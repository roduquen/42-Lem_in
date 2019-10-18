/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:40:17 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/02 13:27:11 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_elem;
	void	*new_content;

	if (!(new_elem = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		new_elem->content = NULL;
		new_elem->content_size = 0;
		new_elem->next = NULL;
		return (new_elem);
	}
	if (!(new_content = ft_memalloc(content_size)))
		return (NULL);
	if (!(new_content = ft_memcpy(new_content, content, content_size)))
		return (NULL);
	new_elem->content = new_content;
	new_elem->content_size = content_size;
	new_elem->next = NULL;
	return (new_elem);
}
