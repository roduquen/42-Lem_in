/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:17:44 by julesqvgn         #+#    #+#             */
/*   Updated: 2019/10/09 13:41:53 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leminvizu.h"

void	get_path(t_lemin *l, char *line, int i, int new_room)
{
	int		j;
	char	*room;
	t_room	*tmp;

	while (line[i])
	{
		if (line[i] == 'L')
			new_room++;
		while (line[i] && line[i] != '-')
			i++;
		i++;
		j = 0;
		while (line[i + j] && line[i + j] != ' ')
			j++;
		room = ft_strndup(line + i, j);
		tmp = l->room;
		while (tmp)
		{
			if (!ft_strcmp(room, tmp->name))
				tmp->full = tmp->full != 0 ? tmp->full : new_room;
			tmp = tmp->next;
		}
		i = j + i + 1;
		free(room);
	}
}

int		parse_path(t_lemin *l)
{
	int		ret;
	char	*line;
	int		i;
	int		new_room;

	while ((ret = get_next_line(0, &line)))
	{
		i = 0;
		new_room = 0;
		if (ret == -1)
			return (ft_parse_error("ERROR during reading file"));
		get_path(l, line, i, new_room);
		free(line);
	}
	return (1);
}

int		ft_rea_link(t_room *room, t_room *link)
{
	int		i;
	int		j;
	t_room	**tmp;

	i = 0;
	if (room->link == NULL)
	{
		if (!(room->link = (t_room **)malloc(sizeof(t_room *) * 2)))
			return (0);
	}
	else
	{
		while (room->link[i] != NULL)
			i++;
		if (!(tmp = (t_room **)malloc(sizeof(t_room *) * (i + 2))))
			return (0);
		j = -1;
		while (++j < i)
			tmp[j] = room->link[j];
		free(room->link);
		room->link = tmp;
	}
	room->link[i] = link;
	room->link[i + 1] = NULL;
	return (1);
}

int		add_link(char *l, int i, t_room *room)
{
	t_room	*ptr;
	char	*tmp;

	ptr = room;
	while (l[i] && l[i] != '-')
		i++;
	if (i == (int)ft_strlen(l))
		return (0);
	tmp = ft_strndup(l, i);
	while (ptr && ft_strcmp(tmp, ptr->name))
		ptr = ptr->next;
	if (ptr == NULL)
		add_link(l, i + 1, room);
	else if (!ft_strcmp(tmp, ptr->name))
	{
		free(tmp);
		tmp = ft_strdup(l + i + 1);
		while (room && ft_strcmp(tmp, room->name))
			room = room->next;
		if (room == NULL)
			return (ft_free("", &tmp, 0));
		if (!ft_strcmp(tmp, room->name) && !ft_rea_link(ptr, room))
			return (ft_free("", &tmp, 0));
	}
	return (ft_free("", &tmp, 2));
}

int		ft_comment(t_lemin *l, int *pos, char **line)
{
	(void)l;
	if (!(*line)[1] || (*line)[1] != '#')
		return (1);
	if ((!ft_strcmp(*line, "##start") && *pos == 2)
		|| (!ft_strcmp(*line, "##end") && *pos == 1))
		return (0);
	if (!ft_strcmp(*line, "##start"))
		*pos = 1;
	else if (!ft_strcmp(*line, "##end"))
		*pos = 2;
	return (1);
}
