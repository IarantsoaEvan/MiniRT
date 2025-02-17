/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 08:09:06 by irabesan          #+#    #+#             */
/*   Updated: 2025/02/17 08:43:23 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

void	set_disk_pos_neg(t_cyl *cyl, int check_pos, t_coord *norm_vec)
{
	if (check_pos == 0)
	{
		cyl->disk_bot->id = cyl->id;
		if (cyl->disk_bot->coord)
			free(cyl->disk_bot->coord);
		cyl->disk_bot->coord = ft_addition(cyl->coord, ft_scal_one(norm_vec,
					-cyl->height / 2));
		if (cyl->disk_bot->vector)
			free(cyl->disk_bot->vector);
		cyl->disk_bot->vector = ft_scal_one(cyl->vector, -1.0);
		cyl->disk_bot->color = cyl->color;
	}
	else
	{
		cyl->disk_top->id = cyl->id;
		if (cyl->disk_top->coord)
			free(cyl->disk_top->coord);
		cyl->disk_top->coord = ft_addition(cyl->coord, ft_scal_one(norm_vec,
					cyl->height / 2));
		if (cyl->disk_top->vector)
			free(cyl->disk_top->vector);
		cyl->disk_top->vector = ft_scal_one(cyl->vector, 1.0);
		cyl->disk_top->color = cyl->color;
	}
}

void	set_disk(t_cyl *cyl, int check_pos)
{
	t_coord	*norm_vec;

	norm_vec = normalize_vector(cyl->vector);
	set_disk_pos_neg(cyl, check_pos, norm_vec);
	free(norm_vec);
}

void	intersec_disk_cyl(t_nearest *near, t_cyl *tmp, float t_top, float t_bot)
{
	if (t_top > 0.0001 && t_top < near->t_near)
	{
		near->t_near = t_top;
		near->near_obj = tmp->disk_top;
		near->cyl_parent = tmp;
		near->type = DISK;
	}
	if (t_bot > 0.0001 && t_bot < near->t_near)
	{
		near->t_near = t_bot;
		near->near_obj = tmp->disk_bot;
		near->cyl_parent = tmp;
		near->type = DISK;
	}
}

void	aply_color_cyl(t_fct *fct, t_rgb *rgb, t_data *rt, t_cyl *cyl)
{
	float		scal_nl;
	t_color		*spec;
	t_nearest	cyl_current;

	init_current_cyl(&cyl_current, cyl);
	spec = init_color();
	scal_nl = ft_scal(cyl->normal, rt->light->normal);
	if (rt->flag_spec)
	{
		if (spec)
			free(spec);
		spec = get_specular(rt, &cyl_current, rgb->point, fct);
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
