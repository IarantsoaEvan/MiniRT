/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:33:33 by irabesan          #+#    #+#             */
/*   Updated: 2025/02/10 19:22:44 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

void	rot_foll_x(t_coord *rot, float alpha)
{
	float tmp;

	tmp = rot->y;
	rot->y = tmp * cos(alpha) + rot->z * sin(alpha);
	rot->z = -(tmp) * sin(alpha) + rot->z * cos(alpha);
}

void	rot_foll_y(t_coord *rot, float beta)
{
	float	tmp;

	tmp = rot->x;
	
	rot->x = tmp * cos(beta) + rot->z * sin(beta);
	rot->z = -(tmp) * sin(beta) + rot->z * cos(beta);
	// printf("beta = %f\n",beta);
}

void	rot_foll_z(t_coord *rot, float teta)
{
	float	tmp;

	tmp = rot->x;
	rot->x = tmp * cos(teta) - rot->y * sin(teta);
	rot->y = tmp * sin(teta) + rot->y * cos(teta);
}