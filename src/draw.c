/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <mlavanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 15:49:08 by mlavanan          #+#    #+#             */
/*   Updated: 2018/07/22 16:34:00 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/scop.h"

float			*centerpoints(t_objdata *obj, float *points)
{
	int		i;
	float	limitmax;
	float	limitmin;

	i = 2;
	limitmin = 0;
	limitmax = 0;
	while (i + 3 < obj->nbpoints)
	{
		if (points[i] < limitmin)
			limitmin = points[i];
		if (points[i] > limitmax)
			limitmax = points[i];
		i += 3;
	}
	printf("centering : %f / %f\n", limitmin, limitmax);
	i = 2;
	while (i < obj->nbpoints)
	{
		points[i] -= (limitmin + limitmax) / 2;
		i += 3;
	}
	return (points);
}

float			*selectpoints(t_objdata *obj, float *pt, int i, int j)
{
	int pointcount;

	pointcount = 0;
	while (obj->faces)
	{
		j = 0;
		while (obj->faces->face[j] != 0 && j < 3)
		{
			obj->vertices = obj->verticesstart;
			while (i + 1 < obj->faces->face[j])
			{
				obj->vertices = obj->vertices->next;
				i++;
			}
			pt[pointcount] = obj->vertices->vertice[0];
			pt[pointcount + 1] = obj->vertices->vertice[1];
			pt[pointcount + 2] = obj->vertices->vertice[2];
			pointcount += 3;
			i = 0;
			j++;
		}
		obj->faces = obj->faces->next;
	}
	return (pt);
}

t_gldata		perspective(t_objdata *obj, float *pt, t_gldata gl)
{
	int i;

	i = 0;
	gl.dp = malloc(sizeof(float) * obj->nbpoints);
	while (i + 2 < obj->nbpoints)
	{
		i++;
		i++;
		if (pt[i] < 0.0)
		{
			gl.dp[i] = pt[i] * (1 + ((-1 * pt[i]) / 5));
			gl.dp[i - 1] = (pt[i - 1] + obj->decy) * (1 + ((-1 * pt[i]) / 5));
			gl.dp[i - 2] = (pt[i - 2] + obj->decx) * (1 + ((-1 * pt[i]) / 5));
		}
		else
		{
			gl.dp[i] = pt[i] * (1 / (1 + ((pt[i]) / 5)));
			gl.dp[i - 1] = (pt[i - 1] + obj->decy) * (1 / (1 + ((pt[i]) / 5)));
			gl.dp[i - 2] = (pt[i - 2] + obj->decx) * (1 / (1 + ((pt[i]) / 5)));
		}
		i++;
	}
	return (gl);
}

void			draw(t_objdata *obj, t_gldata gl, t_contextdata ct)
{
	glDisable(GL_CULL_FACE);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if (obj->texturing == 0)
		glUseProgram(gl.shader_programme);
	else if (obj->texturing == 1)
		glUseProgram(gl.shader_programmet);
	glBindVertexArray(gl.vao);
	if (obj->drawmode == 0)
		glDrawArrays(GL_TRIANGLES, 0, obj->nbpoints / 3);
	else if (obj->drawmode == 1)
		glDrawArrays(GL_LINES, 0, obj->nbpoints / 3);
	glEnable(GL_CULL_FACE);
	if (obj->drawmode == 0)
		glDrawArrays(GL_TRIANGLES, 0, obj->nbpoints / 3);
	else if (obj->drawmode == 1)
		glDrawArrays(GL_LINES, 0, obj->nbpoints / 3);
	glfwPollEvents();
	glBindTexture(GL_TEXTURE_2D, gl.textid);
	glfwSwapBuffers(ct.window);
	glBindTexture(gl.textid, 0);
	free(gl.dp);
}
