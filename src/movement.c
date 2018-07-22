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

static float	*movex(float *points, t_objdata *obj, int dir)
{
	int i;

	i = 0;
	while (i <= obj->nbpoints)
	{
		if (i % 3 == 0)
		{
			points[i] += 0.01f * dir;
		}
		i++;
	}
	return (points);
}

static float	*movey(float *points, t_objdata *obj, int dir)
{
	int i;

	i = 0;
	while (i <= obj->nbpoints)
	{
		if (i % 3 == 1)
		{
			points[i] += 0.01f * dir;
		}
		i++;
	}
	return (points);
}

static float	*movez(float *points, t_objdata *obj, int dir)
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

float			*key_cb(GLFWwindow *win, t_objdata *obj, float *points)
{
	if (glfwGetKey(win, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(win, GL_TRUE);
	if (glfwGetKey(win, GLFW_KEY_LEFT) == GLFW_PRESS)
		points = movex(points, obj, -1);
	if (glfwGetKey(win, GLFW_KEY_DOWN) == GLFW_PRESS)
		points = movey(points, obj, -1);
	if (glfwGetKey(win, GLFW_KEY_KP_SUBTRACT) == GLFW_PRESS)
		points = movez(points, obj, -1);
	if (glfwGetKey(win, GLFW_KEY_RIGHT) == GLFW_PRESS)
		points = movex(points, obj, 1);
	if (glfwGetKey(win, GLFW_KEY_UP) == GLFW_PRESS)
		points = movey(points, obj, 1);
	if (glfwGetKey(win, GLFW_KEY_KP_ADD) == GLFW_PRESS)
		points = movez(points, obj, 1);
	if (glfwGetKey(win, GLFW_KEY_O) == GLFW_PRESS)
		obj->shaderselect = (obj->shaderselect + 1) % 2;
	if (glfwGetKey(win, GLFW_KEY_R) == GLFW_PRESS)
		obj->rotating = (obj->rotating + 1) % 2;
	if (glfwGetKey(win, GLFW_KEY_P) == GLFW_PRESS)
		obj->drawmode = (obj->drawmode + 1) % 2;
	if (glfwGetKey(win, GLFW_KEY_D) == GLFW_PRESS)
		obj->texturing = (obj->texturing + 1) % 2;
	return (points);
}
