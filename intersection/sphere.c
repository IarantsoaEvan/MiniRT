/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:40:48 by mrambelo          #+#    #+#             */
/*   Updated: 2025/01/22 13:32:37 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

void ft_set_abc_sphere(t_fct *fct,t_data *rt)
{
	t_coord *oc;
	float r;

	r = rt->sphere->diam / 2;
	oc = ft_soustraction(rt->cam->coord,rt->sphere->coord);
	fct->pol->a = 1;
	fct->pol->b = 2 * ft_scal(oc,fct->dir);
	fct->pol->c = ft_scal(oc,oc) - (r * r);
}
void intersec_sphere(t_fct *fct,t_data *rt)
{
    ft_set_abc_sphere(fct, rt);
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