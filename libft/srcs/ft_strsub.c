/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:42:31 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/02 13:44:08 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*new_str;

	if (!s)
		return (NULL);
	if (!(new_str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = start;
	j = 0;
	while (s[i] && j < len)
	{
		new_str[j] = s[i];
		i++;
		j++;
	}
	new_str[j] = 0;
	return (new_str);
}
