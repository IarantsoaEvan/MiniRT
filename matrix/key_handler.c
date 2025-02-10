/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 08:11:45 by irabesan          #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */


#include "matrix.h"

void ratio_light(int keycode, t_light *light)
{
	if (keycode == 49)
	{
		if (light->ratio >= 0 && light->ratio <= 1)
			light->ratio -= 0.2;
	}
	if (keycode == 50)
	{
		if (light->ratio >= 0 && light->ratio <= 1)
			light->ratio += 0.2;
	}
	if (light->ratio > 1.0f)
		light->ratio = 1.0f;
	if (light->ratio < 0.0f)
		light->ratio = 0.0f;
}

void	trs_light(int keycode, t_light *light)
{
	if (keycode == 49 || keycode == 50)
		ratio_light(keycode, light);
	// {
	// 	if (light->ratio >= 0 && light->ratio <= 1)
	// 		light->ratio -= 0.2;
	// }
	// if (keycode == 50)
	// {
	// 	if (light->ratio >= 0 && light->ratio <= 1)
	// 		light->ratio += 0.2;
	// }
	// if (light->ratio > 1.0f)
	// 	light->ratio = 1.0f;
	// if (light->ratio < 0.0f)
	// 	light->ratio = 0.0f;
	// printf("light->ratio = %f\n",light->ratio);
	if (keycode == 100)
		light->coord->x += 0.9;
	if (keycode == 119)
		light->coord->y += 0.9;
	if (keycode == 101)
		light->coord->z += 0.9;
	if (keycode == 97)
		light->coord->x -= 0.9;
	if (keycode == 115)
		light->coord->y -= 0.9;
	if (keycode == 113)
		light->coord->z -= 0.9;
}
int	keyboard_handler(int keycode, t_data *rt)
{
	trs_light(keycode, rt->light);
	trs_x(rt->near_moove, keycode);
	trs_y(rt->near_moove, keycode);
	rot_x(keycode, rt, rt->near_moove);
	rot_y(keycode, rt, rt->near_moove);
	rot_z(keycode, rt, rt->near_moove);
	mlx_destroy_image(rt->mlx_ptr, rt->img_ptr);
	rt->img_ptr = mlx_new_image(rt->mlx_ptr, rt->width, rt->height);
	ray_tracing(rt);
	mlx_put_image_to_window(rt->mlx_ptr, rt->win_ptr, rt->img_ptr, 0, 0);
	//}
	// mlx_destroy_image(rt->mlx_ptr, rt->img_ptr);
	// rt->img_ptr = mlx_new_image(rt->mlx_ptr, rt->width, rt->height);
	// ray_tracing(rt);
	// mlx_put_image_to_window(rt->mlx_ptr, rt->win_ptr, rt->img_ptr, 0, 0);
	// printf("keycode = %d\n",keycode);
	return (0);
}