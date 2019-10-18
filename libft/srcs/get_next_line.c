/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julesqvgn <julesqvgn@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 00:06:32 by jquivogn          #+#    #+#             */
/*   Updated: 2019/10/09 19:20:10 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static int	free_part_lst(char **lst_fd)
{
	ft_memdel((void **)lst_fd);
	return (0);
}

static int	get_new_line(char **str, char **line)
{
	char	*tmp;
	size_t	len;

	len = 0;
	while ((*str)[len] != '\n' && (*str)[len] != '\0')
		len++;
	if ((*str)[len] == '\n')
	{
		if (!(*line = ft_strsub(*str, 0, len)))
			return (-1);
		if (!(tmp = ft_strdup(*str + len + 1)))
			return (-1);
		ft_strdel(str);
		*str = tmp;
	}
	else if ((*str)[len] == '\0')
	{
		if (!(*line = ft_strdup(*str)))
			return (-1);
		ft_strdel(str);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	char			buffer[BUFF + 1];
	char			*tmp;
	int				ret;
	static char		*lst_fd[512];

	ret = 1;
	if (fd < 0 || line == NULL)
		return (-1);
	if (!lst_fd[fd])
		lst_fd[fd] = ft_strdup("");
	while (!(ft_strchr(lst_fd[fd], '\n'))
		&& (ret = read(fd, buffer, BUFF)) > 0)
	{
		buffer[ret] = '\0';
		if (!(tmp = ft_strjoin(lst_fd[fd], buffer)))
			return (-1);
		ft_strdel(&lst_fd[fd]);
		lst_fd[fd] = tmp;
	}
	if (ret < 0)
		return (-1);
	if (!ret && (!lst_fd[fd] || !*lst_fd[fd]))
		return (free_part_lst(&lst_fd[fd]));
	return (get_new_line(&lst_fd[fd], line));
}
