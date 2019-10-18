/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_elem_to_list_while_parsing.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 19:24:48 by roduquen          #+#    #+#             */
/*   Updated: 2019/10/09 17:24:52 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"
#include <stdlib.h>

/*
**	--> check_last_number_in_line : makes last validity checks and then
**	adds the room to the list.
*/

static int	check_last_number_in_line(t_lemin *data, char **str, char *test)
{
	if (!test || !ft_iswhitespace(*test))
		return (free_return((void**)str, ERROR));
	while (ft_iswhitespace(*test))
		test++;
	if (*test == '0')
	{
		++test;
		if (*test && !ft_iswhitespace(*test))
			return (free_return((void**)str, ERROR));
	}
	else
		ft_strtol(test, &test, 10);
	if (!test)
		return (free_return((void**)str, ERROR));
	while (ft_iswhitespace(*test))
		test++;
	if (*test)
		return (free_return((void**)str, ERROR));
	if (add_rom_to_list(data, *str))
		return (free_return((void**)str, ERROR));
	free(*str);
	return (SUCCESS);
}

/*
**	--> add_node_if_well_formated : checks that each character of str
**	corresponds to a valid room name character.
*/

int			add_node_if_well_formated(t_lemin *data, char **str)
{
	int			i;
	char		*test;

	i = 0;
	if (data->actual_step != 1)
		return (free_return((void**)str, ERROR));
	while (str[0][i] && !ft_iswhitespace(str[0][i]))
	{
		if (str[0][i] == '-' || str[0][i] < 32 || str[0][i] == 127)
			return (free_return((void**)str, ERROR));
		i++;
	}
	while (ft_iswhitespace(str[0][i]))
		i++;
	if (!str[0][i])
		return (free_return((void**)str, ERROR));
	if (str[0][i] == '0')
	{
		if (!ft_iswhitespace(str[0][++i]))
			return (free_return((void**)str, ERROR));
		test = *str + i;
	}
	else
		ft_strtol(*str + i, &test, 10);
	return (check_last_number_in_line(data, str, test));
}
