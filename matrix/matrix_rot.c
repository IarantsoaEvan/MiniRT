/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:33:33 by irabesan          #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

void	rot_foll_x(t_coord *rot, float alpha)
{
	float tmp;

	tmp = rot->y;
	// printf("Avant rot->y = %f\n",rot->y);
	// printf("Avant rot->z = %f\n\n",rot->z);
	rot->y = tmp * cos(alpha) + rot->z * sin(alpha);
	rot->z = -(tmp) * sin(alpha) + rot->z * cos(alpha);
	// printf("Apres rot->y = %f\n",rot->y);
	// printf("Apres rot->z = %f\n\n",rot->z);
}

void	rot_foll_y(t_coord *rot, float beta)
{
	float	tmp;

	tmp = rot->x;
	
	printf("beta = %f\n",beta);
	rot->x = tmp * cos(beta) + rot->z * sin(beta);
	rot->z = -(tmp) * sin(beta) + rot->z * cos(beta);
	// printf("beta = %f\n",beta);
	// printf("beta = %f\n",beta);
	rot->x = tmp * cos(beta) + rot->z * sin(beta);
	rot->z = -(tmp) * sin(beta) + rot->z * cos(beta);
}

void	rot_foll_z(t_coord *rot, float teta)
{
	float	tmp;

	printf("teta = %f\n",teta);
	tmp = rot->x;
	// printf("Avnat rot->x = %f\n",rot->x);
	// printf("Avnat rot->y = %f\n\n",rot->y);
	rot->x = tmp * cos(teta) - rot->y * sin(teta);
	rot->y = tmp * sin(teta) + rot->y * cos(teta);
// 	printf("Apres rot->x = %f\n",rot->x);
// 	printf("Apres rot->y = %f\n\n",rot->y);
}