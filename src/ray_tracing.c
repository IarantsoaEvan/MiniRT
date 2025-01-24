/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 09:27:27 by irabesan          #+#    #+#             */
/*   Updated: 2025/01/24 13:32:37 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_lbrt init_lbrt(void)
{
	t_lbrt	coo;
	
	coo.bottom = 0;
	coo.left = 0;
	coo.right = 0;
	coo.top = 0;
	return (coo);
}

void ft_set_cfct(t_fct *fct, float x, float y, t_data *rt)
{
	t_lbrt	coo;

	coo = init_lbrt();
	coo.left = rt->cam->coord->x - (fct->as_he/ 2);
	coo.top = rt->cam->coord->y - (fct->as_wi / 2);
	coo.right = -(coo.left);
	coo.bottom = -(coo.top);
	fct->as_x = coo.left + (x + 0.5) * ((coo.right - coo.left) / rt->width);
	fct->as_y = coo.bottom + (y + 0.5)* ((coo.top - coo.bottom) / rt->height);
	real_ray_dir(fct,rt->cam);
}

void	ray_tracing(t_data *rt)
{
	float x;
	float	y;
	float t;
	t_fct *fct;

	y = 0;
	t = 0;
	fct = init_fct(rt);
	while (y < rt->height)
	{
		x = 0;
		while (x < rt->width)
		{
			ft_set_cfct(fct, x, y, rt);
				// intersec(fct,rt);
			// if (rt->cyl)
				intersec_cyl(fct,rt,x,y);
			// if (rt->plane)
			// 	intersec_plane(fct,rt,x,y);
			// if (rt->sphere)
				// intersec_sphere(fct,rt,x,y);
			if (t > 0)
				mlx_pixel_put(rt->mlx_ptr, rt->win_ptr, (int)x, (int)y, 0xFF0000);
			x++;
		}
		y++;
	}
}
