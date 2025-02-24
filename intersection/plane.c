/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:04:58 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/24 09:10:11 by irabesan         ###   ########.fr       */
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

t_coord	*change_plane_vect(t_coord *plane_vect, t_coord *dir)
{
	t_coord	*tmp;

	if (ft_scal(dir, plane_vect) < 0)
		tmp = ft_scal_one(plane_vect, 1);
	else
		tmp = ft_scal_one(plane_vect, -1);
	return (tmp);
}

void	aply_color_pl(t_fct *fct, t_rgb *rgb, t_data *rt, t_plane *plane)
{
	float		scal_nl;
	t_color		*spec;
	t_coord		*tmp;
	t_nearest	pl_current;

	init_current_pl(&pl_current, plane);
	spec = init_color();
	tmp = change_plane_vect(plane->vector, fct->dir);
	scal_nl = ft_scal(tmp, rt->light->normal);
	if (rt->flag_spec)
	{
		if (spec)
			free(spec);
		spec = get_specular(rt, &pl_current, rgb->point, fct);
	}
	check_scal_nl(scal_nl, rgb, spec);
	if (rgb->flag == SHADOW)
	{
		if (rgb->rgb_finale)
			free(rgb->rgb_finale);
		rgb->rgb_finale = apply_shadow_color(rgb->color);
	}
	free(tmp);
	free(spec);
}

int	create_plane_rgb_finale(float t, t_fct *fct, t_data *rt, t_plane *plane)
{
	t_rgb		rgb;
	t_nearest	pl_current;
	t_coord		*tmp;

	init_current_pl(&pl_current, plane);
	rgb.point = ft_addition(rt->cam->coord, ft_scal_one(fct->dir, t));
	rgb.flag = NO_SHADOW;
	rgb.color = apply_amb(plane->color, rt->ambiante->ratio);
	rgb.flag = ray_shadowing(rt, rgb.point, &pl_current);
	rt->light->normal = get_normal_light(rt, rgb.point);
	tmp = change_plane_vect(plane->vector, fct->dir);
	rgb.rgb_diff = get_rgb_diff(tmp, rt->light->normal, rt->light->ratio,
			plane->color);
	free(tmp);
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
