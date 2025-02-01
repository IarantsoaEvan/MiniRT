/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:41:17 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/01 21:09:12 by mrambelo         ###   ########.fr       */
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
	t_coord	*cam_ort;
	t_coord *up;
	t_coord *right;
	t_coord	*ort_y;

	ort_y = init_coord();
	cam_ort = normalize_vector(cam->vector);
	if (cam_ort->y == 1 && !cam_ort->x && !cam_ort->z)
		ort_y->z = -1;
	else
		ort_y->y = 1;
	cam->cam_right = normalize_vector_with_free(ft_cross_product(cam_ort, ort_y));
	cam->cam_up = normalize_vector_with_free(ft_cross_product(cam_ort, cam->cam_right));
	right = ft_scal_one(cam->cam_right, ((-1) * (fct->as_x)));
	up = ft_scal_one(cam->cam_up, ((-1) * (fct->as_y)));
	tmp = vect_add(right, up);
	fct->dir = normalize_vector_with_free(vect_add(tmp, cam_ort));
	free(tmp);
	free(cam_ort);
	free(ort_y);
	free(right);
	free(up);
	free(cam->cam_right);
	free(cam->cam_up);
}
