/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:20:14 by mlavanan          #+#    #+#             */
/*   Updated: 2016/01/28 17:26:08 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*filljoin(char const *s1, char const *s2, char *join)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (s1[j] != '\0')
	{
		join[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		join[i] = s2[j];
		i++;
		j++;
	}
	join[i] = '\0';
	return (join);
}

char				*ft_strjoin(char const *s1, char const *s2)
{
	int				i;
	int				j;
	char			*join;
	int				len;

	i = 0;
	j = 0;
	len = (ft_strlen(s1) + ft_strlen(s2));
	join = (char*)(malloc(sizeof(const char) * (len + 1)));
	if (join)
	{
		join = filljoin(s1, s2, join);
		return (join);
	}
	return (NULL);
}
