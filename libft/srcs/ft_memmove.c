/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:40:52 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/02 23:06:43 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*cpy_dest;
	unsigned char	*cpy_src;

	i = 0;
	cpy_dest = (unsigned char*)dest;
	cpy_src = (unsigned char*)src;
	while (i < len && cpy_dest > cpy_src)
	{
		cpy_dest[len - 1] = cpy_src[len - 1];
		len--;
	}
	while (i < len)
	{
		cpy_dest[i] = cpy_src[i];
		i++;
	}
	return (dest);
}
