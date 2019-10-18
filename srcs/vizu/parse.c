/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 17:30:09 by julesqvgn         #+#    #+#             */
/*   Updated: 2019/10/09 19:00:57 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leminvizu.h"

int		loop_gnl(t_lemin *l, char **line, int *pos, int *ret)
{
	t_room	*room;

	room = NULL;
	while ((*ret = get_next_line(0, line)))
	{
		if (*ret == -1)
			return (ft_parse_error("ERROR during reading file"));
		if (*line[0] == 'L')
			return (ft_free("ERROR: bad room name", line, 1));
		else if (*line[0] == '#')
		{
			if (!ft_comment(l, pos, line))
				return (ft_free("ERROR: double start/end", line, 1));
		}
		else if (!is_room(*line))
			break ;
		else if (!ft_room_list(&room, l, pos, *line))
			return (ft_free("ERROR: bad room definition", line, 1));
		free(*line);
	}
	l->room = room;
	return (1);
}

int		get_room(t_lemin *l)
{
	char	*line;
	int		pos;
	int		ret;

	pos = 0;
	ret = 0;
	if (!loop_gnl(l, &line, &pos, &ret))
		return (0);
	if (!add_link(line, 0, l->room))
		return (ft_free("ERROR: bad link definition", &line, 1));
	return (ret == 0 ? 1 : ft_free("", &line, 2));
}

int		ft_parse(t_lemin *l)
{
	if (!get_ants(l))
		return (0);
	if (!get_room(l))
		return (0);
	if (!get_link(l))
		return (0);
	return (1);
}

void	init(t_lemin *l)
{
	l->ants = 0;
	l->room = NULL;
	l->n_room = 0;
	l->start = 0;
	l->end = 0;
	l->mv_x = MIDDLE_W / 2;
	l->mv_y = MIDDLE_H / 2;
	l->zoom = 1400;
	l->sx_room = 50;
	l->sy_room = 50;
	l->x_min = 0;
	l->x_max = 0;
	l->y_min = 0;
	l->y_max = 0;
}

int		main(void)
{
	t_lemin	l;

	init(&l);
	if (!ft_parse(&l))
	{
		ft_room_clear(&l);
		return (0);
	}
	if (visual(&l))
		return (0);
	ft_room_clear(&l);
	return (0);
}
