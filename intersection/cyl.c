/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:01:07 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/17 08:37:06 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

void	get_abc_cyl(t_coord *origin, t_fct *fct, t_cyl *cyl)
{
	t_coord	*norm_vec;
	t_coord	*x;
	float	scal_dir;

	norm_vec = normalize_vector(cyl->vector);
	x = ft_soustraction(origin, cyl->coord);
	scal_dir = ft_scal(fct->dir, fct->dir);
	fct->pol->a = scal_dir - powf(ft_scal(fct->dir, norm_vec), 2);
	fct->pol->b = (ft_scal(fct->dir, x) - (ft_scal(fct->dir, norm_vec)
				* ft_scal(x, norm_vec))) * 2;
	fct->pol->c = ft_scal(x, x) - powf(ft_scal(x, norm_vec), 2)
		- powf((float)(cyl->diam / 2), 2);
	free(norm_vec);
	free(x);
}

int	create_cyl_rgb_finale(float t, t_fct *fct, t_data *rt, t_cyl *cyl)
{
	t_rgb		rgb;
	t_nearest	cyl_current;

	init_current_cyl(&cyl_current, cyl);
	rgb.point = ft_addition(rt->cam->coord, ft_scal_one(fct->dir, t));
	rgb.flag = NO_SHADOW;
	rgb.color = apply_amb(cyl->color, rt->ambiante->ratio);
	rgb.flag = ray_shadowing(rt, rgb.point, &cyl_current);
	rt->light->normal = get_normal_light(rt, rgb.point);
	cyl->normal = get_normal_cyl(rt, rgb.point, cyl);
	rgb.rgb_diff = get_rgb_diff(cyl->normal, rt->light->normal,
			rt->light->ratio, cyl->color);
	aply_color_cyl(fct, &rgb, rt, cyl);
	rgb.rgb = create_trgb(rgb.rgb_finale->r, rgb.rgb_finale->g,
			rgb.rgb_finale->b);
	free(cyl->normal);
	return (free(rt->light->normal), free_rgb(&rgb), rgb.rgb);
}

float	get_t_cyl_delta_pos(t_fct *fct, t_cyl *cyl, float delta,
		t_coord *origin)
{
	float	t1;
	float	t2;
	float	distance;

	distance = -1;
	t1 = (((-1) * fct->pol->b) - (sqrt(delta))) / (2 * fct->pol->a);
	t2 = (((-1) * fct->pol->b) + (sqrt(delta))) / (2 * fct->pol->a);
	if (t1 > 0.0001)
	{
		cyl->m = get_m_scal(fct->dir, origin, t1, cyl);
		if (cyl->m >= -cyl->height / 2 && cyl->m <= cyl->height / 2)
			distance = t1;
	}
	if (t2 > 0.0001)
	{
		cyl->m = get_m_scal(fct->dir, origin, t2, cyl);
		if (cyl->m >= -cyl->height / 2 && cyl->m <= cyl->height / 2
			&& (distance < 0 || t2 < t1))
			distance = t2;
	}
	return (distance);
}

float	get_t_cyl(t_fct *fct, float delta, t_coord *origin, t_cyl *cyl)
{
	float	t1;
	float	distance;

	distance = -1;
	if (delta == 0)
	{
		t1 = (fct->pol->b * (-1)) / (2 * fct->pol->a);
		cyl->m = get_m_scal(fct->dir, origin, t1, cyl);
		if (cyl->m >= -cyl->height / 2 && cyl->m >= cyl->height / 2)
			distance = t1;
	}
	else if (delta > 0)
		distance = get_t_cyl_delta_pos(fct, cyl, delta, origin);
	return (distance);
}

void	intersec_cyl(t_fct *fct, t_data *rt, t_nearest *near)
{
	t_cyl	*tmp;
	float	t;
	float	t_top;
	float	t_bot;

	tmp = rt->cyl;
	while (tmp)
	{
		get_abc_cyl(rt->cam->coord, fct, tmp);
		t = get_t_cyl(fct, get_delta(fct->pol), rt->cam->coord, tmp);
		t_top = get_base_cyl(fct->dir, rt->cam->coord, tmp, 1);
		t_bot = get_base_cyl(fct->dir, rt->cam->coord, tmp, 0);
		if (t > 0.0001 && t < near->t_near)
		{
			near->t_near = t;
			near->near_obj = tmp;
			near->type = CYL;
		}
		intersec_disk_cyl(near, tmp, t_top, t_bot);
		tmp = tmp->next;
	}
}
