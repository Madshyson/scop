/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 19:42:39 by mlavanan          #+#    #+#             */
/*   Updated: 2015/11/27 23:29:51 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*nlist;

	nlist = malloc(sizeof(t_list));
	if (nlist)
	{
		if (content)
		{
			nlist->content = malloc(sizeof(content_size));
			nlist->content = ft_memcpy(nlist->content, content, content_size);
			nlist->content_size = content_size;
			nlist->next = NULL;
		}
		else
		{
			nlist->content = NULL;
			nlist->content_size = 0;
			nlist->next = NULL;
		}
		return (nlist);
	}
	else
		return (NULL);
}
