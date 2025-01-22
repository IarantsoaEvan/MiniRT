/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:41:17 by mrambelo          #+#    #+#             */
/*   Updated: 2025/01/22 08:52:21 by mrambelo         ###   ########.fr       */
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

void normalize_vector(t_coord *coord)
{
	float	magn;
	
	magn = sqrt((coord->x * coord->x) + (coord->y *coord->y) + (coord->z * coord->z));
	coord->x /= magn;
	coord->y /= magn;
	coord->z /= magn;
}

void set_direction(t_fct *fct, t_coord	*dir,t_camera *cam)
{
	// float	magn;
	
	dir->x = fct->as_x - cam->coord->x;
	dir->y = fct->as_y - cam->coord->y;
	dir->z = fct->as_z - cam->coord->z;
	normalize_vector(dir);
	// magn = sqrt((dir->x * dir->x) + (dir->y *dir->y) + (dir->z * dir->z));
	// dir->x /= magn;
	// dir->y /= magn;
	// dir->z /= magn;
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

