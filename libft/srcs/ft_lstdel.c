/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:39:57 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/02 14:18:47 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*next;

	if (!alst || !*alst || !(*del))
		return ;
	while ((*alst))
	{
		next = (*alst)->next;
		ft_lstdelone(&(*alst), &(*del));
		(*alst) = next;
	}
}
