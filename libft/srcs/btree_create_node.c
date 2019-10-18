/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:39:03 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/02 13:24:59 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_btree		*btree_create_node(void *item)
{
	t_btree		*node;

	if (!(node = (t_btree*)malloc(sizeof(t_btree))))
		return (NULL);
	node->item = item;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
