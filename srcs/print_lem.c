/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:28:00 by roduquen          #+#    #+#             */
/*   Updated: 2019/10/09 18:44:32 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"
#include <unistd.h>

void				print_lem(t_lemin *data, int result, t_queue *last)
{
	write(1, "L", 1);
	ft_putnbr(((t_disp*)data->queue[0]->ptr)->lem);
	write(1, "-", 1);
	write(1, NAME_OF_ROOM, ft_strlen(NAME_OF_ROOM));
	data->queue[0] = data->queue[0]->next;
	if (data->queue[0] && (!(result - 1) || last != data->queue[0]->prev))
		write(1, " ", 1);
}

void				print_begin_file(t_lemin *data)
{
	while (data->begin_file)
	{
		if (data->begin_file->str)
		{
			ft_putstr(data->begin_file->str);
			write(1, "\n", 1);
		}
		data->begin_file = data->begin_file->next;
	}
	write(1, "\n", 1);
}

void				print_start_to_end(t_lemin *data)
{
	int		i;

	i = 1;
	print_begin_file(data);
	while (i <= data->nbr_lem)
	{
		write(1, "L", 1);
		ft_putnbr(i);
		write(1, "-", 1);
		write(1, data->end->name, ft_strlen(data->end->name));
		if (i < data->nbr_lem)
			write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}
