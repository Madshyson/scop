/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:21:49 by mlavanan          #+#    #+#             */
/*   Updated: 2015/11/27 18:12:11 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_start(const char *s)
{
	int				i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	return (i);
}

static int			ft_end(const char *s)
{
	int				j;

	j = ft_strlen(s);
	j--;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	j++;
	return (j);
}

char				*ft_strtrim(char const *s)
{
	int				i;
	int				j;
	int				pos;
	char			*trim;

	pos = 0;
	while (s[pos] == ' ' || s[pos] == '\n' || s[pos] == '\t')
		pos++;
	if (s[pos] == '\0')
	{
		trim = "\0";
		return (trim);
	}
	pos = 0;
	i = ft_start(s);
	j = ft_end(s);
	trim = (char*)(malloc(sizeof(char) * ((j - i) + 1)));
	while (i < j)
	{
		trim[pos] = s[i];
		i++;
		pos++;
	}
	trim[pos] = '\0';
	return (trim);
}
