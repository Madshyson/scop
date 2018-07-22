/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 09:13:39 by mlavanan          #+#    #+#             */
/*   Updated: 2015/11/28 01:05:44 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t			checkintlen(int n)
{
	size_t				i;

	i = 0;
	if (n < 0)
	{
		n = n * (-1);
		i++;
	}
	while (n > 0)
	{
		n = (n / 10);
		i++;
	}
	return (i);
}

char					*ft_itoa(int n)
{
	char				*nbr;
	size_t				i;

	i = 0;
	if (n == -2147483648)
		return ("-2147483648");
	if (n == 0)
		return ("0");
	i = checkintlen(n);
	nbr = ft_strnew(i);
	if (n < 0)
	{
		n = (-1) * n;
		nbr[0] = '-';
	}
	while (n > 0)
	{
		i--;
		nbr[i] = ((n % 10) + '0');
		n = (n / 10);
	}
	return (nbr);
}
