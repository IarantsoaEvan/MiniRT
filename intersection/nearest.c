/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nearest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 09:14:41 by mrambelo          #+#    #+#             */
/*   Updated: 2025/01/28 11:49:34 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

int get_color_nearest(t_data *rt,t_fct *fct)
{
	int rgb;

	if (rt->obj_nearest->type == SHPERE)
		rgb = create_sphere_rgb_finale(rt->obj_nearest->t,fct,rt,rt->obj_nearest->obj);
	else if (rt->obj_nearest->type == PLANE)
		rgb = create_plane_rgb_finale(rt->obj_nearest->t,fct,rt,rt->obj_nearest->obj);
	else if (rt->obj_nearest->type == CYL)
		rgb = create_cyl_rgb_finale(rt->obj_nearest->t,fct,rt
		,get_m_scal(fct,rt,rt->obj_nearest->t,rt->obj_nearest->obj),rt->obj_nearest->obj);
	else
		rgb = 0x00000;
	return (rgb);
}