/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <mlavanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 04:53:29 by mlavanan          #+#    #+#             */
/*   Updated: 2018/07/22 16:49:28 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/scop.h"

static void			freerecur(char **coord, char *line)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < (int)ft_strlen(line))
	{
		if (line[i] == ' ')
			count++;
		i++;
	}
	while (count >= 0)
	{
		free(coord[count]);
		count--;
	}
	free(coord);
}

t_objdata			*setvertices(t_objdata *obj, char *line)
{
	int		i;
	char	**coord;
	t_vlist *v;

	v = malloc(sizeof(t_vlist));
	v->next = NULL;
	i = 1;
	coord = ft_strsplit(line, ' ');
	obj->nbvertices += 1;
	while (coord[i] != NULL)
	{
		v->vertice[i - 1] = atof(coord[i]);
		i++;
	}
	verticalloc(v, obj);
	freerecur(coord, line);
	return (obj);
}

static t_flist		*createtfromq(t_flist *f, char **coord)
{
	t_flist *n;

	n = malloc(sizeof(t_flist));
	n->face[0] = atoi(coord[1]);
	n->face[1] = atoi(coord[3]);
	n->face[2] = atoi(coord[4]);
	n->next = NULL;
	f->next = n;
	return (f);
}

t_objdata			*setfaces(t_objdata *obj, char *line)
{
	int		i;
	char	**coord;
	t_flist *f;

	f = malloc(sizeof(t_flist));
	f->next = NULL;
	i = 1;
	coord = ft_strsplit(line, ' ');
	obj->nbfaces += 1;
	while (coord[i] != NULL)
	{
		f->face[i - 1] = atoi(coord[i]);
		i++;
	}
	if (i == 5)
	{
		f = createtfromq(f, coord);
		obj->nbpoints += 6;
	}
	obj->nbpoints += (i - 1) * 3;
	facealloc(f, obj);
	freerecur(coord, line);
	return (obj);
}

t_objdata			*dataparser(int ac, char **av, t_objdata *obj)
{
	int		fd;
	int		ret;
	char	*line;
	int		i;

	i = 0;
	if (ac == 2 && testgoodfile(av[1]) == 1)
	{
		fd = open(av[1], O_RDONLY);
		obj->filename = av[1];
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			if (line[0] == 'v' && line[1] == ' ')
				setvertices(obj, line);
			if (line[0] == 'f')
				setfaces(obj, line);
			free(line);
		}
		fd = close(fd);
	}
	else
		obj = seterror(1, obj);
	if (obj->nbpoints % 3 != 0)
		obj = seterror(2, obj);
	return (obj);
}
