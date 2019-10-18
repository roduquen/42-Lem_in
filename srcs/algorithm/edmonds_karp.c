/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 13:59:01 by roduquen          #+#    #+#             */
/*   Updated: 2019/10/04 20:30:22 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	update_graph_edmonds_karp(t_lemin *data)
{
	t_queue		*tmp;
	int			parent;
	int			child;

	tmp = data->queue[0];
	while (((t_bfs*)tmp->ptr)->parent)
	{
		parent = ((t_bfs*)((t_bfs*)tmp->ptr)->parent->ptr)->id;
		child = ((t_bfs*)tmp->ptr)->id;
		data->resid[parent][child]++;
		data->resid[child][parent]--;
		tmp = ((t_bfs*)tmp->ptr)->parent;
	}
}

int			edmonds_karp(t_lemin *data)
{
	int		ret;
	int		i;

	i = 0;
	while (i <= data->nbr_room)
		data->graph[i++] = 1;
	update_graph_edmonds_karp(data);
	while (1)
	{
		if ((ret = bfs_after_edmunds_karp(data)) == ERROR)
			return (ERROR);
		if (ret == SUCCESS)
			return (CONTINUE);
	}
	return (SUCCESS);
}
