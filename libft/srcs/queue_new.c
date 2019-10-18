/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julesqvgn <julesqvgn@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:43:04 by roduquen          #+#    #+#             */
/*   Updated: 2019/10/09 13:18:24 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_queue		*queue_new(void *ptr)
{
	t_queue	*new;

	if (!(new = (t_queue*)malloc(sizeof(t_queue))))
		return (NULL);
	new->ptr = ptr;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
