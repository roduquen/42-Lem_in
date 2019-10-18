/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:42:21 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/02 13:43:44 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	int				mem;
	unsigned char	*str;
	unsigned char	occur;

	i = 0;
	mem = -1;
	str = (unsigned char*)s;
	occur = (unsigned char)c;
	while (str[i])
	{
		if (str[i] == occur)
			mem = i;
		i++;
	}
	if (c == 0)
		return ((char*)str + i);
	if (mem == -1)
		return (NULL);
	return ((char*)str + mem);
}
