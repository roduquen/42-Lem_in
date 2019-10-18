/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_suffix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:38:54 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/02 13:24:56 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_apply_suffix(t_btree *root, void (*applyf)(void*))
{
	if (!root)
		return ;
	if (root->left)
		btree_apply_suffix(root->left, (*applyf));
	if (root->right)
		btree_apply_suffix(root->right, (*applyf));
	(*applyf)(root->item);
}
