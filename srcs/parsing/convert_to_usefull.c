/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_usefull.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 20:29:59 by roduquen          #+#    #+#             */
/*   Updated: 2019/10/09 17:25:00 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"
#include <stdlib.h>

int			allocate_and_init_graphs(t_lemin *data)
{
	int		i;

	i = 0;
	if (!(data->graph = (char*)malloc(sizeof(char) * (data->nbr_room + 1))))
		return (ERROR);
	if (!(data->resid = (char**)malloc(sizeof(char*) * (data->nbr_room + 1))))
		return (ERROR);
	if (!(data->best_way = (int*)malloc(sizeof(int) * (data->nbr_room + 1))))
		return (ERROR);
	if (!(data->adj_list = malloc(sizeof(t_links*) * (data->nbr_room + 1))))
		return (ERROR);
	while (i <= data->nbr_room)
	{
		if (!(data->resid[i] = (char*)malloc(sizeof(char)
					* (data->nbr_room + 1))))
			return (ERROR);
		ft_memset(data->resid[i], 0, data->nbr_room + 1);
		data->adj_list[i] = NULL;
		data->graph[i] = 1;
		i++;
	}
	return (SUCCESS);
}

int			create_elem_for_links(t_lemin *data, int id1, int id2)
{
	t_links		*elem;
	t_links		*tmp;

	if (!(elem = (t_links*)malloc(sizeof(t_links))))
		return (ERROR);
	elem->id = id2;
	elem->next = NULL;
	if (data->adj_list[id1])
	{
		tmp = data->adj_list[id1];
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = elem;
	}
	else
		data->adj_list[id1] = elem;
	return (SUCCESS);
}

int			convert_parsing_to_usefull(t_lemin *data)
{
	t_lstlin	*tmp;

	if (allocate_and_init_graphs(data) == ERROR)
		return (ERROR);
	tmp = data->links;
	while (tmp)
	{
		if (create_elem_for_links(data, tmp->id1, tmp->id2) == ERROR)
			return (ERROR);
		if (create_elem_for_links(data, tmp->id2, tmp->id1) == ERROR)
			return (ERROR);
		if ((tmp->id1 == data->start->id || tmp->id2 == data->start->id)
			&& (tmp->id1 == data->end->id || tmp->id2 == data->end->id))
			return (42);
		if (tmp->id1 == data->start->id)
			data->max_flow++;
		tmp = tmp->next;
	}
	data->best.cost = 2147483647;
	return (flow_optimizer(data));
}
