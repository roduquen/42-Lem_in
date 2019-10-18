/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_list_to_string.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 16:24:41 by roduquen          #+#    #+#             */
/*   Updated: 2019/10/09 17:25:09 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"
#include <stdlib.h>

static int	skip_white_spaces(int *i, t_lstch **list, int *space_nbr
	, char **str)
{
	str[0][*i - 1] = ' ';
	(*space_nbr)++;
	while ((*list) && ft_iswhitespace((*list)->c))
		(*list) = (*list)->next;
	if (*space_nbr > 2 && ((*list) && (*list)->c != 0))
		return (ERROR);
	if (!(*list))
	{
		(*i)--;
		(*space_nbr)--;
	}
	return (SUCCESS);
}

/*
**	--> translate_list_to_string : skips all whitespaces saves in the char
**	list, then copies each char into the new str string and returns the number
**	of spaces which indicates later what type of data we are dealing with
*/

int			translate_list_to_string(t_lstch *list, char **str, int len)
{
	int			i;
	int			space_nbr;

	i = 0;
	space_nbr = 0;
	if (!(*str = (char*)malloc(sizeof(char) * (len + 1))))
		return (ERROR);
	while (list && ft_iswhitespace(list->c))
		list = list->next;
	while (list && list->c)
	{
		str[0][i++] = list->c;
		if (ft_iswhitespace(list->c))
		{
			if (skip_white_spaces(&i, &list, &space_nbr, str) == ERROR)
				return (ERROR);
		}
		else
			list = list->next;
	}
	str[0][i] = 0;
	return (space_nbr);
}
