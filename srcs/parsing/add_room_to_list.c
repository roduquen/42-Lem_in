/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_room_to_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 18:14:17 by roduquen          #+#    #+#             */
/*   Updated: 2019/10/09 17:24:36 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdlib.h>

static int	str_compare_space(char *s1, char *s2)
{
	int			i;

	i = 0;
	while (s1[i] && s2[i] && s2[i] != ' ' && s1[i] == s2[i])
		i++;
	if (!s1[i] && s2[i] == ' ')
		return (ERROR);
	return (SUCCESS);
}

static int	add_first_rom_to_list(t_lemin *data, char *str, int len)
{
	int			i;

	i = 0;
	if (!(data->rooms = (t_lstrom*)malloc(sizeof(t_lstrom))))
		return (ERROR);
	if (!(data->rooms->name = (char*)malloc(sizeof(char) * (len + 1))))
		return (ERROR);
	while (str[i] != ' ')
	{
		data->rooms->name[i] = str[i];
		i++;
	}
	data->rooms->name[i] = 0;
	data->rooms->next = NULL;
	if (data->start_end == 1)
		data->start = data->rooms;
	else if (data->start_end == 2)
		data->end = data->rooms;
	data->start_end = 0;
	data->rooms->id = ++data->nbr_room;
	return (SUCCESS);
}

static int	check_if_last_room_is_not_the_same_and_add_it_to_list_if_possible(
	t_lemin *data, t_lstrom *tmp, char *str, int len)
{
	int		i;

	i = -1;
	if (str_compare_space(tmp->name, str)
		|| !(tmp->next = (t_lstrom*)malloc(sizeof(t_lstrom)))
		|| !(tmp->next->name = (char*)malloc(sizeof(char) * (len + 1))))
		return (ERROR);
	tmp->next->next = NULL;
	while (str[++i] != ' ')
		tmp->next->name[i] = str[i];
	tmp->next->name[i] = 0;
	if (data->start_end == 1)
		data->start = tmp->next;
	else if (data->start_end == 2)
		data->end = tmp->next;
	data->start_end = 0;
	tmp->next->id = ++data->nbr_room;
	return (SUCCESS);
}

/*
**	--> add_rom_to_list : creates the room list and adds both rooms to it after
**	it checks it.
*/

int			add_rom_to_list(t_lemin *data, char *str)
{
	int			len;
	t_lstrom	*tmp;

	len = 0;
	while (str[len] != ' ')
		len++;
	tmp = data->rooms;
	if (!tmp)
		return (add_first_rom_to_list(data, str, len));
	while (tmp->next)
	{
		if (str_compare_space(tmp->name, str))
			return (ERROR);
		tmp = tmp->next;
	}
	return (check_if_last_room_is_not_the_same_and_add_it_to_list_if_possible(
			data, tmp, str, len));
}
