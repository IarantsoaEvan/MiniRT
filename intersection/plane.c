/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:04:58 by mrambelo          #+#    #+#             */
/*   Updated: 2025/01/28 10:57:57 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

float get_t_plane(t_fct *fct,t_data *rt,t_plane *plane)
{
	t_coord *xc;
	t_coord *norm;
	float t;

	xc = ft_soustraction(rt->cam->coord,plane->coord);
	norm = normalize_vector(plane->vector);
	t = ((-1) * (ft_scal(xc,norm))) / ft_scal(fct->dir,norm);
	return (t);
}
int create_plane_rgb_finale(float t,t_fct *fct,t_data *rt,void *tmp)
{
	t_coord *point;
	t_color *color;
	t_color *rgb_diff;
	t_color *rgb_finale;
	t_plane *plane;
	int rgb;
	
	plane = (t_plane *)tmp;
	point = ft_addition(rt->cam->coord,ft_scal_one(fct->dir, t));
	color = apply_amb(plane->color, rt->ambiante->ratio);
	rt->light->normal = get_normal_light(rt,point);
	rgb_diff = get_rgb_diff(plane->vector
		,rt->light->normal,rt->light->ratio,plane->color);
	rgb_finale = add_amb_and_diff(color,rgb_diff);
	rgb = create_trgb(rgb_finale->r, rgb_finale->g, rgb_finale->b);
	return (rgb);
}
void intersec_plane(t_fct *fct,t_data *rt)
{
	t_plane *tmp;
	float t;
	int rgb;
	
	rgb = 0;
	tmp = rt->plane;
	while (tmp)
	{
		t = get_t_plane(fct,rt,tmp);
		if (t < rt->obj_nearest->t)
		{
			rt->obj_nearest->t = t;
			rt->obj_nearest->obj = tmp;
			// rgb = create_plane_rgb_finale(t,fct,rt);
			// // color = apply_amb(rt->plane->color, rt->ambiante->ratio);
			// // rgb = create_trgb(color->r, color->g, color->b);
			// mlx_pixel_put(rt->mlx_ptr, rt->win_ptr, (int)x, (int)y, rgb);
		}
		tmp = tmp->next;
	}
}