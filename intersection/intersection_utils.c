/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:41:17 by mrambelo          #+#    #+#             */
/*   Updated: 2025/01/22 12:54:37 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

float	get_delta(t_pol *pol)
{
	float delta;

	delta = (pol->b * pol->b) - (4 * (pol->a * pol->c));
	return (delta);
}

float get_t_sphere(t_pol *pol, float delta)
{
	float	t1;
	float	t2;
	float	distance;

	distance = -1;

	if (delta == 0)
	{
		t1 = (pol->b * (-1)) / (2 * pol->a);
		return (t1);
	}
	else if (delta > 0)
	{
		t1 = (((-1) * pol->b) - (sqrt(delta))) / (2 * pol->a);
		t2 = (((-1) * pol->b) + (sqrt(delta))) / (2 * pol->a);
		if (t1 > 0)
			distance = t1;
		if (t2 > 0 && (t2 < t1))
			distance = t2;
		if (t2 > 0 && t1 < 0)
			distance = t2;
	}
	return (distance);

}

t_coord *normalize_vector(t_coord *coord)
{
	t_coord *norm_vec;
	float	magn;
	
	norm_vec = init_coord();
	norm_vec->x = coord->x;
	norm_vec->y = coord->y;
	norm_vec->z = coord->z;
	magn = sqrt((norm_vec->x * norm_vec->x) + (norm_vec->y *norm_vec->y) + (norm_vec->z * norm_vec->z));
	norm_vec->x /= magn;
	norm_vec->y /= magn;
	norm_vec->z /= magn;
	return (norm_vec);
}

void set_ray_direction(t_fct *fct, t_coord	*dir, t_camera *cam)
{	
	t_coord	*ort_y;
	t_coord *dir_norm;

	ort_y = init_coord();
	ort_y->y = 1;
	dir->x = fct->as_x - cam->coord->x;
	dir->y = fct->as_y - cam->coord->y;
	dir->z = fct->as_z - cam->coord->z;
	dir_norm = normalize_vector(dir);
	cam->cam_right = normalize_vector(ft_cross_product(dir_norm, ort_y));
	cam->cam_up = normalize_vector(ft_cross_product(dir_norm, cam->cam_right));
}
float ft_scal(t_coord *vect1,t_coord *vect2)
{
	float res;

	res = (vect1->x * vect2->x) + (vect1->y * vect2->y) + (vect1->z * vect2->z);
	return (res);
}

t_coord *ft_soustraction(t_coord *coord1,t_coord *coord2)
{
	t_coord *oc;

	oc = init_coord();
	oc->x = coord1->x - coord2->x;
	oc->y = coord1->y - coord2->y;
	oc->z = coord1->z - coord2->z;
	return(oc);
}

t_coord *ft_cross_product(t_coord *v1, t_coord *v2)
{
	t_coord	*v3;

	v3 = init_coord();
	v3->x = (v1->y * v2->z) - (v1->z * v2->y);
	v3->y = (v1->z * v2->x) - (v1->x * v2->z);
	v3->z = (v1->x * v2->y) - (v1->y * v2->x);
	return (v3);
}

t_coord	*ft_scal_one(t_coord *v1, float one)
{
	t_coord	*prod;

	prod = init_coord();
	prod->x = one * v1->x;
	prod->y = one * v1->y;
	prod->z = one * v1->z;
	free(v1);
	return (prod);
}

t_coord	*vect_add(t_coord	*v1, t_coord *v2)
{
	t_coord	*v3;

	v3 = init_coord();
	v3->x = v1->x + v2->x;
	v3->y = v1->y + v2->y;
	v3->z = v1->z + v2->z;
	return (v3);
}
t_coord	*real_ray_dir(t_fct *fct, t_camera *cam)
{
	t_coord	*tmp;


	fct->ort_y->y = 1;
	fct->cam_ort = normalize_vector(cam->vector);
	cam->cam_right = normalize_vector(ft_cross_product(cam_ort, ort_y));

	cam->cam_up = normalize_vector(ft_cross_product(cam_ort, cam->cam_right));

	cam->cam_right = ft_scal_one(cam->cam_right, ((-1) * (fct->as_x)));
	cam->cam_up = ft_scal_one(cam->cam_up, ((-1) * (fct->as_y)));
	tmp = vect_add(cam->cam_right, cam->cam_up);
	fct->add = vect_add(tmp, fct->cam_ort);
	free(tmp);
	return (fct->add);
}
