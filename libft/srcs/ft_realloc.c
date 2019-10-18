/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:41:21 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/02 13:28:40 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_realloc(char *str, int size)
{
	int		i;
	char	*new_str;

	if (!(new_str = (char*)malloc(sizeof(char) * (size))))
		return (NULL);
	i = 0;
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = 0;
	free(str);
	return (new_str);
}
