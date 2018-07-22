/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoitab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 16:33:55 by mlavanan          #+#    #+#             */
/*   Updated: 2016/01/28 17:21:01 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_atoitab(char *str)
{
	int		i;
	char	**split;
	int		*tab;

	i = 0;
	split = ft_strsplit(str, ' ');
	tab = malloc(sizeof(int) * ft_strlen(str) + 1);
	while (split[i] != NULL)
	{
		tab[i] = ft_atoi(split[i]);
		i++;
	}
	return(tab);
}
