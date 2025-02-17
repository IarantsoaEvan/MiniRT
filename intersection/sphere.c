/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:40:48 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/17 09:05:46 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

void	ft_set_abc_sphere(t_fct *fct, t_sphere *sphere, t_coord *origin)
{
	t_coord	*oc;
	float	r;

	r = sphere->diam / 2;
	oc = ft_soustraction(origin, sphere->coord);
	fct->pol->a = 1;
	fct->pol->b = 2 * ft_scal(oc, fct->dir);
	fct->pol->c = ft_scal(oc, oc) - (r * r);
	free(oc);
}

void	aply_color_sp(t_fct *fct, t_rgb *rgb, t_data *rt, t_sphere *sphere)
{
	float		scal_nl;
	t_color		*spec;
	t_nearest	sp_current;

	init_current_sp(&sp_current, sphere);
	spec = init_color();
	scal_nl = ft_scal(sphere->normal, rt->light->normal);
	if (rt->flag_spec)
	{
		if (spec)
			free(spec);
		spec = get_specular(rt, &sp_current, rgb->point, fct);
	}
	if (scal_nl < 0)
		rgb->rgb_finale = apply_shadow_color(rgb->color);
	else
		rgb->rgb_finale = add_amb_and_diff(rgb->color, rgb->rgb_diff, spec);
	if (rgb->flag == SHADOW && rt->light->ratio > 0.01)
	{
		if (rgb->rgb_finale)
			free(rgb->rgb_finale);
		rgb->rgb_finale = apply_shadow_color(rgb->color);
	}
}

int	create_sphere_rgb_finale(float t, t_fct *fct, t_data *rt, t_sphere *sphere)
{
	t_rgb		rgb;
	t_nearest	sp_current;

	init_current_sp(&sp_current, sphere);
	rgb.point = ft_addition(rt->cam->coord, ft_scal_one(fct->dir, t));
	rgb.flag = NO_SHADOW;
	rgb.color = apply_amb(sphere->color, rt->ambiante->ratio);
	rgb.flag = ray_shadowing(rt, rgb.point, &sp_current);
	rt->light->normal = get_normal_light(rt, rgb.point);
	sphere->normal = get_normal_sphere(rgb.point, sphere);
	rgb.rgb_diff = get_rgb_diff(sphere->normal, rt->light->normal,
			rt->light->ratio, sphere->color);
	aply_color_sp(fct, &rgb, rt, sphere);
	rgb.rgb = create_trgb(rgb.rgb_finale->r, rgb.rgb_finale->g,
			rgb.rgb_finale->b);
	free_rgb(&rgb);
	return (free(rt->light->normal), free(sphere->normal), rgb.rgb);
}

void	intersec_sphere(t_fct *fct, t_data *rt, t_nearest *near)
{
	t_sphere	*tmp;
	float		t;

	tmp = rt->sphere;
	while (tmp)
	{
		ft_set_abc_sphere(fct, tmp, rt->cam->coord);
		t = get_t_sphere(fct->pol, get_delta(fct->pol));
		if (t > 0 && t < near->t_near)
		{
			near->t_near = t;
			near->near_obj = tmp;
			near->type = SPHERE;
		}
		tmp = tmp->next;
	}
}

float	get_t_sphere(t_pol *pol, float delta)
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
		if (t1 > 0.001 && t2 > 0.001)
			distance = fminf(t1, t2);
		else if (t1 > 0.001 && t2 < 0.001)
			distance = t1;
		else if (t1 < 0.001 && t2 > 0.001)
			distance = t2;
	}
	return (distance);
}
