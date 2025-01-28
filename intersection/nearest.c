/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nearest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:32:10 by mrambelo          #+#    #+#             */
/*   Updated: 2025/01/28 19:05:03 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

void get_nearest_obj(t_data *rt ,t_fct *fct ,float x,float y)
{
	int rgb;

	if (rt->near->type == SPHERE)
		rgb = create_sphere_rgb_finale(rt->near->t_near,fct,rt,rt->near->near_obj);
	if (rt->near->type == PLANE)
		rgb = create_plane_rgb_finale(rt->near->t_near,fct,rt,rt->near->near_obj);
	if (rt->near->type == CYL)
		rgb = create_cyl_rgb_finale(rt->near->t_near,fct,rt,rt->near->near_obj);
	if (rt->near->t_near > 0 && rt->near->t_near < INFINITY)
		mlx_pixel_put(rt->mlx_ptr,rt->win_ptr, (int)x, (int)y, rgb);
		// my_mlx_pxp(rt, (int)x, (int)y, rgb);
}