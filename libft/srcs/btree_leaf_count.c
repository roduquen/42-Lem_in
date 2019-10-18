/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_leaf_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:39:09 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/02 13:25:08 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		btree_recursive_count(t_btree *current)
{
	if (current->left && current->right)
		return (btree_recursive_count(current->left)
			+ btree_recursive_count(current->right));
	else if (current->left)
		return (btree_recursive_count(current->left));
	else if (current->right)
		return (btree_recursive_count(current->right));
	else
		return (1);
}

int				btree_leaf_count(t_btree *root)
{
	if (!root)
		return (0);
	return (btree_recursive_count(root));
}
