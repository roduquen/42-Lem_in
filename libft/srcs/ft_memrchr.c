/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:40:54 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/02 13:27:28 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memrchr(const void *s, int c, size_t n)
{
	size_t			i;
	int				mem;
	unsigned char	*str;
	unsigned char	occur;

	if (!s)
		return (NULL);
	i = 0;
	mem = -1;
	str = (unsigned char*)s;
	occur = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == occur)
			mem = i;
		i++;
	}
	if (mem == -1)
		return (NULL);
	return ((void*)str + mem);
}
