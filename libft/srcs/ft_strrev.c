/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:42:23 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/02 13:43:50 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *str)
{
	unsigned int	i;
	unsigned int	j;

	if (!str)
		return ;
	i = 0;
	while (str[i])
		i++;
	i--;
	j = 0;
	while (i > j)
	{
		ft_swapchar(&str[i], &str[j]);
		i--;
		j++;
	}
}
