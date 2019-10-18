/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:42:34 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/02 13:44:18 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	full_str(char **new, const char *s, size_t start, size_t end)
{
	size_t	i;

	i = 0;
	if (end <= start)
	{
		if (!(*new = (char*)malloc(sizeof(char))))
			return (-1);
	}
	else
	{
		if (!(*new = (char*)malloc(sizeof(char) * (end - start + 2))))
			return (-1);
	}
	while (start < end)
	{
		new[0][i] = s[start];
		i++;
		start++;
	}
	new[0][i] = 0;
	return (0);
}

char		*ft_strtrim(char const *s)
{
	size_t			i;
	size_t			len;
	char			*new_str;

	new_str = NULL;
	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && ft_iswhitespace(s[i]))
		i++;
	len = i;
	while (s[i])
		i++;
	i--;
	while (i > 0 && ft_iswhitespace(s[i]))
		i--;
	if (i != 0)
		i++;
	if (full_str(&new_str, s, len, i) != 0)
		return (NULL);
	return (new_str);
}
