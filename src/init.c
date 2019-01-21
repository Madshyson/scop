/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <mlavanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 00:34:42 by mlavanan          #+#    #+#             */
/*   Updated: 2018/07/22 16:14:27 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/scop.h"

t_gldata				initgl(t_objdata *obj)
{
	t_gldata gl;

	gl.shaderpointsg = createshadergreyfaces(obj);
	gl.shaderpointsm = createshadermulticolor(obj);
	gl.textureancors = createtextureancor(obj);
	gl.colours_vbo = 0;
	glGenBuffers(1, &gl.colours_vbo);
	gl.points_vbo = 0;
	glGenBuffers(1, &gl.points_vbo);
	gl.texture_vbo = 0;
	glGenBuffers(1, &gl.texture_vbo);
	gl.textid = loadbmp_custom("./textures/mlp2.bmp");
	gl.vao = 0;
	glGenVertexArrays(1, &gl.vao);
	glBindVertexArray(gl.vao);
	gl.vs = glCreateShader(GL_VERTEX_SHADER);
	gl.fs = glCreateShader(GL_FRAGMENT_SHADER);
	gl.shader_programme = glCreateProgram();
	gl.vst = glCreateShader(GL_VERTEX_SHADER);
	gl.fst = glCreateShader(GL_FRAGMENT_SHADER);
	gl.shader_programmet = glCreateProgram();
	return (gl);
}

t_objdata				*initobj(int ac, char **av)
{
	t_objdata *obj;

	obj = malloc(sizeof(t_objdata));
	obj->error = 0;
	obj->nbvertices = 0;
	obj->nbfaces = 0;
	obj->nbpoints = 0;
	obj->vertices = NULL;
	obj->faces = NULL;
	obj->drawmode = 0;
	obj->shaderselect = 0;
	obj->rotating = 1;
	obj->texturing = 0;
	obj->keypress = 0;
	obj->decx = 0.0f;
	obj->decy = 0.0f;
	obj = dataparser(ac, av, obj);
	return (obj);
}

static GLFWwindow		*createwin(void)
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	return (glfwCreateWindow(1500, 1500, "SCOP", NULL, NULL));
}

t_contextdata			initcontext(void)
{
	t_contextdata context;

	if (!glfwInit())
	{
		fprintf(stderr, "ERROR: could not start GLFW3\n");
		context.error = 1;
		return (context);
	}
	context.window = createwin();
	if (!context.window)
	{
		fprintf(stderr, "ERROR: could not open window with GLFW3\n");
		glfwTerminate();
		context.error = 1;
		return (context);
	}
	glfwMakeContextCurrent(context.window);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	context.error = 0;
	return (context);
}
