/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shaders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <mlavanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 02:46:23 by mlavanan          #+#    #+#             */
/*   Updated: 2018/07/21 22:42:44 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/scop.h"

float					*createtextureancor(t_objdata *obj)
{
	int		i;
	float	*textureanc;

	i = 0;
	textureanc = malloc(sizeof(float) * obj->nbpoints);
	while (i < obj->nbpoints)
	{
		if (i % 12 == 0)
			textureanc[i] = 1.0;
		if (i % 12 == 1 || i % 12 == 2 || i % 12 == 6 || i % 12 == 9)
			textureanc[i] = 0.0;
		if (i % 12 == 3)
			textureanc[i] = 1.0;
		if (i % 12 == 4)
			textureanc[i] = 1.0;
		if (i % 12 == 5)
			textureanc[i] = 1.0;
		if (i % 12 == 7 || i % 12 == 8 || i % 12 == 10 || i % 12 == 11)
			textureanc[i] = 1.0;
		i++;
	}
	return (textureanc);
}

float					*createshadermulticolor(t_objdata *obj)
{
	int		i;
	float	*shaderpoints;
	float	randn;

	i = 0;
	shaderpoints = malloc(obj->nbpoints * sizeof(float));
	srand(time(NULL));
	while (i <= obj->nbpoints)
	{
		randn = (((rand() % 7) + 2) / 10.0);
		randn += ((rand() % 200) / 1000.0);
		shaderpoints[i] = randn;
		i++;
	}
	return (shaderpoints);
}

float					*createshadergreyfaces(t_objdata *obj)
{
	int		i;
	float	*shaderpoints;
	float	randn;

	i = 0;
	shaderpoints = malloc(obj->nbpoints * sizeof(float));
	srand(time(NULL));
	while (i <= obj->nbpoints)
	{
		if (i % 9 == 0)
		{
			randn = (((rand() % 6) + 2) / 10.0);
			randn += ((rand() % 200) / 1000.0);
		}
		shaderpoints[i] = randn;
		i++;
	}
	return (shaderpoints);
}

static t_texturedata	fdatatexture(t_texturedata t)
{
	t.datapos = *(int*)&(t.header[0x0A]);
	t.imagesize = *(int*)&(t.header[0x22]);
	t.width = *(int*)&(t.header[0x12]);
	t.height = *(int*)&(t.header[0x16]);
	return (t);
}

GLuint					loadbmp_custom(const char *imagepath)
{
	t_texturedata t;

	t.file = fopen(imagepath, "rb");
	if (!t.file)
		return (0);
	if (fread(t.header, 1, 54, t.file) != 54)
		return (0);
	if (t.header[0] != 'B' || t.header[1] != 'M')
		return (0);
	t = fdatatexture(t);
	if (t.imagesize == 0)
		t.imagesize = t.width * t.height * 3;
	if (t.datapos == 0)
		t.datapos = 54;
	t.data = malloc(sizeof(unsigned char) * t.imagesize);
	fread(t.data, 1, t.imagesize, t.file);
	fclose(t.file);
	glGenTextures(1, &t.textureid);
	glBindTexture(GL_TEXTURE_2D, t.textureid);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, t.width, t.height, 0, GL_BGR, GL_UNSIGNED_BYTE, t.data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	free(t.data);
	return (t.textureid);
}
