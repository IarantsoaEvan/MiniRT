/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:04:58 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/04 09:33:37 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

float get_t_plane(t_coord *direction,t_coord *origin,t_plane *plane)
{
	t_coord *xc;
	t_coord *norm;
	float t;

	xc = ft_soustraction(origin,plane->coord);
	norm = normalize_vector(plane->vector);
	t = ((-1) * (ft_scal(xc,norm))) / ft_scal(direction,norm);
	free(xc);
	free(norm);
	return (t);
}
int create_plane_rgb_finale(float t,t_fct *fct,t_data *rt,t_plane *plane)
{
	// t_coord *point;
	// t_color *color;
	// t_color *rgb_diff;
	// t_color *rgb_finale;
	// int rgb;
	t_rgb rgb;
	
	rgb.point = ft_addition(rt->cam->coord,ft_scal_one(fct->dir, t));
	rgb.flag = NO_SHADOW;
	rgb.color = apply_amb(plane->color, rt->ambiante->ratio);
	rgb.flag = ray_shadowing(rt, rgb.point,plane->id);
	rt->light->normal = get_normal_light(rt,rgb.point);
	rgb.rgb_diff = get_rgb_diff(plane->vector
		,rt->light->normal,rt->light->ratio,plane->color);
	rgb.rgb_finale = add_amb_and_diff(rgb.color,rgb.rgb_diff);
	if (rgb.flag == SHADOW)
		rgb.rgb_finale = apply_shadow_color(rgb.rgb_finale);
	rgb.rgb = create_trgb(rgb.rgb_finale->r, rgb.rgb_finale->g, rgb.rgb_finale->b);
	free(rt->light->normal);
	// free(point);
	// free(color);
	// free(rgb_diff);
	// free(rgb_finale);
	return (rgb.rgb);
}
void intersec_plane(t_fct *fct,t_data *rt)
{
	t_plane *tmp;
	float t;
	// int rgb;
	
	// rgb = 0;
	tmp = rt->plane;
	// rt->near->t_near = INFINITY;
	while (tmp)
	{
		t = get_t_plane(fct->dir,rt->cam->coord,tmp);
		if (t > 0 && t < rt->near->t_near)
		{
			rt->near->t_near = t;
			rt->near->near_obj = tmp;
			rt->near->type = PLANE; 
		}
		tmp = tmp->next;
	}
}