/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infinity_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 09:08:50 by roduquen          #+#    #+#             */
/*   Updated: 2019/05/05 00:20:49 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void		add_char_by_char(char *result, char *nbr1, char *nbr2
	, int size_max)
{
	int			i;
	int			j;
	int			ret;
	char		add_ret;

	i = ft_strlen(nbr1);
	j = ft_strlen(nbr2) - 1;
	ret = 0;
	while (--i >= 0)
	{
		add_ret = (ret >= 10 ? 1 : 0);
		if ((ret = nbr1[i] + (j >= 0 ? nbr2[j] : '0')
				+ result[size_max] - 3 * '0') >= 0)
			result[size_max] = ret % 10 + '0';
		if (add_ret && result[size_max] != '9')
			result[size_max]++;
		else if (add_ret)
		{
			result[size_max] = '0';
			result[size_max - 1]++;
		}
		size_max--;
		j--;
	}
	result[size_max] += (ret >= 10 ? 1 : 0);
}

char			*infinity_add_plus(char *nbr1, char *nbr2)
{
	char		*result;
	int			ret1;
	int			ret2;
	int			size_max;

	ret1 = ft_strlen(nbr1);
	ret2 = ft_strlen(nbr2);
	size_max = (ret1 > ret2 ? ret1 + 1 : ret2 + 1);
	if (!(result = (char*)malloc(sizeof(char) * (size_max + 1))))
		return (NULL);
	ft_memset(result, '0', size_max);
	result[size_max] = 0;
	if (ret1 > ret2)
		add_char_by_char(result, nbr1, nbr2, size_max - 1);
	else
		add_char_by_char(result, nbr2, nbr1, size_max - 1);
	ret1 = 0;
	while (result[ret1] == '0')
		ret1++;
	ft_memmove(result, result + ret1, size_max - ret1);
	result[size_max - ret1] = 0;
	return (result);
}
