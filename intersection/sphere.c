/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:40:48 by mrambelo          #+#    #+#             */
/*   Updated: 2025/01/23 09:18:19 by mrambelo         ###   ########.fr       */
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
void intersec_sphere(t_fct *fct,t_data *rt,float x,float y)
{
    t_sphere *tmp;
	float t;

	tmp = rt->sphere;
	while (tmp)
	{
		ft_set_abc_sphere(fct, rt);
		// intersec_sphere(fct,rt);
		t = get_t_sphere(fct->pol, get_delta(fct->pol));
		if (t > 0)
				mlx_pixel_put(rt->mlx_ptr, rt->win_ptr, (int)x, (int)y, 0x45FF0B);
		tmp = tmp->next;
	}
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
		distance = fminf(t1, t2);
		if (distance < 0)
			distance = -1;
	}
	return (distance);

}