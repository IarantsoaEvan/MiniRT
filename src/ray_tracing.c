/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 09:27:27 by irabesan          #+#    #+#             */
/*   Updated: 2025/01/22 15:02:13 by mrambelo         ###   ########.fr       */
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
	float	t;
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
			get_abc_cyl(rt,fct);
			t = get_t_cyl(fct, get_delta(fct->pol), rt);
			// t = get_t_plane(fct,rt);
			// if (rt->sphere)
			// {
			// 	intersec_sphere(fct,rt);
				// t = get_t_sphere(fct->pol, get_delta(fct->pol));
			// }
			if (t > 0)
				mlx_pixel_put(rt->mlx_ptr, rt->win_ptr, (int)x, (int)y, 0xFF0000);
			x++;
		}
		y++;
	}
}