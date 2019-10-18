/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:41:55 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/02 13:42:03 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*new_str;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
	{
		if (!(new_str = ft_strnew(ft_strlen(s2))))
			return (NULL);
		ft_strcpy(new_str, s2);
	}
	else if (!s2)
	{
		if (!(new_str = ft_strnew(ft_strlen(s1))))
			return (NULL);
		ft_strcpy(new_str, s1);
	}
	else
	{
		if (!(new_str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
			return (NULL);
		ft_strcpy(new_str, s1);
		ft_strcat(new_str, s2);
	}
	return (new_str);
}
