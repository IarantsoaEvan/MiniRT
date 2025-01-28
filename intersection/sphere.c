/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:40:48 by mrambelo          #+#    #+#             */
/*   Updated: 2025/01/28 09:46:27 by mrambelo         ###   ########.fr       */
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

int create_sphere_rgb_finale(float t,t_fct *fct,t_data *rt)
{
	t_coord *point;
	t_color *color;
	t_color *rgb_diff;
	t_color *rgb_finale;
	int rgb;
	
	point = ft_addition(rt->cam->coord,ft_scal_one(fct->dir, t));
	color = apply_amb(rt->sphere->color, rt->ambiante->ratio);
	rt->light->normal = get_normal_light(rt,point);
	rt->sphere->normal = get_normal_sphere(rt,point);
	rgb_diff = get_rgb_diff(rt->sphere->normal
		,rt->light->normal,rt->light->ratio,rt->sphere->color);
	rgb_finale = add_amb_and_diff(color,rgb_diff);
	rgb = create_trgb(rgb_finale->r, rgb_finale->g, rgb_finale->b);
	return (rgb);
}

void intersec_sphere(t_fct *fct,t_data *rt,float x,float y)
{
    t_sphere *tmp;
	int rgb;
	float t;

	rgb = 0;
	tmp = rt->sphere;
	while (tmp)
	{
		ft_set_abc_sphere(fct, rt);
		t = get_t_sphere(fct->pol, get_delta(fct->pol));
		if (t < rt->obj_nearest->t)
		{
			rt->obj_nearest->t = t;
			rt->obj_nearest->obj = tmp;
			rt->obj_nearest->type = SHPERE;
			// rgb = create_sphere_rgb_finale(t,fct,rt);
			// mlx_pixel_put(rt->mlx_ptr, rt->win_ptr, (int)x, (int)y, rgb);
		}
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
		if (t1 > 0 && t2 > 0)
			distance = fminf(t1, t2);
		else if (t1 > 0 && t2 < 0)
			distance = t1;
		else if (t1 < 0 && t2 > 0)
			distance = t2;		
	}
	return (distance);

}