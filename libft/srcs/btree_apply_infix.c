/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_infix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:38:45 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/02 13:24:52 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_apply_infix(t_btree *root, void (*applyf)(void*))
{
	if (!root)
		return ;
	if (root->left)
		btree_apply_infix(root->left, (*applyf));
	(*applyf)(root->item);
	if (root->right)
		btree_apply_infix(root->right, (*applyf));
}
