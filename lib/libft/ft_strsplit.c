/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:04:05 by mlavanan          #+#    #+#             */
/*   Updated: 2015/11/26 17:39:49 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		countsplit(char const *s, char c)
{
	int			i;
	int			nbsplit;

	i = 0;
	nbsplit = 0;
	while (s[i] != '\0')
	{
		if ((i == 0) && s[i] != c)
			nbsplit++;
		else if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			nbsplit++;
		i++;
	}
	return (nbsplit);
}

static char		*createsplitt(char const *s, char c, int i)
{
	char		*split;
	int			pos;
	int			j;
	int			sizesp;

	pos = i;
	j = 0;
	sizesp = 0;
	while (s[pos] != c && s[pos] != '\0')
	{
		sizesp++;
		pos++;
	}
	split = (char*)(malloc(sizeof(char) * (sizesp + 1)));
	while (j < sizesp)
	{
		split[j] = s[i + j];
		j++;
	}
	split[j] = '\0';
	return (split);
}

char			**ft_strsplit(char const *s, char c)
{
	int			i;
	int			j;
	char		**split;
	int			nbs;

	i = 0;
	j = 0;
	nbs = countsplit(s, c);
	split = (char**)(malloc(sizeof(char*) * (nbs + 1)));
	while (i < nbs)
	{
		while (s[j] == c)
			j++;
		split[i] = createsplitt(s, c, j);
		while (s[j] != c && s[j] != '\0')
			j++;
		i++;
	}
	split[i] = (NULL);
	return (split);
}
