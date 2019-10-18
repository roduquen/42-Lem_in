/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 15:20:47 by julesqvgn         #+#    #+#             */
/*   Updated: 2019/10/09 19:17:23 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leminvizu.h"

int			draw_room(t_lemin *l)
{
	t_room		*tmp;
	SDL_Rect	rect;

	tmp = l->room;
	l->sx_room = WIDTH / (l->x_max - l->x_min + 5);
	l->sy_room = HEIGHT / (l->y_max - l->y_min + 5);
	while (tmp)
	{
		if (tmp->start)
			SDL_SetRenderDrawColor(l->sdl.renderer, 0, 150, 0, 255);
		else if (tmp->end)
			SDL_SetRenderDrawColor(l->sdl.renderer, 150, 0, 0, 255);
		else if (tmp->full != 0)
			SDL_SetRenderDrawColor(l->sdl.renderer, 25 * tmp->full % 255,
			50 * tmp->full % 255, 150 / tmp->full, 255);
		else
			SDL_SetRenderDrawColor(l->sdl.renderer, 150, 150, 150, 255);
		rect = (SDL_Rect){tmp->x * (l->zoom / 20) + l->mv_x - l->sx_room / 2,
		tmp->y * (l->zoom / 20) + l->mv_y - l->sy_room / 2
		, l->sx_room, l->sy_room};
		SDL_RenderFillRect(l->sdl.renderer, &rect);
		tmp = tmp->next;
	}
	return (0);
}

int			lem_visu(t_lemin *l)
{
	t_room		*tmp;
	int			i;

	SDL_SetRenderDrawColor(l->sdl.renderer, 0, 0, 0, 255);
	SDL_RenderClear(l->sdl.renderer);
	tmp = l->room;
	while (tmp)
	{
		i = -1;
		while (tmp->link && tmp->link[++i])
		{
			choose_color(l, tmp, i);
			SDL_RenderDrawLine(l->sdl.renderer, tmp->x * (l->zoom / 20)
			+ l->mv_x, tmp->y * (l->zoom / 20) + l->mv_y
			, tmp->link[i]->x * (l->zoom / 20) + l->mv_x, tmp->link[i]->y
			* (l->zoom / 20) + l->mv_y);
		}
		tmp = tmp->next;
	}
	draw_room(l);
	SDL_RenderPresent(l->sdl.renderer);
	return (1);
}

int			init_sdl(t_lemin *l)
{
	l->go = 0;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s"
				, SDL_GetError());
		return (1);
	}
	if (!(l->sdl.window = SDL_CreateWindow("Lem-in"
					, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED
					, WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE)))
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window: %s"
				, SDL_GetError());
		return (1);
	}
	if (!(l->sdl.renderer = SDL_CreateRenderer(l->sdl.window, -1
					, 0)))
	{
		SDL_DestroyWindow(l->sdl.window);
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION
				, "Couldn't create renderer: %s", SDL_GetError());
		return (1);
	}
	return (0);
}

int			visual(t_lemin *l)
{
	SDL_Event		event;

	if (init_sdl(l))
		return (1);
	lem_visu(l);
	while (1)
	{
		SDL_PollEvent(&event);
		if (event.window.event == SDL_WINDOWEVENT_CLOSE)
			break ;
		else if (event.key.keysym.sym == SDLK_ESCAPE)
			break ;
		else if (event.type == SDL_KEYDOWN)
			key_event(l, event);
	}
	SDL_DestroyRenderer(l->sdl.renderer);
	SDL_DestroyWindow(l->sdl.window);
	SDL_Quit();
	return (0);
}
