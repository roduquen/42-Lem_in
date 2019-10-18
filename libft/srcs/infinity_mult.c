/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infinity_mult.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 09:06:25 by roduquen          #+#    #+#             */
/*   Updated: 2019/05/05 00:21:07 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*add_decimal_by_decimal(char *nbr1, int nbr_boucle)
{
	char	*tmp;
	char	*to_save;

	if (!(tmp = (char*)malloc(sizeof(char) * 1)))
		return (NULL);
	tmp[0] = 0;
	while (nbr_boucle > 0)
	{
		to_save = tmp;
		tmp = infinity_add_plus(to_save, nbr1);
		free(to_save);
		nbr_boucle--;
	}
	return (tmp);
}

static char	*mult_nbr(char *nbr1, int nbr_boucle)
{
	char	*result;
	int		i;
	int		len;

	len = ft_strlen(nbr1);
	if (!(result = (char*)malloc(sizeof(char) * (len + nbr_boucle + 1))))
		return (NULL);
	ft_memmove(result, nbr1, len);
	i = 0;
	while (i < nbr_boucle)
	{
		result[i + len] = '0';
		i++;
	}
	result[i + len] = 0;
	return (result);
}

char		*infinity_mult(char *nbr1, char *nbr2)
{
	char	*result;
	char	*up;
	char	*tmp;
	int		i;
	int		len;

	len = ft_strlen(nbr2);
	i = len - 1;
	if (!(result = (char*)malloc(sizeof(char))))
		return (NULL);
	up = nbr1;
	while (i >= 0)
	{
		tmp = add_decimal_by_decimal(up, nbr2[i] - '0');
		up = result;
		result = infinity_add_plus(tmp, result);
		free(up);
		free(tmp);
		up = mult_nbr(nbr1, len - i);
		i--;
	}
	return (result);
}
