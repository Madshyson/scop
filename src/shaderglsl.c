/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shaderGLSL.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <mlavanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 22:55:27 by mlavanan          #+#    #+#             */
/*   Updated: 2018/07/21 23:11:40 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/scop.h"

char		*createfshadertext(void)
{
	char	*fshadert;

	fshadert = "#version 400\n"
	"in vec2 UV;"
	"out vec3 color;"
	"uniform sampler2D myTextureSampler;"
	"void main(){"
		"color = texture( myTextureSampler, UV ).rgb;"
	"}";
	return (fshadert);
}

char		*createvshadertext(void)
{
	char	*vshadert;

	vshadert = "#version 400\n"
	"layout(location = 0) in vec3 vertex_position;"
	"layout(location = 2) in vec2 vertexUV;"
	"out vec2 UV;"
	"void main(){"
		"gl_Position = vec4(vertex_position, 3.8);"
		"UV = vertexUV;"
	"}";
	return (vshadert);
}

char		*createfshader(void)
{
	char	*fshader;

	fshader = "#version 400\n"
	"in vec3 colour;"
	"out vec4 frag_colour;"
	"void main() {"
		"frag_colour = vec4(colour, 1.0);"
	"}";
	return (fshader);
}

char		*createvshader(void)
{
	char	*vshader;

	vshader = "#version 400\n"
	"layout(location = 0) in vec3 vertex_position;"
	"layout(location = 1) in vec3 vertex_colour;"
	"out vec3 colour;"
	"void main() {"
		"colour = vertex_colour;"
		"gl_Position = vec4(vertex_position, 3.8);"
	"}";
	return (vshader);
}
