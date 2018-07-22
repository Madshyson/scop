/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 19:29:07 by mlavanan          #+#    #+#             */
/*   Updated: 2015/11/27 18:38:22 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nblength(const char *str)
{
	int			i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
			str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}

int				ft_atoi(const char *str)
{
	int			i;
	int			coeff;
	int			res;

	coeff = 1;
	res = 0;
	i = nblength(str);
	i--;
	while (i >= 0)
	{
		if (str[i] == '-')
			return (-1 * res);
		if (str[i] == '+' || str[i] == ' ' || str[i] == '\t' ||
			str[i] == '\n' || str[i] == '\r' || str[i] == '\v' ||
			str[i] == '\f')
			return (res);
		res = res + coeff * (str[i] - '0');
		coeff *= 10;
		i--;
	}
	return (res);
}
