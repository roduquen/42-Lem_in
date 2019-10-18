/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_part2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 16:15:11 by roduquen          #+#    #+#             */
/*   Updated: 2019/10/09 17:24:56 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"
#include <stdlib.h>

int			free_return(void **ptr, int type)
{
	free(*ptr);
	return (type);
}

/*
**	--> add_nbr_lem : performs an atoi to store the number of ants.
*/

static int	add_nbr_lem(char **str, t_lemin *data)
{
	int			i;
	long		result;

	i = 0;
	result = 0;
	if (!str[0][i])
		return (free_return((void**)str, ERROR));
	while (str[0][i] && str[0][i] >= '0' && str[0][i] <= '9')
	{
		result = result * 10 + str[0][i++] - '0';
		if (result >= 2147483648)
			return (free_return((void**)str, ERROR));
	}
	if (str[0][i] || result <= 0)
		return (free_return((void**)str, ERROR));
	data->actual_step = 1;
	data->nbr_lem = result;
	if (data->start_end)
		return (free_return((void**)str, ERROR));
	return (free_return((void**)str, SUCCESS));
}

/*
**	--> find_type_of_line : converts list to a string str and then
**	depending on what type of data we have, performs actions :
**	if we are on the "number of ants" step (ret = 0 and step = 0),
**	it launches the number of ants parsing function,
**	if we are checking links (ret = 0 and step = 2), it means we
**	are on the link step, so it launches the link parsing function,
**	finally, if ret is positive, it means we are dealing with the rooms
**	so it launches the node parsing function.
*/

int			find_type_of_line(t_lstch *begin, t_lemin *data, int len)
{
	char		*str;
	int			ret;

	str = NULL;
	if ((ret = translate_list_to_string(begin, &str, len)) == ERROR)
	{
		free(str);
		return (ERROR);
	}
	if (!ret)
	{
		if (data->actual_step == 0)
			return (add_nbr_lem(&str, data));
		else
			return (add_link_if_well_formated(data, &str));
	}
	return (add_node_if_well_formated(data, &str));
}
