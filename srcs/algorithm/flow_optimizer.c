/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow_optimizer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 14:12:25 by roduquen          #+#    #+#             */
/*   Updated: 2019/10/05 18:35:19 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"
#include "libft.h"

static int	length_of_paths(t_lstpat *list, int *nbr_path, int *max)
{
	int		result;

	result = 0;
	*max = 0;
	*nbr_path = 0;
	while (list)
	{
		result += list->path[0] - 1;
		if (list->path[0] - 1 > *max)
			*max = list->path[0] - 1;
		list = list->next;
		(*nbr_path)++;
	}
	return (result);
}

static int	chose_best_path(t_lemin *data)
{
	int			length;
	int			i;
	int			max;
	int			nbr_path;
	int			result;

	length = length_of_paths(data->exit_paths[data->max_flow], &nbr_path, &max);
	i = max * nbr_path - length;
	if (i >= data->nbr_lem)
		return (ERROR);
	i = data->nbr_lem - i;
	result = i / nbr_path;
	result += max - 1;
	if (i % nbr_path)
		result++;
	if (data->best.cost > result)
	{
		data->best.cost = result;
		data->best.nbr_paths = nbr_path;
		data->best.id = data->max_flow;
		data->best.surplus = i % nbr_path;
		data->best.size = max - 1;
		data->best.len = length;
	}
	return (CONTINUE);
}

static int	display_reverse(t_lemin *reverse, t_lemin *data)
{
	t_lstpat	*tmp;
	int			i[2];

	if (reverse->best.cost >= data->best.cost && (reverse->start = data->start))
	{
		free_exit_paths(reverse);
		free_queue(reverse);
		return (display(data));
	}
	reverse->end = data->end;
	tmp = reverse->exit_paths[reverse->best.id];
	while (tmp && (i[0] = 1))
	{
		i[1] = tmp->path[0];
		while (i[0] < i[1])
		{
			tmp->path[i[0]] ^= tmp->path[i[1]];
			tmp->path[i[1]] ^= tmp->path[i[0]];
			tmp->path[i[0]++] ^= tmp->path[i[1]--];
		}
		tmp = tmp->next;
	}
	i[0] = display(reverse);
	free_exit_paths(reverse);
	return (i[0]);
}

static int	init_reverse(t_lemin *reverse, t_lemin *data)
{
	ft_memcpy(reverse, data, sizeof(t_lemin));
	reverse->start = data->end;
	reverse->end = data->start;
	reverse->exit_paths = (t_lstpat**)malloc(sizeof(t_lstpat*)
			* (data->max_flow + 3));
	if (!reverse->exit_paths)
		return (ERROR);
	data->exit_paths = (t_lstpat**)malloc(sizeof(t_lstpat*)
					* (data->max_flow + 3));
	if (!data->exit_paths)
		return (free_return((void**)&reverse->exit_paths, ERROR));
	data->max_flow += 2;
	while (data->max_flow >= 0)
	{
		reverse->exit_paths[data->max_flow] = NULL;
		data->exit_paths[data->max_flow--] = NULL;
	}
	data->max_flow = 0;
	reverse->max_flow = 0;
	return (SUCCESS);
}

int			flow_optimizer(t_lemin *data)
{
	int			ret;
	t_lemin		reverse;
	static int	i = 0;

	if (init_reverse(&reverse, data) == ERROR)
		return (ERROR);
	while ((ret = breadth_first_search(data)) == CONTINUE)
	{
		if (chose_best_path(data) == ERROR)
			break ;
		data->max_flow++;
	}
	if (ret == ERROR)
		return (ERROR);
	while (i <= data->nbr_room)
		ft_memset(reverse.resid[i++], 0, data->nbr_room + 1);
	while ((ret = breadth_first_search(&reverse)) == CONTINUE)
	{
		if (chose_best_path(&reverse) == ERROR)
			break ;
		reverse.max_flow++;
	}
	if (ret == ERROR)
		return (ERROR);
	return (display_reverse(&reverse, data));
}
