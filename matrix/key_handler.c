/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 08:11:45 by irabesan          #+#    #+#             */
/*   Updated: 2025/02/18 13:52:35 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

void	rot_cam(int keycode, t_data *rt, t_camera *cam)
{
	change_flag_rot(keycode, rt);
	if (rt->flag_camx == 1)
		select_sign(keycode, rt->alpha_cam, cam->vector, rt);
	if (rt->flag_camy == 1)
		select_sign(keycode, rt->beta_cam, cam->vector, rt);
	if (rt->flag_camz == 1)
		select_sign(keycode, rt->teta_cam, cam->vector, rt);
}

void	trs_cam(int keycode, t_data *rt)
{
	if (keycode == 99)
		rt->flag_cam = 1;
	if (keycode == 65361 && rt->flag_cam == 1)
		rt->cam->coord->x -= 0.1;
	if (keycode == 65363 && rt->flag_cam == 1)
		rt->cam->coord->x += 0.1;
	if (keycode == 65364 && rt->flag_cam == 1)
		rt->cam->coord->y += 0.1;
	if (keycode == 65362 && rt->flag_cam == 1)
		rt->cam->coord->y -= 0.1;
	if (keycode == 65507)
		rt->cam->coord->z -= 0.1;
	if (keycode == 65508)
		rt->cam->coord->z += 0.1;
}

void	ratio_light(int keycode, t_light *light)
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
	if (keycode == 32 && rt->flag_spec == 0)
		rt->flag_spec = 1;
	else if (keycode == 32 && rt->flag_spec == 1)
		rt->flag_spec = 0;
	trs_light(keycode, rt->light);
	trs_x(rt->near_moove, keycode, rt);
	trs_y(rt->near_moove, keycode, rt);
	trs_cam(keycode, rt);
	rot_x(keycode, rt, rt->near_moove);
	rot_y(keycode, rt, rt->near_moove);
	rot_z(keycode, rt, rt->near_moove);
	rot_cam(keycode, rt, rt->cam);
	mlx_destroy_image(rt->mlx_ptr, rt->img_ptr);
	rt->img_ptr = mlx_new_image(rt->mlx_ptr, rt->width, rt->height);
	ray_tracing(rt);
	mlx_put_image_to_window(rt->mlx_ptr, rt->win_ptr, rt->img_ptr, 0, 0);
	return (0);
}
