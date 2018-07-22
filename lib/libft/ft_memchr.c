/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 09:21:18 by mlavanan          #+#    #+#             */
/*   Updated: 2015/11/26 21:33:35 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*str;
	unsigned char		uchr;
	size_t				i;

	i = 0;
	uchr = c;
	str = (unsigned char*)s;
	while (i < n)
	{
		if (str[i] == uchr)
		{
			return (&str[i]);
		}
		i++;
	}
	return (NULL);
}
