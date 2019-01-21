/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 15:02:55 by mlavanan          #+#    #+#             */
/*   Updated: 2018/07/22 15:03:41 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/scop.h"

void			verticalloc(t_vlist *v, t_objdata *obj)
{
	if (!obj->vertices)
	{
		obj->vertices = v;
		obj->vertices->next = NULL;
		obj->verticesstart = obj->vertices;
	}
	else
	{
		v->next = NULL;
		obj->vertices = obj->verticesstart;
		while (obj->vertices->next)
		{
			obj->vertices = obj->vertices->next;
		}
		obj->vertices->next = v;
	}
}

void			facealloc(t_flist *f, t_objdata *obj)
{
	if (!obj->faces)
	{
		obj->faces = f;
		obj->facesstart = obj->faces;
	}
	else
	{
		obj->faces = obj->facesstart;
		while (obj->faces->next)
		{
			obj->faces = obj->faces->next;
		}
		obj->faces->next = f;
	}
}

t_objdata		*seterror(int errorval, t_objdata *obj)
{
	if (errorval == 1)
	{
		obj->error = 1;
		obj->filename = "Error";
		ft_putendl("This function accept only one argument : a .obj file");
	}
	if (errorval == 2)
	{
		obj->error = 1;
		obj->filename = "Error";
		ft_putendl("this file is not well formated");
	}
	return (obj);
}

int				testgoodfile(char *fn)
{
	if (ft_strstr(fn, ".obj") == NULL)
		return (0);
	return (1);
}
