/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breadth_first_search.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 16:26:12 by roduquen          #+#    #+#             */
/*   Updated: 2019/10/04 20:46:40 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"
#include <stdlib.h>

static int	init_queue(t_lemin *data)
{
	t_bfs		*elem;
	int			i;

	if (data->queue[1])
		free_queue(data);
	if (!(elem = create_node_bfs(0, NULL, data->start->id)))
		return (ERROR);
	if (!(data->queue[0] = queue_new(elem)))
	{
		free(elem);
		return (ERROR);
	}
	data->queue[1] = data->queue[0];
	i = 1;
	while (i <= data->nbr_room)
		data->best_way[i++] = 2147483647;
	return (SUCCESS);
}

static int	update_bfs_edmonds_karp(t_lemin *data)
{
	int			k;
	t_queue		*tmp;

	if (!(data->path = (int*)malloc(sizeof(int) * (data->nbr_room + 2))))
		return (ERROR);
	k = 1;
	tmp = data->queue[0];
	while (tmp)
	{
		data->graph[((t_bfs*)tmp->ptr)->id] = 0;
		data->path[k++] = ((t_bfs*)tmp->ptr)->id;
		tmp = ((t_bfs*)tmp->ptr)->parent;
	}
	data->path[0] = k - 1;
	if (save_path_to_exit(data))
		return (ERROR);
	data->graph[data->start->id] = 1;
	data->graph[data->end->id] = 1;
	return (CONTINUE);
}

int			bfs_after_edmunds_karp(t_lemin *data)
{
	int			tmp;
	int			i;

	if (init_queue(data) == ERROR)
		return (ERROR);
	while (data->queue[0])
	{
		tmp = ((t_bfs*)data->queue[0]->ptr)->id;
		if (tmp == data->end->id)
			return (update_bfs_edmonds_karp(data));
		i = 0;
		while (++i <= data->nbr_room)
		{
			if (data->resid[tmp][i] == 1 && data->graph[i])
			{
				if (create_and_add_queue_elem_to_end(data, tmp, i) == ERROR)
					return (ERROR);
			}
		}
		data->queue[0] = data->queue[0]->next;
	}
	return (SUCCESS);
}

int			verify_one(t_lemin *data, int id)
{
	int			i;
	int			tmp;

	i = 1;
	tmp = 0;
	if (data->start->id == id)
		return (0);
	if (data->queue[0]->prev)
		tmp = ((t_bfs*)((t_bfs*)data->queue[0]->ptr)->parent->ptr)->id;
	if (data->resid[tmp][id] == -1)
		return (0);
	while (i <= data->nbr_room)
	{
		if (data->resid[id][i] == 1)
			return (-1);
		i++;
	}
	return (0);
}

int			breadth_first_search(t_lemin *data)
{
	int			tmp;
	int			test;
	t_links		*connected;

	if (init_queue(data) == ERROR)
		return (ERROR);
	while (data->queue[0])
	{
		if ((tmp = ((t_bfs*)data->queue[0]->ptr)->id) == data->end->id)
			return (edmonds_karp(data));
		connected = data->adj_list[tmp];
		test = verify_one(data, tmp);
		while (connected)
		{
			if (data->resid[tmp][connected->id] <= test)
			{
				if (create_and_add_queue_elem_to_end(data, tmp, connected->id)
					== ERROR)
					return (ERROR);
			}
			connected = connected->next;
		}
		data->queue[0] = data->queue[0]->next;
	}
	return (SUCCESS);
}
