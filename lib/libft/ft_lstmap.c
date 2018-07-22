/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 21:55:10 by mlavanan          #+#    #+#             */
/*   Updated: 2015/11/28 00:37:36 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *nlist;
	t_list *nelem;
	t_list *pelem;

	nlist = NULL;
	if (lst)
	{
		nlist = (*f)(lst);
		pelem = nlist;
		lst = lst->next;
		while (lst)
		{
			nelem = (*f)(lst);
			pelem->next = nelem;
			pelem = nelem;
			lst = lst->next;
		}
		pelem->next = NULL;
	}
	return (nlist);
}
