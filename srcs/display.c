/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julesqvgn <julesqvgn@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 14:11:39 by roduquen          #+#    #+#             */
/*   Updated: 2019/10/09 18:34:18 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

static t_disp	*create_disp_ptr(int lem, int pos, int *path)
{
	t_disp	*new;

	if (!(new = (t_disp*)malloc(sizeof(t_disp))))
		return (NULL);
	new->lem = lem;
	new->pos = pos;
	new->path = path;
	return (new);
}

static int		add_ant_and_room_to_queue(t_lstpat *tmp, int *lem
	, t_lemin *data)
{
	t_queue		*new;
	t_disp		*ptr;

	if (!(ptr = create_disp_ptr(*lem, tmp->path[0] - 1, tmp->path)))
		return (ERROR);
	(*lem)++;
	if (!(new = queue_new(ptr)))
	{
		free(ptr);
		return (ERROR);
	}
	new->next = NULL;
	if (data->queue[1])
	{
		new->prev = data->queue[1];
		new->prev->next = new;
		data->queue[1] = new;
	}
	else
	{
		data->queue[0] = new;
		new->prev = NULL;
		data->queue[1] = new;
	}
	return (SUCCESS);
}

static int		fill_queue(t_lemin *data, int res)
{
	t_lstpat	*tmp;
	static int	lem = 1;
	int			i;

	tmp = data->exit_paths[data->best.id];
	i = 0;
	while (++i <= data->best.nbr_paths)
	{
		if (lem <= data->nbr_lem && i <= data->best.surplus)
		{
			data->best.surplus--;
			if (add_ant_and_room_to_queue(tmp, &lem, data) == ERROR)
				return (ERROR);
		}
		else if (tmp->path[0] <= res && lem <= data->nbr_lem)
		{
			if (!(tmp->path[0] == res && tmp->path[0] - 1 == data->best.size))
			{
				if (add_ant_and_room_to_queue(tmp, &lem, data) == ERROR)
					return (ERROR);
			}
		}
		tmp = tmp->next;
	}
	return (SUCCESS);
}

static int		print_ants(t_lemin *data, int result)
{
	t_queue		*wait;
	t_queue		*new;
	t_disp		*elem;

	(void)result;
	wait = data->queue[1];
	while (data->queue[0] && wait != data->queue[0]->prev)
	{
		if (((t_disp*)data->queue[0]->ptr)->pos > 1)
		{
			elem = create_disp_ptr(((t_disp*)data->queue[0]->ptr)->lem
					, ((t_disp*)data->queue[0]->ptr)->pos - 1
					, ((t_disp*)data->queue[0]->ptr)->path);
			if (!elem)
				return (ERROR);
			if (!(new = queue_new(elem)))
				return (ERROR);
			queue_add(&data->queue[1], new);
		}
		print_lem(data, result, wait);
	}
	return (SUCCESS);
}

int				display(t_lemin *data)
{
	int		result;

	free_queue(data);
	if (data->best.cost == 2147483647)
		return (ERROR);
	result = data->best.cost;
	print_begin_file(data);
	while (result)
	{
		if (fill_queue(data, result + 1) == ERROR)
			return (ERROR);
		if (print_ants(data, result) == ERROR)
			return (ERROR);
		if (data->queue[0])
			write(1, "\n", 1);
		result--;
	}
	write(1, "\n", 1);
	free_queue(data);
	return (SUCCESS);
}
