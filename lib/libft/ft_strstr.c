/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:45:00 by mlavanan          #+#    #+#             */
/*   Updated: 2015/11/27 18:42:58 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*str1;

	i = 0;
	j = 0;
	str1 = (char*)s1;
	if (s2[j] == '\0')
		return (str1);
	while (str1[i] != '\0')
	{
		if (s2[j] == str1[i])
		{
			while (s2[j] != '\0' && s2[j] == str1[i + j])
				j++;
			if (s2[j] == '\0')
				return (&str1[i]);
		}
		j = 0;
		i++;
	}
	return (NULL);
}
