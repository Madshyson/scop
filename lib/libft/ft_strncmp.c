/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:07:34 by mlavanan          #+#    #+#             */
/*   Updated: 2015/11/27 18:09:55 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		j;
	int			i;

	i = 0;
	j = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && j < n)
	{
		if (s1[i] != s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
		j++;
	}
	if (j == n)
		return (0);
	if (s1[i] == '\0' && s2[i] != '\0')
		return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
	if (s1[i] != '\0' && s2[i] == '\0')
		return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
	return (0);
}
