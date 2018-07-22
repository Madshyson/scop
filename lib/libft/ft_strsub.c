/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:31:22 by mlavanan          #+#    #+#             */
/*   Updated: 2015/11/26 19:13:44 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*sub;

	i = start;
	sub = (char*)(malloc(sizeof(const char) * (len + 1)));
	if (sub)
	{
		while (i < (start + len) && (s[i] != '\0'))
		{
			sub[i - start] = s[i];
			i++;
		}
		return (sub);
	}
	else
		return (NULL);
}
