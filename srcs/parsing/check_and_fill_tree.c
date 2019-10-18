/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_fill_tree.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:24:38 by roduquen          #+#    #+#             */
/*   Updated: 2019/10/18 10:00:01 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"
#include <stdlib.h>

/*
**	--> check_if_it_is_start_end_or_comment : uses char comparison to check
**	if it is a start or end instruction.
*/

static int	check_if_it_is_start_end_or_comment(t_lstch *begin, t_lemin *data)
{
	char		*start;
	char		*end;
	int			i;

	start = "start";
	end = "end";
	i = 0;
	while (begin && begin->c && begin->c == start[i])
	{
		begin = begin->next;
		i++;
	}
	if (i == 5 && begin->c == 0)
		data->start_end = 1;
	else if (!i)
	{
		while (begin && begin->c && begin->c == end[i])
		{
			begin = begin->next;
			i++;
		}
		if (i == 3 && begin->c == 0)
			data->start_end = 2;
	}
	return (SUCCESS);
}

/*
**	--> find_name_in_list : used for creating links, scrolls the list of
**	rooms to find str, if it does, it saves its id and returns 0
*/

int			find_name_in_list(t_lemin *data, char *str, int *id)
{
	t_lstrom	*tmp;

	tmp = data->rooms;
	if (!tmp)
		return (ERROR);
	while (tmp)
	{
		if (!ft_strcmp(str, tmp->name))
		{
			*id = tmp->id;
			return (SUCCESS);
		}
		tmp = tmp->next;
	}
	return (ERROR);
}

/*
**	--> check_line_and_fill_type : makes sure that the line is either
**	a comment, an instruction or map information.
*/

static int	check_line_and_fill_type(t_lstch *begin, t_lemin *data, int len)
{
	int			ret;
	t_lstst		*tmp;

	if (begin->c == '#')
	{
		if (begin->next && begin->next->c == '#')
			return (check_if_it_is_start_end_or_comment(begin->next->next
					, data));
	}
	else if ((ret = find_type_of_line(begin, data, len)) == ERROR)
	{
		tmp = data->begin_file;
		while (tmp && tmp->next && tmp->next != data->file)
			tmp = tmp->next;
		if (tmp->next)
		{
			free(tmp->next->str);
			free(tmp->next);
			tmp->next = NULL;
		}
		return (ERROR);
	}
	return (SUCCESS);
}

/*
**	--> check_if_line_can_probably_be_well_formated : makes sure that
**	the first character doesn't start with 'L' because 'L' are only for
**	ant instructions. It then checks the line in detail.
*/

int			check_if_line_can_probably_be_well_formated(t_lstch *begin
	, t_lemin *data, int len)
{
	int	type;

	type = 0;
	if (begin->c == 'L')
		return (ERROR);
	if ((type = check_line_and_fill_type(begin, data, len)) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
