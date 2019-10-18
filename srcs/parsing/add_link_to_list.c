/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_link_to_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 18:16:20 by roduquen          #+#    #+#             */
/*   Updated: 2019/10/05 17:00:27 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"
#include <stdlib.h>

static int	check_if_link_already_exists(char *str, int mid, char *s1, char *s2)
{
	int		i;

	i = 0;
	if (!ft_strcmp(str, s1))
	{
		if (!ft_strcmp(str + mid, s2))
			return (ERROR);
	}
	if (!ft_strcmp(str, s2))
	{
		if (!ft_strcmp(str + mid, s1))
			return (1);
	}
	return (SUCCESS);
}

static void	init_link_elem(t_lstlin *elem, char **str, int mid)
{
	elem->next = NULL;
	elem->name1 = *str;
	elem->name2 = *str + mid;
}

/*
**	--> scan_links : scans the list of links to make sure the links doesn't
**	already exist, and then saves the link.
*/

int			scan_links(t_lemin *data, char **str, int mid, int ids[2])
{
	t_lstlin		*tmp;

	tmp = data->links;
	while (tmp)
	{
		if (check_if_link_already_exists(*str, mid, tmp->name1, tmp->name2))
			return (ERROR);
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}
	if (!(tmp->next = (t_lstlin*)malloc(sizeof(t_lstlin))))
		return (ERROR);
	tmp = tmp->next;
	init_link_elem(tmp, str, mid);
	tmp->id1 = ids[0];
	tmp->id2 = ids[1];
	return (SUCCESS);
}

/*
**	--> add_elem_to_link : saves links between rooms by giving the id of
**	the linked rooms to each other if the link doesn't already exist..
*/

static int	add_elem_to_link(t_lemin *data, char **str, int mid, int ids[2])
{
	if (!data->links)
	{
		if (!(data->links = (t_lstlin*)malloc(sizeof(t_lstlin))))
			return (ERROR);
		init_link_elem(data->links, str, mid);
		data->links->id1 = ids[0];
		data->links->id2 = ids[1];
		return (SUCCESS);
	}
	return (scan_links(data, str, mid, ids));
}

/*
**	--> add_link_if_well_formated : if we were still on the "room names"
**	step, it indicates that we have moved to the "links". It finds the
**	rooms names, and gives them an id according to their order of appearance
**	it then creates a link between the rooms using their newly created ids.
*/

int			add_link_if_well_formated(t_lemin *data, char **str)
{
	int			i;
	int			ids[2];

	i = 0;
	if (data->actual_step == 1)
		data->actual_step = 2;
	while (str[0][i] && str[0][i] != '-')
		i++;
	if (str[0][i])
		str[0][i++] = 0;
	else
		return (free_return((void**)str, ERROR));
	if (find_name_in_list(data, str[0], &ids[0]))
		return (free_return((void**)str, ERROR));
	if (find_name_in_list(data, str[0] + i, &ids[1]))
		return (free_return((void**)str, ERROR));
	if (add_elem_to_link(data, str, i, ids))
		return (free_return((void**)str, ERROR));
	return (SUCCESS);
}
