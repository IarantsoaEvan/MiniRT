/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:04:58 by mrambelo          #+#    #+#             */
/*   Updated: 2025/01/28 15:26:09 by mrambelo         ###   ########.fr       */
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
int create_plane_rgb_finale(float t,t_fct *fct,t_data *rt,t_plane *plane)
{
	t_coord *point;
	t_color *color;
	t_color *rgb_diff;
	t_color *rgb_finale;
	int rgb;
	
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
	rt->near->t_near = INFINITY;
	while (tmp)
	{
		t = get_t_plane(fct,rt,tmp);
		if (t > 0 && t < rt->near->t_near)
		{
			rt->near->t_near = t;
			rt->near->near_obj = tmp;
			rt->near->type = PLANE; 
		}
		tmp = tmp->next;
	}
}