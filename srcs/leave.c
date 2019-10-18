/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leave.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 15:20:17 by roduquen          #+#    #+#             */
/*   Updated: 2019/10/05 18:36:31 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"
#include "libft.h"
#include <stdio.h>

void		free_exit_paths(t_lemin *data)
{
	int			i;
	t_lstpat	*tmp;

	i = 0;
	while (data->exit_paths && data->exit_paths[i])
	{
		while (data->exit_paths[i])
		{
			tmp = data->exit_paths[i]->next;
			free(data->exit_paths[i]->path);
			free(data->exit_paths[i]);
			data->exit_paths[i] = (t_lstpat*)tmp;
		}
		i++;
	}
	free(data->exit_paths);
	data->exit_paths = NULL;
}

int			free_data_after_printing(t_lemin *data, int type)
{
	void	*tmp;
	int		i;

	i = 0;
	while (data->exit_paths && data->exit_paths[i])
	{
		while (data->exit_paths[i])
		{
			tmp = data->exit_paths[i]->next;
			free(data->exit_paths[i]->path);
			free(data->exit_paths[i]);
			data->exit_paths[i] = (t_lstpat*)tmp;
		}
		i++;
	}
	free(data->exit_paths);
	data->exit_paths = NULL;
	while (data->file)
	{
		tmp = data->file->next;
		free(data->file->str);
		free(data->file);
		data->file = (t_lstst*)tmp;
	}
	return (type);
}

static void	free_graph_and_resid_and_adj_list(t_lemin *data)
{
	int		i;
	void	*tmp;

	i = 0;
	if (data->resid)
	{
		while (i <= data->nbr_room)
			free(data->resid[i++]);
	}
	free(data->graph);
	free(data->resid);
	data->resid = NULL;
	data->graph = NULL;
	i = 0;
	while (data->adj_list && i <= data->nbr_room)
	{
		while (data->adj_list[i])
		{
			tmp = data->adj_list[i]->next;
			free(data->adj_list[i]);
			data->adj_list[i] = tmp;
		}
		i++;
	}
}

int			free_data_after_parsing(t_lemin *data, int type)
{
	void		*tmp;

	while (data->rooms)
	{
		tmp = data->rooms->next;
		free(data->rooms->name);
		free(data->rooms);
		data->rooms = (t_lstrom*)tmp;
	}
	while (data->links)
	{
		tmp = data->links->next;
		free(data->links->name1);
		free(data->links);
		data->links = (t_lstlin*)tmp;
	}
	free(data->room_tab);
	free_graph_and_resid_and_adj_list(data);
	free(data->best_way);
	free(data->adj_list);
	return (type);
}

int			free_char_list(t_lstch **list, int type)
{
	t_lstch *tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free(*list);
		*list = tmp;
	}
	return (type);
}
