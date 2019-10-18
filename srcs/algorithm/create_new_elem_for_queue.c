/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_new_elem_for_queue.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 13:26:41 by roduquen          #+#    #+#             */
/*   Updated: 2019/10/04 20:50:33 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"
#include <stdlib.h>

int			find_step_of_actual_node(t_lemin *data, int id)
{
	int			result;
	int			i;

	result = 0;
	while (id != data->start->id)
	{
		i = 1;
		while (data->resid[id][i] != -1)
			i++;
		id = i;
		result++;
	}
	return (result);
}

t_bfs		*create_node_bfs(int step, t_queue *parent, int id)
{
	t_bfs		*new;
	static int	test = 0;

	new = (t_bfs*)malloc(sizeof(t_bfs));
	test++;
	if (!new)
		return (NULL);
	new->step = step;
	new->id = id;
	new->parent = parent;
	return (new);
}

static void	add_node_bfs(t_lemin *data, t_queue *node, int step, int type)
{
	t_queue		*tmp;

	tmp = data->queue[0];
	while (tmp->next && ((t_bfs*)tmp->next->ptr)->step < step + type)
		tmp = tmp->next;
	node->prev = tmp;
	node->next = tmp->next;
	node->prev->next = node;
	if (node->next)
		node->next->prev = node;
	else
		data->queue[1] = node;
}

int			already_visited(int *step, int id, t_queue *queue)
{
	while (((t_bfs*)queue->ptr)->parent)
	{
		if (((t_bfs*)((t_bfs*)queue->ptr)->parent->ptr)->id == id)
		{
			*step = ((t_bfs*)((t_bfs*)queue->ptr)->parent->ptr)->step;
			return (42);
		}
		queue = ((t_bfs*)queue->ptr)->parent;
	}
	return (0);
}

int			create_and_add_queue_elem_to_end(t_lemin *data, int parent, int id)
{
	t_bfs		*new;
	t_queue		*node;
	int			step;
	int			visited;

	visited = 0;
	if (id == data->start->id)
		return (CONTINUE);
	step = ((t_bfs*)data->queue[0]->ptr)->step + 1;
	if (data->resid[parent][id] == -1)
		step = find_step_of_actual_node(data, id);
	visited = already_visited(&step, id, data->queue[0]);
	if (visited && data->resid[parent][id] == 0)
		return (CONTINUE);
	if (step >= data->best_way[id] + visited)
		return (CONTINUE);
	if (!(new = create_node_bfs(step, data->queue[0], id)))
		return (ERROR);
	if (!(node = queue_new(new)))
		return (free_return((void**)&new, ERROR));
	data->best_way[id] = step;
	node->ptr = new;
	add_node_bfs(data, node, step, data->resid[parent][id] != -1);
	return (SUCCESS);
}
