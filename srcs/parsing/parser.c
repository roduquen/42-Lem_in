/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 10:49:32 by roduquen          #+#    #+#             */
/*   Updated: 2019/10/09 17:24:07 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"
#include <stdlib.h>
#include <unistd.h>

/*
**	--> translate_char_list_to_array : converts the t_lstch list of chars into
**	a list of strings t_lstst (contained in t_lemin structure)that we will be
**	able to use to pursue parsing
*/

static int	translate_char_list_to_array(t_lstch *list, t_lemin *data, int len)
{
	int			i;
	t_lstch		*tmp;

	i = 0;
	tmp = list;
	if (!(data->file->next = (t_lstst*)malloc(sizeof(t_lstst))))
		return (ERROR);
	data->file->next->line = data->file->line + 1;
	data->file = data->file->next;
	data->file->len = len;
	if (!(data->file->str = (char*)malloc(sizeof(char) * (len + 1))))
		return (ERROR);
	while (list && (data->file->str[i++] = list->c))
		list = list->next;
	data->file->next = NULL;
	return (SUCCESS);
}

/*
**	--> add_char_to_list_before_translation : saves each char from the file
**	into a t_lstch list.
**	This method was used to avoid doing multiple "strjoins".
*/

static int	add_char_to_list_before_translation(t_lstch **actual
	, char c, t_lstch **begin)
{
	if (!(*begin))
	{
		if (!(*begin = (t_lstch*)malloc(sizeof(t_lstch))))
			return (ERROR);
		(*begin)->c = c;
		(*begin)->next = NULL;
		*actual = *begin;
	}
	else
		(*actual)->c = c;
	if (!(*actual)->next)
	{
		if (!((*actual)->next = (t_lstch*)malloc(sizeof(t_lstch))))
			return (ERROR);
		(*actual)->next->next = NULL;
	}
	*actual = (*actual)->next;
	return (SUCCESS);
}

static int	translate_line_and_verify_if_well_formated(t_lstch **actual
	, t_lstch **begin, t_lemin *data, int *count)
{
	if (add_char_to_list_before_translation(actual, 0, begin) == ERROR)
		return (ERROR);
	if (translate_char_list_to_array(*begin, data, *count) == ERROR)
		return (ERROR);
	if (check_if_line_can_probably_be_well_formated(*begin, data, *count)
		== ERROR)
		return (ERROR);
	*actual = *begin;
	*count = 0;
	return (SUCCESS);
}

/*
**	--> read_loop : reads through the file 1 byte at a time to make
**	the reading process more secure. Every byte is added to a list
**	of chars, and there's an extra security check with
**	probably_be_well_formated in case the file is 4096 bites long.
**	It calls if_well_formated once it has read a line or reached
** 	EOF and then checks the whole line and translates it.
*/

static int	read_loop(t_lemin *data, t_lstch **begin, t_lstch **actual
	, int ret[2])
{
	char	buf;

	while ((ret[0] = read(0, &buf, 1)) > 0)
	{
		if (buf == '\n' || !buf)
		{
			if (translate_line_and_verify_if_well_formated(actual, begin
					, data, &ret[1]) == ERROR)
				return (free_char_list(begin, ERROR));
		}
		else
		{
			if (add_char_to_list_before_translation(actual, buf, begin)
				== ERROR)
				return (free_char_list(begin, ERROR));
			if (++(ret[1]) % 4096 == 0)
			{
				if (check_if_line_can_probably_be_well_formated(*begin, data
						, ret[1]) == ERROR)
					return (free_char_list(begin, ERROR));
			}
		}
	}
	return (SUCCESS);
}

/*
**	--> parser : reads through the file, checks that it's correct, and saves it
**	into lists of chars
*/

int			parser(t_lemin *data)
{
	int			ret[2];
	t_lstch		*begin;
	t_lstch		*actual;

	ret[1] = 0;
	begin = NULL;
	actual = NULL;
	if (read_loop(data, &begin, &actual, ret) == ERROR)
		return (ERROR);
	if (!ret[0] && actual != begin)
	{
		if (translate_line_and_verify_if_well_formated(&actual, &begin
					, data, &ret[1]) == ERROR)
			return (free_char_list(&begin, ERROR));
	}
	return (free_char_list(&begin, SUCCESS));
}
