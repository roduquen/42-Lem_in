/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 18:08:32 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/02 13:25:41 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned int	i;
	unsigned int	nbr;
	int				sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = (str[i++] == '-' ? -1 : 1);
	while (str[i] && ft_isdigit(str[i]))
		nbr = nbr * 10 + str[i++] - '0';
	return (nbr * sign);
}
