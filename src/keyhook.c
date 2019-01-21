/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <mlavanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 00:48:38 by mlavanan          #+#    #+#             */
/*   Updated: 2018/07/21 21:07:34 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/scop.h"

int		setkeyhook(GLFWwindow *win)
{
	if (glfwGetKey(win, GLFW_KEY_O) == GLFW_RELEASE)
	{
		if (glfwGetKey(win, GLFW_KEY_R) == GLFW_RELEASE)
		{
			if (glfwGetKey(win, GLFW_KEY_P) == GLFW_RELEASE)
			{
				if (glfwGetKey(win, GLFW_KEY_D) == GLFW_RELEASE)
				{
					return (1);
				}
			}
		}
	}
	return (0);
}
