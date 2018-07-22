/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:17:03 by mlavanan          #+#    #+#             */
/*   Updated: 2015/11/26 18:27:58 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*dst;
	int		i;

	i = 0;
	dst = (char*)(malloc(sizeof(const char) * (ft_strlen(s) + 1)));
	while (s[i] != '\0')
	{
		dst[i] = f(s[i]);
		i++;
	}
	return (dst);
}
