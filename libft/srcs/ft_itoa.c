/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:39:50 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/02 13:26:48 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	unsigned int	sign;
	unsigned int	size;
	char			*new_str;

	nbr = (n < 0 ? -n : n);
	sign = (n < 0 ? 1 : 0);
	size = 1;
	while (nbr >= 10)
	{
		nbr /= 10;
		size++;
	}
	if (!(new_str = ft_strnew(size + sign)))
		return (NULL);
	nbr = (n < 0 ? -n : n);
	while (size >= 1)
	{
		new_str[size - 1 + sign] = nbr % 10 + '0';
		nbr /= 10;
		size--;
	}
	if (sign == 1)
		new_str[0] = '-';
	return (new_str);
}
