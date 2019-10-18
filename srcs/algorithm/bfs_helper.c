/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 15:12:19 by roduquen          #+#    #+#             */
/*   Updated: 2019/10/04 20:45:06 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"
#include <stdlib.h>

void	free_queue(t_lemin *data)
{
	while (data->queue[1])
	{
		data->queue[0] = data->queue[1]->prev;
		free(data->queue[1]->ptr);
		free(data->queue[1]);
		data->queue[1] = data->queue[0];
	}
}

int		save_path_to_exit(t_lemin *data)
{
	t_lstpat		*tmp;

	tmp = data->exit_paths[data->max_flow];
	if (!tmp)
	{
		if (!(data->exit_paths[data->max_flow] = malloc(sizeof(t_lstpat))))
			return (free_return((void**)&data->path, ERROR));
		data->exit_paths[data->max_flow]->path = data->path;
		data->exit_paths[data->max_flow]->next = NULL;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		if (!(tmp->next = (t_lstpat*)malloc(sizeof(t_lstpat))))
			return (free_return((void**)&data->path, ERROR));
		tmp->next->path = data->path;
		tmp->next->next = NULL;
	}
	return (SUCCESS);
}
