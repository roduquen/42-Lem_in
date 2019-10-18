/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cocktail_sort_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:39:16 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/02 13:25:36 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static void	swap(int *a, int *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

void		cocktail_sort_int(int *tab, size_t size)
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
			if (tab[i] > tab[i + 1])
				swap(&tab[i], &tab[i + 1]);
			i++;
		}
		max--;
		while (i > min)
		{
			if (tab[i] < tab[i - 1])
				swap(&tab[i], &tab[i - 1]);
			i--;
		}
		min++;
	}
}
