/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:04:58 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/17 11:11:46 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

float	get_t_plane(t_coord *direction, t_coord *origin, t_plane *plane)
{
	t_coord	*xc;
	t_coord	*norm;
	float	t;

	xc = ft_soustraction(origin, plane->coord);
	norm = normalize_vector(plane->vector);
	t = ((-1) * (ft_scal(xc, norm))) / ft_scal(direction, norm);
	free(xc);
	free(norm);
	return (t);
}

void	init_current_pl(t_nearest *pl_current, t_plane *plane)
{
	pl_current->near_obj = plane;
	pl_current->type = PLANE;
	pl_current->id = plane->id;
}

void	aply_color_pl(t_fct *fct, t_rgb *rgb, t_data *rt, t_plane *plane)
{
	float		scal_nl;
	t_color		*spec;
	t_nearest	pl_current;

	init_current_pl(&pl_current, plane);
	spec = init_color();
	scal_nl = ft_scal(plane->vector, rt->light->normal);
	if (rt->flag_spec)
	{
		if (spec)
			free(spec);
		spec = get_specular(rt, &pl_current, rgb->point, fct);
	}
	if (scal_nl < 0)
		rgb->rgb_finale = apply_shadow_color(rgb->color);
	else
		rgb->rgb_finale = add_amb_and_diff(rgb->color, rgb->rgb_diff, spec);
	if (rgb->flag == SHADOW)
	{
		if (rgb->rgb_finale)
			free(rgb->rgb_finale);
		rgb->rgb_finale = apply_shadow_color(rgb->color);
	}
	free(spec);
}

int	create_plane_rgb_finale(float t, t_fct *fct, t_data *rt, t_plane *plane)
{
	t_rgb		rgb;
	t_nearest	pl_current;

	init_current_pl(&pl_current, plane);
	rgb.point = ft_addition(rt->cam->coord, ft_scal_one(fct->dir, t));
	rgb.flag = NO_SHADOW;
	rgb.color = apply_amb(plane->color, rt->ambiante->ratio);
	rgb.flag = ray_shadowing(rt, rgb.point, &pl_current);
	rt->light->normal = get_normal_light(rt, rgb.point);
	rgb.rgb_diff = get_rgb_diff(plane->vector, rt->light->normal,
			rt->light->ratio, plane->color);
	aply_color_pl(fct, &rgb, rt, plane);
	rgb.rgb = create_trgb(rgb.rgb_finale->r, rgb.rgb_finale->g,
			rgb.rgb_finale->b);
	return (free(rt->light->normal), free_rgb(&rgb), rgb.rgb);
}

void	intersec_plane(t_fct *fct, t_data *rt, t_nearest *near)
{
	t_plane	*tmp;
	float	t;

	tmp = rt->plane;
	while (tmp)
	{
		t = get_t_plane(fct->dir, rt->cam->coord, tmp);
		if (t > 0 && t < near->t_near)
		{
			near->t_near = t;
			near->near_obj = tmp;
			near->type = PLANE;
		}
		tmp = tmp->next;
	}
}
