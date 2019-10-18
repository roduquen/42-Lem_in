/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:43:10 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/02 13:45:21 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void			quick_sort_string(char **tab, size_t size)
{
	char	*pivot;
	size_t	i;
	size_t	current_mid;

	if (size < 2)
		return ;
	pivot = tab[size - 1];
	current_mid = 0;
	i = 0;
	while (i < size)
	{
		if (ft_strcmp(tab[i], pivot) <= 0)
		{
			if (current_mid != i)
				swap(&tab[current_mid], &tab[i]);
			current_mid++;
		}
		i++;
	}
	quick_sort_string(tab, current_mid - 1);
	quick_sort_string(tab + current_mid - 1, size - current_mid + 1);
}
