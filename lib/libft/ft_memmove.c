/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:35:37 by mlavanan          #+#    #+#             */
/*   Updated: 2015/11/26 20:50:28 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void						*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char		*s;
	char					*temp;
	unsigned char			*d;

	s = src;
	d = dst;
	temp = ft_strnew(len);
	ft_memcpy(temp, s, len);
	ft_memcpy(d, temp, len);
	return (dst);
}
