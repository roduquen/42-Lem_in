/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:40:39 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/02 13:27:19 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	occur;

	i = 0;
	str = (unsigned char*)s;
	occur = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == occur)
			return ((void*)(str + i));
		i++;
	}
	return (NULL);
}
