/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 22:56:18 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/02 14:35:22 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*cpy_dst;
	unsigned char	*cpy_src;

	cpy_dst = (unsigned char*)dst;
	cpy_src = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		cpy_dst[i] = cpy_src[i];
		if ((unsigned char)c == cpy_src[i++])
			return (dst + i);
	}
	return (NULL);
}
