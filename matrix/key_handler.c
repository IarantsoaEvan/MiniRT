/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 08:11:45 by irabesan          #+#    #+#             */
/*   Updated: 2025/02/10 14:44:39 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "matrix.h"

void	trs_cam(int keycode, t_data *rt)
{
	if (keycode == 99)
	{
		rt->flag_cam = 1;
		// printf("flag == 1\n");
	}
	if (keycode == 65361 && rt->flag_cam == 1)
		rt->cam->coord->x -= 0.2;
	if (keycode == 65363 && rt->flag_cam == 1)
		rt->cam->coord->x += 0.2;
	if (keycode == 65364 && rt->flag_cam == 1)
		rt->cam->coord->y -= 0.2;
	if (keycode == 65362 && rt->flag_cam == 1)
		rt->cam->coord->y += 0.2;
}

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
	trs_cam(keycode, rt);
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
	return (0);
}