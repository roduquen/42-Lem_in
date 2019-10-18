/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:40:26 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/02 14:18:17 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin_list;
	t_list	*current;
	t_list	*tmp;

	if (!lst || !(*f))
		return (NULL);
	begin_list = NULL;
	while (lst)
	{
		if (!(tmp = (*f)(lst)))
			return (NULL);
		if (begin_list == NULL)
		{
			begin_list = tmp;
			current = tmp;
		}
		else
		{
			current->next = tmp;
			current = current->next;
			current->next = NULL;
		}
		lst = lst->next;
	}
	return (begin_list);
}
