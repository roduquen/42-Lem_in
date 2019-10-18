/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cocktail_sort_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:39:22 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/02 13:25:38 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void		cocktail_sort_string(char **tab, size_t size)
{
	size_t		i;
	size_t		max;
	size_t		min;

	max = size - 1;
	min = 0;
	i = 0;
	while (min < max)
	{
		while (i < max)
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
				swap(&tab[i], &tab[i + 1]);
			i++;
		}
		max--;
		while (i > min)
		{
			if (ft_strcmp(tab[i], tab[i - 1]) < 0)
				swap(&tab[i], &tab[i - 1]);
			i--;
		}
		min++;
	}
}
