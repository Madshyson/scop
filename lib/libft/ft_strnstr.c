/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:10:18 by mlavanan          #+#    #+#             */
/*   Updated: 2015/11/27 23:34:03 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*str(char *str1, char *str2, size_t n)
{
	size_t		i;
	int			j;

	i = 0;
	j = 0;
	while (str1[i] != '\0' && i < n)
	{
		while (str2[j] == str1[i + j] && str2[j] != '\0' && str1[i + j] != '\0')
			j++;
		if ((i + j) > n)
			return (0);
		else if (str2[j] == '\0')
			return (&str1[i]);
		else
			j = 0;
		i++;
	}
	return (0);
}

char			*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	int			j;
	char		*str2;
	char		*str1;

	str1 = (char*)s1;
	str2 = (char*)s2;
	i = 0;
	j = 0;
	if (str1[i] == '\0' && str2[j] == '\0')
		return (&str1[i]);
	if (str1[i] != '\0' && str2[j] == '\0')
		return (&str1[i]);
	return (str(str1, str2, n));
}
