/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <mlavanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 02:35:14 by mlavanan          #+#    #+#             */
/*   Updated: 2018/07/22 16:34:47 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H

# define SCOP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <math.h>
# include <fcntl.h>
# include <time.h>

# include "../lib/libft/libft.h"
# define GLFW_INCLUDE_GLCOREARB
# define BUFF 1024
# include "../lib/glfw/include/GLFW/glfw3.h"

typedef struct			s_vlist
{
	float				vertice[3];
	struct s_vlist		*next;
}						t_vlist;

typedef struct			s_flist
{
	int					face[3];
	struct s_flist		*next;
}						t_flist;

typedef struct			s_objdata
{
	char				*filename;
	int					nbvertices;
	int					nbfaces;
	int					nbpoints;
	t_vlist				*verticesstart;
	t_flist				*facesstart;
	t_vlist				*vertices;
	t_flist				*faces;
	int					error;
	float				decx;
	float				decy;
	int					drawmode;
	int					shaderselect;
	int					rotating;
	int					texturing;
	int					keypress;
}						t_objdata;

typedef struct			s_matrix
{
	float				x;
	float				x2;
	float				y;
	float				y2;
	float				z;
	float				z2;
	float				w;
	float				c;
	float				s;
}						t_matrix;

typedef struct			s_contextdata
{
	GLFWwindow			*window;
	int					error;
}						t_contextdata;

typedef struct			s_texturedata
{
	unsigned char		header[54];
	unsigned int		datapos;
	unsigned int		width;
	unsigned int		height;
	unsigned int		imagesize;
	unsigned char		*data;
	GLuint				textureid;
	FILE				*file;
}						t_texturedata;

typedef struct			s_gldata
{
	GLuint				colours_vbo;
	GLuint				points_vbo;
	GLuint				texture_vbo;
	GLuint				textid;
	GLuint				vao;
	GLuint				vs;
	GLuint				fs;
	GLuint				shader_programme;
	GLuint				vst;
	GLuint				fst;
	GLuint				shader_programmet;
	const char			*vertex_shader;
	const char			*fragment_shader;
	const char			*vertex_shadert;
	const char			*fragment_shadert;
	float				*shaderpointsm;
	float				*shaderpointsg;
	float				*textureancors;
	float				*dp;
}						t_gldata;

t_objdata				*initobj(int ac, char **av);
t_contextdata			initcontext();
t_objdata				*dataparser(int ac, char **av, t_objdata *obj);
t_objdata				*setfaces(t_objdata *obj, char *line);
t_objdata				*setvertices(t_objdata *obj, char *line);
float					*rotate(float *points, t_objdata *obj);
float					*key_cb(GLFWwindow *win, t_objdata *obj, float *points);
float					*createshadermulticolor(t_objdata *obj);
float					*createshadergreyfaces(t_objdata *obj);
float					*createtextureancor(t_objdata *obj);
char					*createfshadertext(void);
char					*createvshadertext(void);
char					*createfshader(void);
char					*createvshader(void);
GLuint					loadbmp_custom(const char *imagepath);
int						main(int argc, char **argv);
t_objdata				*seterror(int errorval, t_objdata *obj);
int						testgoodfile(char *fn);
void					facealloc(t_flist *f, t_objdata *obj);
void					verticalloc(t_vlist *v, t_objdata *obj);
t_gldata				initgl(t_objdata *obj);
t_gldata				perspective(t_objdata *obj, float *pt, t_gldata gl);
void					draw(t_objdata *obj, t_gldata gl, t_contextdata ct);
float					*selectpoints(t_objdata *obj, float *pt, int i, int j);
float					*centerpoints(t_objdata *obj, float *points);
int						setkeyhook(GLFWwindow *win);

#endif
