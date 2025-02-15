/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nearest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:32:10 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/15 12:11:17 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

int creat_rgb_amb(t_data *rt)
{
	t_color *color;
	int rgb;
	
	color = apply_amb(rt->ambiante->color, rt->ambiante->ratio);
	rgb = create_trgb(color->r, color->g, color->b);
	free(color);
	return (rgb);
}

void get_nearest_obj(t_data *rt ,t_fct *fct ,float x,float y)
{
	int rgb;
	int rgb_amb;

	if (rt->near->type == SPHERE)
		rgb = create_sphere_rgb_finale(rt->near->t_near,fct,rt,rt->near->near_obj);
	if (rt->near->type == PLANE || rt->near->type == DISK)
		rgb = create_plane_rgb_finale(rt->near->t_near,fct,rt,rt->near->near_obj);
	if (rt->near->type == CYL)
		rgb = create_cyl_rgb_finale(rt->near->t_near,fct,rt,rt->near->near_obj);
	if (rt->near->t_near > 0 && rt->near->t_near < INFINITY)
		my_mlx_pxp(rt, (int)x, (int)y, rgb);
	else if (rt->near->t_near == INFINITY)
	{
		rgb_amb = creat_rgb_amb(rt);
		my_mlx_pxp(rt, (int)x, (int)y, rgb_amb);
	}	
}
