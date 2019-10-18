/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 15:33:00 by julesqvgn         #+#    #+#             */
/*   Updated: 2019/10/09 19:16:25 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leminvizu.h"

int		take_coor(char *line, int *x, int *y)
{
	char	*test;

	while (*line && *line != ' ')
		line++;
	line++;
	if (!line)
		return (0);
	*x = ft_strtol(line, &test, 10);
	if (!test || *test != ' ')
		return (0);
	*y = ft_strtol(test, &test, 10);
	if (!test || test[0])
		return (0);
	return (1);
}

int		take_name(char **name, char *line, t_lemin *l)
{
	t_room	*tmp;
	int		i;

	i = 0;
	tmp = l->room;
	while (line[i] && line[i] != ' ')
		i++;
	if (!line[i])
		return (0);
	line[i] = '\0';
	*name = ft_strdup(line);
	return (1);
}

t_room	*ft_init_room(t_room *elem, int *pos, char *line, t_lemin *l)
{
	t_room	*tmp;

	if (!take_coor(line, &elem->x, &elem->y))
		return (NULL);
	if (elem->x > l->x_max)
		l->x_max = elem->x;
	else if (elem->x < l->x_min)
		l->x_min = elem->x;
	if (elem->y > l->y_max)
		l->y_max = elem->y;
	else if (elem->y < l->y_min)
		l->y_min = elem->y;
	tmp = l->room;
	while (tmp)
	{
		if (tmp->x == elem->x && tmp->y == elem->y)
			return (NULL);
		tmp = tmp->next;
	}
	elem->full = 0;
	elem->start = *pos == 1 ? 1 : 0;
	elem->end = *pos == 2 ? 1 : 0;
	elem->link = NULL;
	*pos = 0;
	return (elem);
}

t_room	*ft_create_obj(int *pos, t_lemin *l, char *line, char *name)
{
	t_room		*element;

	if ((*pos == 1 && l->start == 1) || (*pos == 2 && l->end == 1))
		return (NULL);
	*pos == 1 ? l->start = 1 : 0;
	*pos == 2 ? l->end = 1 : 0;
	if (!(element = (t_room *)malloc(sizeof(t_room))))
		return (NULL);
	if (!(element = ft_init_room(element, pos, line, l)))
		return (NULL);
	if (!(element->name = ft_strdup((const char *)name)))
		return (NULL);
	element->next = NULL;
	l->n_room += 1;
	return (element);
}

int		ft_room_list(t_room **begin_list, t_lemin *l, int *pos, char *line)
{
	t_room	*list;
	char	*name;

	list = *begin_list;
	l->room = *begin_list;
	if (!take_name(&name, line, l))
		return (0);
	if (list == NULL)
	{
		if (!(*begin_list = ft_create_obj(pos, l, line, name)))
			return (ft_free("", &name, 0));
	}
	else
	{
		while (list->next != NULL)
		{
			if (!ft_strcmp(name, list->name))
				return (ft_free("", &name, 0));
			list = list->next;
		}
		if (!(list->next = ft_create_obj(pos, l, line, name)))
			return (ft_free("", &name, 0));
	}
	free(name);
	return (1);
}
