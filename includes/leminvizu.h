/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leminvizu.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 16:32:33 by julesqvgn         #+#    #+#             */
/*   Updated: 2019/10/09 16:47:28 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMINVIZU_H
# define LEMINVIZU_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <SDL.h>

# define WIDTH		1200
# define HEIGHT		900
# define MIDDLE_W	WIDTH / 2
# define MIDDLE_H	HEIGHT / 2

typedef struct		s_sdl
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
}					t_sdl;

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	uint8_t			start;
	uint8_t			end;
	int				full;
	struct s_room	*next;
	struct s_room	**link;
}					t_room;

typedef struct		s_lemin
{
	int				ants;
	int				n_room;
	int				mv_x;
	int				mv_y;
	int				zoom;
	int				sx_room;
	int				sy_room;
	int				go;
	int				x_min;
	int				x_max;
	int				y_min;
	int				y_max;
	uint8_t			start;
	uint8_t			end;
	t_sdl			sdl;
	t_room			*room;
}					t_lemin;

int					ft_room_clear(t_lemin *l);
int					ft_parse(t_lemin *l);
int					ft_room_list(t_room **begin_list, t_lemin *l,
						int *pos, char *line);
int					ft_free(char *error, char **str, int i);
int					ft_parse_error(char *error);
int					ft_comment(t_lemin *l, int *pos, char **line);
int					visual(t_lemin *l);
int					parse_path(t_lemin *l);
int					lem_visu(t_lemin *l);
int					is_room(char *line);
int					get_ants(t_lemin *l);
int					add_link(char *l, int i, t_room *room);
int					key_event(t_lemin *l, SDL_Event event);
int					choose_color(t_lemin *l, t_room *tmp, int i);
int					get_link(t_lemin *l);

#endif
