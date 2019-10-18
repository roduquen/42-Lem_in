/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:32:45 by julesqvgn         #+#    #+#             */
/*   Updated: 2019/10/09 18:58:05 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leminvizu.h"

int			choose_color(t_lemin *l, t_room *tmp, int i)
{
	if (l->go && ((tmp->full != 0 && tmp->link[i]->full == tmp->full)
		|| ((tmp->start && tmp->link[i]->full != 0) || (tmp->link[i]->start
		&& tmp->full != 0)) || ((tmp->end && tmp->link[i]->full != 0)
		|| (tmp->link[i]->end && tmp->full != 0))))
	{
		SDL_SetRenderDrawColor(l->sdl.renderer, 69, 243, 255, 255);
	}
	else
		SDL_SetRenderDrawColor(l->sdl.renderer, 100, 100, 100, 255);
	return (0);
}

int			key_event(t_lemin *l, SDL_Event event)
{
	if (event.key.keysym.sym == SDLK_a)
		l->mv_x = l->mv_x - 10;
	else if (event.key.keysym.sym == SDLK_d)
		l->mv_x = l->mv_x + 10;
	else if (event.key.keysym.sym == SDLK_w)
		l->mv_y = l->mv_y - 10;
	else if (event.key.keysym.sym == SDLK_s)
		l->mv_y = l->mv_y + 10;
	else if (event.key.keysym.sym == SDLK_UP && l->zoom > 0)
		l->zoom = l->zoom - 1;
	else if (event.key.keysym.sym == SDLK_DOWN)
		l->zoom = l->zoom + 1;
	else if (event.key.keysym.sym == SDLK_p)
	{
		l->go = 1;
		if (!parse_path(l))
			return (1);
	}
	lem_visu(l);
	return (0);
}

int			get_link(t_lemin *l)
{
	char	*line;
	int		ret;
	int		tmp;

	tmp = 0;
	while ((ret = get_next_line(0, &line)))
	{
		if (ret == -1)
			return (ft_parse_error("ERROR during reading file"));
		if (!line[0])
		{
			free(line);
			break ;
		}
		if (line[0] == '#')
		{
			if (!ft_comment(l, &tmp, &line))
				return (ft_free("ERROR: double start/end", &line, 1));
		}
		else if (!add_link(line, 0, l->room))
			return (ft_free("ERROR: add link fail", &line, 1));
		free(line);
	}
	return (1);
}
