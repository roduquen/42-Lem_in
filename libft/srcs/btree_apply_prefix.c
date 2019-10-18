/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:38:49 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/02 13:24:53 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_apply_prefix(t_btree *root, void (*applyf)(void*))
{
	if (!root)
		return ;
	(*applyf)(root->item);
	if (root->left)
		btree_apply_prefix(root->left, (*applyf));
	if (root->right)
		btree_apply_prefix(root->right, (*applyf));
}
