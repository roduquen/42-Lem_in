/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 00:44:41 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/02 13:43:55 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	word_count(char const *s, char c)
{
	size_t	i;
	size_t	word_nbr;

	i = 0;
	word_nbr = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		word_nbr++;
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (word_nbr);
}

static int	letter_count(char const *s, char c, size_t start)
{
	size_t	i;

	i = 0;
	while (s[i + start] && s[i + start] != c)
		i++;
	return (i + 1);
}

static int	full_tab(char **tab, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	while (s[i] && s[i] == c)
		i++;
	j = 0;
	while (s[i])
	{
		if (!(tab[j] = (char*)malloc(sizeof(char) * (letter_count(s, c, i)))))
			return (-1);
		k = 0;
		while (s[i] && s[i] != c)
			tab[j][k++] = s[i++];
		tab[j][k] = 0;
		while (s[i] && s[i] == c)
			i++;
		j++;
	}
	tab[j] = 0;
	return (0);
}

char		**ft_strsplit(char const *s, char c)
{
	size_t	nbr_word;
	char	**tab;

	if (!s)
		return (NULL);
	nbr_word = word_count(s, c);
	if (!(tab = (char**)malloc(sizeof(char*) * (nbr_word + 1))))
		return (NULL);
	if (full_tab(tab, s, c) != 0)
		return (NULL);
	return (tab);
}
