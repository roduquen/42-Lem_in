/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 16:27:01 by roduquen          #+#    #+#             */
/*   Updated: 2019/07/24 12:24:56 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		chose_right_base(char *str)
{
	int		i;

	i = 0;
	while (str[i] && ft_iswhitespace(str[i]))
		i++;
	if (str[i] && str[i] == '-')
		i++;
	if (str[i] && str[i] == '0')
	{
		if (str[i + 1] && (str[i + 1] == 'x' || str[i + 1] == 'X'))
			return (16);
		return (8);
	}
	return (10);
}

static long		convert_decimal(char *str, char **endptr)
{
	int				sign;
	size_t			i;
	unsigned long	result;

	result = 0;
	i = 0;
	while (ft_iswhitespace(str[i]))
		i++;
	sign = (str[i] == '-' ? -1 : 1);
	i = (sign == -1 ? i + 1 : i);
	if (str[i] != '0')
	{
		while (str[i] >= '0' && str[i] <= '9')
		{
			result = result * 10 + str[i++] - '0';
			if (result > 2147483648l || (result == 2147483648l && sign == 1))
			{
				*endptr = NULL;
				return (0);
			}
		}
	}
	*endptr = str + i;
	return (result * sign);
}

static long		convert_octal(char *str, char **endptr)
{
	int				sign;
	size_t			i;
	unsigned long	result;

	result = 0;
	i = 0;
	while (ft_iswhitespace(str[i]))
		i++;
	sign = (str[i] == '-' ? -1 : 1);
	i = (sign == -1 ? i + 1 : i);
	if (str[i] != '0')
	{
		*endptr = NULL;
		return (0);
	}
	i++;
	while (str[i] >= '0' && str[i] <= '7')
		result = result * 8 + str[i++] - '0';
	*endptr = str + i;
	return (result * sign);
}

static long		convert_hexadecimal(char *str, char **endptr, char *base)
{
	int				sign;
	size_t			i;
	unsigned long	result;

	result = 0;
	i = 0;
	while (ft_iswhitespace(str[i]))
		i++;
	sign = (str[i] == '-' ? -1 : 1);
	i = (sign == -1 ? i + 1 : i);
	if (!str[i] || !str[i + 1] || str[i] != '0'
		|| (str[i + 1] != 'x' && str[i + 1] != 'X'))
	{
		*endptr = NULL;
		return (0);
	}
	i += 2;
	while (str[i] && ft_strchr(base, str[i]))
		result = result * 16 + (ft_strchr(base, str[i++]) - base) % 16;
	*endptr = str + i;
	return (result * sign);
}

long			ft_strtol(char *str, char **endptr, int base)
{
	if (!str || !endptr)
		return (0);
	if (base == 0)
		base = chose_right_base(str);
	if (base == 10)
		return (convert_decimal(str, endptr));
	if (base == 16)
	{
		return (convert_hexadecimal(str, endptr
				, "0123456789abcdef0123456789ABCDEF"));
	}
	if (base == 8)
		return (convert_octal(str, endptr));
	*endptr = NULL;
	return (-1);
}
