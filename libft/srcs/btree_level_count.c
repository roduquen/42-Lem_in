/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:39:11 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/02 13:25:10 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		btree_max_depth(t_btree *root, int actual, int *max_depth)
{
	if (root->left)
		btree_max_depth(root->left, actual + 1, max_depth);
	if (actual > *max_depth)
		*max_depth = actual;
	if (root->right)
		btree_max_depth(root->right, actual + 1, max_depth);
}

int				btree_level_count(t_btree *root)
{
	int		max_depth;

	if (!root)
		return (0);
	max_depth = 1;
	btree_max_depth(root, 1, &max_depth);
	return (max_depth);
}
