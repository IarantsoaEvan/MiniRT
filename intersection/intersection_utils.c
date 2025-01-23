/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:41:17 by mrambelo          #+#    #+#             */
/*   Updated: 2025/01/23 10:20:57 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

float	get_delta(t_pol *pol)
{
	float delta;

	delta = (pol->b * pol->b) - (4 * (pol->a * pol->c));
	return (delta);
}

void	real_ray_dir(t_fct *fct, t_camera *cam)
{
	t_coord	*tmp;


	fct->ort_y->y = 1;
	fct->cam_ort = normalize_vector(cam->vector);
	cam->cam_right = normalize_vector(ft_cross_product(fct->cam_ort, fct->ort_y));
	cam->cam_up = normalize_vector(ft_cross_product(fct->cam_ort, cam->cam_right));
	cam->cam_right = ft_scal_one(cam->cam_right, ((-1) * (fct->as_x)));
	cam->cam_up = ft_scal_one(cam->cam_up, ((-1) * (fct->as_y)));
	tmp = vect_add(cam->cam_right, cam->cam_up);
	fct->dir = normalize_vector(vect_add(tmp, fct->cam_ort));
	free(tmp);
}
