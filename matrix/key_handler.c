/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 08:11:45 by irabesan          #+#    #+#             */
/*   Updated: 2025/02/09 19:05:51 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "matrix.h"


int	keyboard_handler(int keycode, t_data *rt)
{
	trs_x(rt->near_moove, keycode);
	trs_y(rt->near_moove, keycode);
	rot_x(keycode, rt, rt->near_moove);
	rot_y(keycode, rt, rt->near_moove);
	rot_z(keycode, rt, rt->near_moove);
	// if ((rt->flag_rot_x || rt->flag_rot_y || rt->flag_rot_z) && (keycode == 45 || keycode == 61))
	// {
	// select_sign(keycode, rt->angle, rt->near_moove->dir, rt);
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