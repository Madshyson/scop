/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <mlavanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 00:48:38 by mlavanan          #+#    #+#             */
/*   Updated: 2018/07/21 21:07:34 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/scop.h"

static t_objdata	*movex(t_objdata *obj, int dir)
{
	obj->decx += 0.04f * dir;
	return (obj);
}

static t_objdata	*movey(t_objdata *obj, int dir)
{
	obj->decy += 0.04f * dir;
	return (obj);
}

static float		*movez(float *points, t_objdata *obj, int dir)
{
	int i;

	i = 0;
	while (i <= obj->nbpoints)
	{
		if (dir == -1)
			points[i] *= 0.99009f;
		if (dir == 1)
			points[i] *= 1.01f;
		i++;
	}
	return (points);
}

static t_objdata	*keyh(GLFWwindow *win, t_objdata *obj)
{
	if (glfwGetKey(win, GLFW_KEY_O) == GLFW_PRESS)
	{
		obj->shaderselect = (obj->shaderselect + 1) % 2;
		obj->keypress = 1;
	}
	if (glfwGetKey(win, GLFW_KEY_R) == GLFW_PRESS)
	{
		obj->rotating = (obj->rotating + 1) % 2;
		obj->keypress = 1;
	}
	if (glfwGetKey(win, GLFW_KEY_P) == GLFW_PRESS)
	{
		obj->drawmode = (obj->drawmode + 1) % 2;
		obj->keypress = 1;
	}
	if (glfwGetKey(win, GLFW_KEY_D) == GLFW_PRESS)
	{
		obj->texturing = (obj->texturing + 1) % 2;
		obj->keypress = 1;
	}
	return (obj);
}

float				*key_cb(GLFWwindow *win, t_objdata *obj, float *points)
{
	if (glfwGetKey(win, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(win, GL_TRUE);
	if (setkeyhook(win) == 1)
		obj->keypress = 0;
	if (glfwGetKey(win, GLFW_KEY_LEFT) == GLFW_PRESS)
		obj = movex(obj, -1);
	if (glfwGetKey(win, GLFW_KEY_DOWN) == GLFW_PRESS)
		obj = movey(obj, -1);
	if (glfwGetKey(win, GLFW_KEY_KP_SUBTRACT) == GLFW_PRESS)
		points = movez(points, obj, -1);
	if (glfwGetKey(win, GLFW_KEY_RIGHT) == GLFW_PRESS)
		obj = movex(obj, 1);
	if (glfwGetKey(win, GLFW_KEY_UP) == GLFW_PRESS)
		obj = movey(obj, 1);
	if (glfwGetKey(win, GLFW_KEY_KP_ADD) == GLFW_PRESS)
		points = movez(points, obj, 1);
	if (obj->keypress != 1)
		obj = keyh(win, obj);
	return (points);
}
