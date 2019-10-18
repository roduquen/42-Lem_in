/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:39:06 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/02 14:34:44 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		btree_chose_place(t_btree **current, t_btree **new_elem
	, int (*cmpf)(void*, void*))
{
	if (!(*current))
		(*current) = *new_elem;
	else if ((*cmpf)((*new_elem)->item, (*current)->item) < 0)
		btree_chose_place(&(*current)->left, new_elem, (*cmpf));
	else
		btree_chose_place(&(*current)->right, new_elem, (*cmpf));
}

void			btree_insert_data(t_btree **root, void *item
	, int (*cmpf)(void*, void*))
{
	t_btree		*new_elem;

	if (!root)
		return ;
	if (!(new_elem = btree_create_node(item)))
		return ;
	btree_chose_place(root, &new_elem, (*cmpf));
}
