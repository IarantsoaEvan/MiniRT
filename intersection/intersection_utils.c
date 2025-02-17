/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:41:17 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/17 09:15:31 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

void	init_current_cyl(t_nearest *cyl_current, t_cyl *cyl)
{
	cyl_current->near_obj = cyl;
	cyl_current->type = CYL;
	cyl_current->id = cyl->id;
}

float	get_delta(t_pol *pol)
{
	float	delta;

	delta = (pol->b * pol->b) - (4 * (pol->a * pol->c));
	return (delta);
}

void	real_ray_dir(t_fct *fct, t_camera *cam)
{
	t_coord	*tmp;
	t_coord	*cam_ort;
	t_coord	*up;
	t_coord	*right;
	t_coord	*ort_y;

	ort_y = init_coord();
	cam_ort = normalize_vector(cam->vector);
	if (cam_ort->y == 1 && !cam_ort->x && !cam_ort->z)
		ort_y->z = -1;
	else
		ort_y->y = 1;
	cam->cam_right = normalize_vector_with_free(ft_cross_product(cam_ort,
				ort_y));
	cam->cam_up = normalize_vector_with_free(ft_cross_product(cam_ort,
				cam->cam_right));
	right = ft_scal_one(cam->cam_right, ((-1) * (fct->as_x)));
	up = ft_scal_one(cam->cam_up, ((-1) * (fct->as_y)));
	tmp = vect_add(right, up);
	fct->dir = normalize_vector_with_free(vect_add(tmp, cam_ort));
	free(tmp);
	free(ort_y);
	free(right);
	free(up);
	free_cam_ur(cam, cam_ort);
}

float	get_m_scal(t_coord *dir, t_coord *origin, float t, t_cyl *cyl)
{
	t_coord	*norm_vec;
	t_coord	*x;

	norm_vec = normalize_vector(cyl->vector);
	x = ft_soustraction(origin, cyl->coord);
	cyl->m = (ft_scal(dir, norm_vec) * t) + ft_scal(x, norm_vec);
	free(norm_vec);
	free(x);
	return (cyl->m);
}

float	get_base_cyl(t_coord *dir, t_coord *origin, t_cyl *cyl, int check_pos)
{
	t_coord	*xc;
	t_coord	*norm;
	t_coord	*impact;
	t_coord	*disk_coord;
	float	t_disk;

	set_disk(cyl, check_pos);
	if (check_pos == 0)
	{
		xc = ft_soustraction(origin, cyl->disk_bot->coord);
		norm = normalize_vector(cyl->disk_bot->vector);
		disk_coord = cyl->disk_bot->coord;
	}
	else
	{
		xc = ft_soustraction(origin, cyl->disk_top->coord);
		norm = normalize_vector(cyl->disk_top->vector);
		disk_coord = cyl->disk_top->coord;
	}
	t_disk = ((-1) * (ft_scal(xc, norm))) / ft_scal(dir, norm);
	impact = ft_addition(origin, ft_scal_one(dir, t_disk));
	if (t_disk > 0.0001 && lenght_vector(ft_soustraction(impact,
				disk_coord)) <= cyl->diam / 2)
		return (free(impact), free(xc), free(norm), t_disk);
	return (free(impact), free(xc), free(norm), -1);
}
