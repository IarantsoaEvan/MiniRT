/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_operant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:31:27 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/17 08:43:05 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

float	lenght_vector(t_coord *vect)
{
	float	lenght;

	lenght = 0.0;
	lenght = sqrt(powf(vect->x, 2) + powf(vect->y, 2) + powf(vect->z, 2));
	free(vect);
	return (lenght);
}

t_coord	*normalize_vector(t_coord *coord)
{
	t_coord	*norm_vec;
	float	magn;

	norm_vec = init_coord();
	norm_vec->x = coord->x;
	norm_vec->y = coord->y;
	norm_vec->z = coord->z;
	magn = sqrt((norm_vec->x * norm_vec->x) + (norm_vec->y * norm_vec->y)
			+ (norm_vec->z * norm_vec->z));
	norm_vec->x /= magn;
	norm_vec->y /= magn;
	norm_vec->z /= magn;
	return (norm_vec);
}

t_coord	*normalize_vector_with_free(t_coord *coord)
{
	t_coord	*norm_vec;
	float	magn;

	norm_vec = init_coord();
	norm_vec->x = coord->x;
	norm_vec->y = coord->y;
	norm_vec->z = coord->z;
	magn = sqrt((norm_vec->x * norm_vec->x) + (norm_vec->y * norm_vec->y)
			+ (norm_vec->z * norm_vec->z));
	norm_vec->x /= magn;
	norm_vec->y /= magn;
	norm_vec->z /= magn;
	free(coord);
	return (norm_vec);
}

float	ft_scal(t_coord *vect1, t_coord *vect2)
{
	float	res;

	res = (vect1->x * vect2->x) + (vect1->y * vect2->y) + (vect1->z * vect2->z);
	return (res);
}

t_coord	*ft_soustraction(t_coord *coord1, t_coord *coord2)
{
	t_coord	*oc;

	oc = init_coord();
	oc->x = coord1->x - coord2->x;
	oc->y = coord1->y - coord2->y;
	oc->z = coord1->z - coord2->z;
	return (oc);
}
