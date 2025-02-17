/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_operant2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 08:38:25 by irabesan          #+#    #+#             */
/*   Updated: 2025/02/17 08:44:06 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

void	free_cam_ur(t_camera *cam, t_coord *cam_ort)
{
	free(cam_ort);
	free(cam->cam_right);
	free(cam->cam_up);
}

t_coord	*ft_addition(t_coord *coord1, t_coord *coord2)
{
	t_coord	*oc;

	oc = init_coord();
	oc->x = coord1->x + coord2->x;
	oc->y = coord1->y + coord2->y;
	oc->z = coord1->z + coord2->z;
	free(coord2);
	return (oc);
}

t_coord	*ft_cross_product(t_coord *v1, t_coord *v2)
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
	return (prod);
}

t_coord	*vect_add(t_coord *v1, t_coord *v2)
{
	t_coord	*v3;

	v3 = init_coord();
	v3->x = v1->x + v2->x;
	v3->y = v1->y + v2->y;
	v3->z = v1->z + v2->z;
	return (v3);
}
