/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:26:07 by mlavanan          #+#    #+#             */
/*   Updated: 2015/11/26 17:36:03 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dst;
	unsigned int	i;

	i = 0;
	dst = (char*)(malloc(sizeof(ft_strlen(s) + 1)));
	while (s[i] != '\0')
	{
		dst[i] = f(i, s[i]);
		i++;
	}
	return (dst);
}
