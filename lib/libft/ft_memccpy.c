/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:03:02 by mlavanan          #+#    #+#             */
/*   Updated: 2015/11/26 21:16:15 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		chr;
	const unsigned char *s;
	unsigned char		*d;

	i = 0;
	s = src;
	d = dst;
	chr = c;
	while (i < n)
	{
		d[i] = s[i];
		if (s[i] == chr)
		{
			i++;
			return (&dst[i]);
		}
		i++;
	}
	return (NULL);
}
