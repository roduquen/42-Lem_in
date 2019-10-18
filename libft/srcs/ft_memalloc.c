/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:40:34 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/02 13:27:13 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*new_mem;

	if (!(new_mem = (void*)malloc(size)))
		return (NULL);
	ft_memset(new_mem, 0, size);
	return (new_mem);
}
