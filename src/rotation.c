/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <mlavanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 04:54:38 by mlavanan          #+#    #+#             */
/*   Updated: 2018/07/22 16:22:55 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/scop.h"

static t_matrix		createunitarymatrix(void)
{
	t_matrix uni;

	uni.x = 0.0f;
	uni.y = 1.0f;
	uni.z = 0.0f;
	uni.w = 1.0f;
	uni.c = cos(0.02);
	uni.s = sin(0.02);
	return (uni);
}

static void			freemat(float **mat)
{
	free(mat[0]);
	free(mat[1]);
	free(mat[2]);
	free(mat);
}

static float		**matriceset(t_matrix u, float x, float y, float z)
{
	float	**matrice;

	matrice = (float**)malloc(sizeof(float *) * 3);
	matrice[0] = (float *)malloc(sizeof(float) * 3);
	matrice[1] = (float *)malloc(sizeof(float) * 3);
	matrice[2] = (float *)malloc(sizeof(float) * 3);
	matrice[0][0] = u.x2 + (1 - u.x2) * u.c;
	matrice[0][1] = u.x * u.y * (1 - u.c) - u.z * u.s;
	matrice[0][2] = u.x * u.z * (1 - u.c) + u.y * u.s;
	matrice[1][0] = u.x * u.y * (1 - u.c) + u.z * u.s;
	matrice[1][1] = u.y2 + (1 - u.y2) * u.c;
	matrice[1][2] = u.y * u.z * (1 - u.c) - u.x * u.s;
	matrice[2][0] = u.x * u.y * (1 - u.c) - u.y * u.s;
	matrice[2][1] = u.y * u.z * (1 - u.c) + u.x * u.s;
	matrice[2][2] = u.z2 + (1 - u.z2) * u.c;
	matrice[0][0] *= x;
	matrice[1][0] *= x;
	matrice[2][0] *= x;
	matrice[0][1] *= y;
	matrice[1][1] *= y;
	matrice[2][1] *= y;
	matrice[0][2] *= z;
	matrice[1][2] *= z;
	matrice[2][2] *= z;
	return (matrice);
}

static float		*rotateloop(float *points, t_objdata *obj, t_matrix u)
{
	int		i;
	float	x;
	float	y;
	float	z;
	float	**matrice;

	i = 0;
	while (i + 2 < obj->nbpoints)
	{
		x = points[i];
		i++;
		y = points[i];
		i++;
		z = points[i];
		u.x2 = u.x * u.x;
		u.y2 = u.y * u.y;
		u.z2 = u.z * u.z;
		matrice = matriceset(u, x, y, z);
		points[i - 2] = matrice[0][0] + matrice[0][1] + matrice[0][2];
		points[i - 1] = matrice[1][0] + matrice[1][1] + matrice[1][2];
		points[i] = matrice[2][0] + matrice[2][1] + matrice[2][2];
		i++;
		freemat(matrice);
	}
	return (points);
}

float				*rotate(float *points, t_objdata *obj)
{
	t_matrix unitmat;

	unitmat = createunitarymatrix();
	if (obj->rotating == 1)
		return (rotateloop(points, obj, unitmat));
	else
		return (points);
}
