/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 14:14:01 by mlavanan          #+#    #+#             */
/*   Updated: 2016/02/08 16:04:40 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl			*initfile(int fd)
{
	t_gnl	*file;

	file = malloc(sizeof(t_gnl));
	if (!file)
		return (NULL);
	file->fd = fd;
	file->read = 0;
	file->line = 0;
	file->next = NULL;
	return (file);
}

t_gnl			*selectfile(int fd)
{
	static t_gnl	*start = NULL;
	t_gnl			*file;
	t_gnl			*tool;

	if (start == NULL)
	{
		file = initfile(fd);
		start = file;
		return (file);
	}
	file = start;
	while (file)
	{
		if (file->fd == fd)
			return (file);
		file = file->next;
	}
	tool = initfile(fd);
	file = start;
	while (file->next)
		file = file->next;
	file->next = tool;
	return (file->next);
}

void			search_line(t_gnl *file, char **line)
{
	int i;
	int pos;

	i = 0;
	pos = 0;
	if (file->line == 1 && file->content[0] != '\0')
		file->content = &(file->content[1]);
	file->line = 1;
	while (file->content[pos] != '\n' && file->content[pos] != '\0')
		pos++;
	line[0] = malloc(sizeof(char) * (pos + 1));
	while (file->content[i] != '\n' && file->content[i] != '\0')
	{
		line[0][i] = file->content[i];
		i++;
	}
	line[0][i] = '\0';
	file->content = &(file->content[i]);
}

char			*file_allocat(char *file, char *buf)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = malloc(sizeof(char) * (ft_strlen(buf) + ft_strlen(file)) + 1);
	if (!tmp)
		return (NULL);
	while (file[i] == file[j] && file[j] != '\0')
	{
		tmp[j] = file[i];
		i++;
		j++;
	}
	i = 0;
	while (buf[i] != '\0')
	{
		tmp[j] = buf[i];
		j++;
		i++;
	}
	tmp[j] = '\0';
	free(file);
	return (tmp);
}

int				get_next_line(const int fd, char **line)
{
	int				ret;
	t_gnl			*file;
	char			buf[BUFF_SIZE + 1];

	file = selectfile(fd);
	if (file->read == 0)
	{
		file->content = ft_strnew(1);
		while ((ret = read(file->fd, buf, BUFF_SIZE)) && ret != -1)
		{
			buf[ret] = '\0';
			file->content = file_allocat(file->content, buf);
		}
		if (ret == -1 || file->fd < 0 || line == NULL)
			return (-1);
		file->read = 1;
	}
	search_line(file, line);
	if (line[0][0] == '\0' && file->content[0] == '\0')
		return (0);
	return (1);
}
