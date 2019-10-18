/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 11:57:34 by roduquen          #+#    #+#             */
/*   Updated: 2019/10/09 18:44:21 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

static int		translate_lstrom_to_tab(t_lemin *data)
{
	t_lstrom	*tmp;
	int			i;

	i = 0;
	tmp = data->rooms;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	if (!(data->room_tab = (t_lstrom **)malloc(sizeof(t_lstrom *) * i)))
		return (ERROR);
	i = 0;
	tmp = data->rooms;
	while (tmp)
	{
		data->room_tab[i++] = tmp;
		tmp = tmp->next;
	}
	return (SUCCESS);
}

static int		initialize_and_parse_data(t_lemin *data)
{
	data->begin_file = data->file;
	data->begin_file->str = NULL;
	data->file->next = NULL;
	parser(data);
	if (!(data->end) || !(data->start))
		return (ERROR);
	return (SUCCESS);
}

static int		launch_parsing_print_map(t_lemin *data)
{
	int			ret;

	if (initialize_and_parse_data(data) == ERROR)
	{
		write(1, "ERROR PARSING\n", sizeof("ERROR PARSING\n"));
		return (ERROR);
	}
	if (translate_lstrom_to_tab(data) == ERROR)
		return (ERROR);
	if ((ret = convert_parsing_to_usefull(data)) == ERROR)
	{
		ft_putendl_fd("Something went wrong when parsing standard input", 2);
		return (ERROR);
	}
	else if (ret == 42)
		print_start_to_end(data);
	return (SUCCESS);
}

int				main(void)
{
	t_lemin		data;
	void		*tmp;
	int			ret;

	ft_memset(&data, 0, sizeof(t_lemin));
	if (!(data.file = (t_lstst*)malloc(sizeof(t_lstst))))
	{
		ft_putendl_fd("Initial malloc has failed, check your memory use", 2);
		return (ERROR);
	}
	tmp = data.file;
	ret = launch_parsing_print_map(&data);
	while (tmp)
	{
		data.file = ((t_lstst*)tmp)->next;
		free(((t_lstst*)tmp)->str);
		free(tmp);
		tmp = data.file;
	}
	free_data_after_parsing(&data, 0);
	free_data_after_printing(&data, 0);
	return (ret);
}
