/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:04:58 by mrambelo          #+#    #+#             */
/*   Updated: 2025/01/23 08:58:25 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

float get_t_plane(t_fct *fct,t_data *rt)
{
	t_coord *xc;
	t_coord *norm;
	float t;

	xc = ft_soustraction(rt->cam->coord,rt->plane->coord);
	norm = normalize_vector(rt->plane->vector);
	t = ((-1) * (ft_scal(xc,norm))) / ft_scal(fct->dir,norm);
	return (t);
}
void intersec_plane(t_fct *fct,t_data *rt,float x,float y)
{
	t_plane *tmp;
	float t;
	
	tmp = rt->plane;
	while (tmp)
	{
		t = get_t_plane(fct,rt);
		if (t > 0)
				mlx_pixel_put(rt->mlx_ptr, rt->win_ptr, (int)x, (int)y, 0xFF0000);
		tmp = tmp->next;
	}
}