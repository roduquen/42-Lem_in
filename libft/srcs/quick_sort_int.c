/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:43:08 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/02 13:45:09 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static void		swap(int *a, int *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

void			quick_sort_int(int *tab, size_t size)
{
	int		pivot;
	size_t	i;
	size_t	current_mid;

	if (size < 2)
		return ;
	pivot = tab[size - 1];
	current_mid = 0;
	i = 0;
	while (i < size)
	{
		if (tab[i] <= pivot)
		{
			if (current_mid != i)
				swap(&tab[current_mid], &tab[i]);
			current_mid++;
		}
		i++;
	}
	if (current_mid > 3)
		quick_sort_int(tab, current_mid - 1);
	if (size - current_mid > 1)
		quick_sort_int(tab + current_mid - 1, size - current_mid + 1);
}
