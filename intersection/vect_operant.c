/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_operant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:31:27 by mrambelo          #+#    #+#             */
/*   Updated: 2025/01/27 14:12:17 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

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

t_coord *ft_addition(t_coord *coord1,t_coord *coord2)
{
	t_coord *oc;

	oc = init_coord();
	oc->x = coord1->x + coord2->x;
	oc->y = coord1->y + coord2->y;
	oc->z = coord1->z + coord2->z;
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