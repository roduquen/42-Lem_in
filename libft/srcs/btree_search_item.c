/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:39:14 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/02 14:35:09 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*btree_search_item(t_btree *root, void *data_ref
	, int (*cmpf)(void*, void*))
{
	if (!root)
		return (NULL);
	else if ((*cmpf)(data_ref, root->item) < 0)
		return (btree_search_item(root->left, data_ref, (*cmpf)));
	else if ((*cmpf)(data_ref, root->item) == 0)
		return (root->item);
	else if ((*cmpf)(data_ref, root->item) > 0)
		return (btree_search_item(root->right, data_ref, (*cmpf)));
	else
		return (NULL);
}
