/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <mlavanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 02:43:08 by mlavanan          #+#    #+#             */
/*   Updated: 2018/07/22 16:29:18 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/scop.h"

static void				fullfree(t_objdata *obj, float *points, t_gldata gl)
{
	free(points);
	free(obj);
	free(gl.shaderpointsg);
	free(gl.shaderpointsm);
	free(gl.textureancors);
}

static void				managebuffers(t_objdata *obj, t_gldata gl)
{
	glBindBuffer(GL_ARRAY_BUFFER, gl.points_vbo);
	glBufferData(GL_ARRAY_BUFFER, obj->nbpoints * sizeof(float), gl.dp, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glBindBuffer(GL_ARRAY_BUFFER, gl.colours_vbo);
	if (obj->shaderselect == 0)
		glBufferData(GL_ARRAY_BUFFER, obj->nbpoints * sizeof(float), gl.shaderpointsg, GL_STATIC_DRAW);
	else if (obj->shaderselect == 1)
		glBufferData(GL_ARRAY_BUFFER, obj->nbpoints * sizeof(float), gl.shaderpointsm, GL_STATIC_DRAW);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glBindBuffer(GL_ARRAY_BUFFER, gl.texture_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * obj->nbpoints, gl.textureancors, GL_STATIC_DRAW);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
}

static t_gldata			manageshader(t_gldata gl)
{
	gl.vertex_shader = createvshader();
	gl.fragment_shader = createfshader();
	gl.vertex_shadert = createvshadertext();
	gl.fragment_shadert = createfshadertext();
	glShaderSource(gl.vs, 1, &gl.vertex_shader, NULL);
	glCompileShader(gl.vs);
	glShaderSource(gl.fs, 1, &gl.fragment_shader, NULL);
	glCompileShader(gl.fs);
	glAttachShader(gl.shader_programme, gl.vs);
	glAttachShader(gl.shader_programme, gl.fs);
	glShaderSource(gl.vst, 1, &gl.vertex_shadert, NULL);
	glCompileShader(gl.vst);
	glShaderSource(gl.fst, 1, &gl.fragment_shadert, NULL);
	glCompileShader(gl.fst);
	glAttachShader(gl.shader_programmet, gl.vst);
	glAttachShader(gl.shader_programmet, gl.fst);
	glBindAttribLocation(gl.shader_programmet, 2, "vertexUV");
	glBindAttribLocation(gl.shader_programmet, 0, "vertex_position");
	glBindAttribLocation(gl.shader_programme, 1, "vertex_color");
	glBindAttribLocation(gl.shader_programme, 0, "vertex_position");
	glLinkProgram(gl.shader_programme);
	glLinkProgram(gl.shader_programmet);
	return (gl);
}

static float			*creatingpoints(t_objdata *obj)
{
	float	*points;
	int		i;

	points = malloc(sizeof(float) * (obj->nbpoints));
	i = 0;
	obj->faces = obj->facesstart;
	points = selectpoints(obj, points, i, 0);
	points = centerpoints(obj, points);
	return (points);
}

int						main(int argc, char **argv)
{
	float			*points;
	t_gldata		gld;
	t_contextdata	context;
	t_objdata		*obj;

	context = initcontext();
	if (context.error != 0)
		return (0);
	obj = initobj(argc, argv);
	if (obj->error != 0)
		return (0);
	points = creatingpoints(obj);
	gld = initgl(obj);
	while (!glfwWindowShouldClose(context.window))
	{
		points = rotate(points, obj);
		points = key_cb(context.window, obj, points);
		gld = perspective(obj, points, gld);
		managebuffers(obj, gld);
		gld = manageshader(gld);
		draw(obj, gld, context);
	}
	glfwTerminate();
	fullfree(obj, points, gld);
	return (0);
}
