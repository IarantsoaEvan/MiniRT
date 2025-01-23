/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 09:27:27 by irabesan          #+#    #+#             */
/*   Updated: 2025/01/23 11:43:40 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void intersec(t_fct *fct,t_data *rt)
{
	ft_ndc(&fct->x_ndc, &fct->y_ndc);
	ft_screen(&fct->x_ndc, &fct->y_ndc, &fct->x_screen, &fct->y_screen);
	ft_as_ratio(fct, rt->cam);
	// set_ray_direction(fct, fct->dir,rt->cam);
	real_ray_dir(fct, rt->cam);
}

void	ray_tracing(t_data *rt)
{
	float x;
	float	y;
	t_fct *fct;

	y = 0;
	fct = init_fct();
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			fct->x_ndc = x;
			fct->y_ndc = y;
			intersec(fct,rt);
			if (rt->cyl)
				intersec_cyl(fct,rt,x,y);
			if (rt->plane)
				intersec_plane(fct,rt,x,y);
			if (rt->sphere)
				intersec_sphere(fct,rt,x,y);
			// if (t > 0)
			// 	mlx_pixel_put(rt->mlx_ptr, rt->win_ptr, (int)x, (int)y, 0xFF0000);
			x++;
		}
		y++;
	}
}
