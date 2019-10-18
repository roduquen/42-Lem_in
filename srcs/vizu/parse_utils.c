/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:30:24 by julesqvgn         #+#    #+#             */
/*   Updated: 2019/10/09 19:15:12 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leminvizu.h"

int		ft_parse_error(char *error)
{
	if (*error)
		ft_putendl_fd(error, 2);
	return (0);
}

int		ft_free(char *error, char **str, int i)
{
	free(*str);
	if (i == 2)
		return (1);
	return (i == 1 ? ft_parse_error(error) : 0);
}

int		ft_room_clear(t_lemin *l)
{
	t_room	*stock;
	t_room	*supp;
	int		i;

	i = -1;
	stock = l->room;
	while (stock != 0)
	{
		supp = stock;
		stock = stock->next;
		free(supp->name);
		free(supp->link);
		free(supp);
	}
	return (0);
}

int		get_ants(t_lemin *l)
{
	char	*line;
	char	*test;

	if (get_next_line(0, &line) < 1)
		return (ft_parse_error("ERROR during reading file"));
	if (!*line)
		return (ft_free("ERROR: nb of ants has not been specified", &line, 1));
	l->ants = ft_strtol(line, &test, 10);
	if (!test || test[0])
		return (ft_free("ERROR: ants line not well formatted", &line, 1));
	free(line);
	return (1);
}

int		is_room(char *line)
{
	int	i;
	int	c;

	if (!*line || (*line == '#' || *line == 'L'))
		return (0);
	c = 0;
	while (line[c] && line[c] != ' ')
		c++;
	i = 0;
	if (!line[c])
		return (0);
	while (line[c])
	{
		if (line[c] == ' ')
			i++;
		if ((line[c] != ' ' && (!ft_isdigit(line[c]))) || i > 2)
			return (0);
		c++;
	}
	return (1);
}
