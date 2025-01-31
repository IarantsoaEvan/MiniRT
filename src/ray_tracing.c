/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 09:27:27 by irabesan          #+#    #+#             */
/*   Updated: 2025/01/31 09:54:56 by mrambelo         ###   ########.fr       */
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
	fct->as_x = coo.left + (x + 0.5) * ((fct->as_he) / rt->width);
	fct->as_y = (coo.bottom + (y + 0.5) * ((-fct->as_wi) / rt->height));
	real_ray_dir(fct,rt->cam);
}

void intersec_obj(t_fct	*fct, t_data *rt)
{
	rt->near->t_near = INFINITY;
	if (rt->cyl)
		intersec_cyl(fct,rt);
	if (rt->plane)
		intersec_plane(fct,rt);
	if (rt->sphere)
		intersec_sphere(fct,rt);
}

// void cam_set_up(t_camera *cam)
// {
// 	t_coord	*cam_ort;
// 	t_coord	*ort_y;

// 	ort_y = init_coord();
// 	cam_ort = normalize_vector(cam->vector);
// 	if (cam_ort->y == 1 && !cam_ort->x && !cam_ort->z)
// 		ort_y->z = -1;
// 	else
// 		ort_y->y = 1;
// 	cam->cam_right = normalize_vector(ft_cross_product(cam_ort, ort_y));
// 	cam->cam_up = normalize_vector(ft_cross_product(cam_ort, cam->cam_right));
// }

void	ray_tracing(t_data *rt)
{
	float x;
	float	y;
	t_fct	*fct;

	y = 0;
	fct = init_fct(rt);
	rt->near = init_nearest();
	// cam_set_up(rt->cam);
	while (y < rt->height)
	{
		x = 0;
		while (x < rt->width)
		{
			ft_set_cfct(fct, x, y, rt);
			intersec_obj(fct, rt);
			get_nearest_obj(rt ,fct , x,y);
			
			x++;
		}
		y++;
	}
}
