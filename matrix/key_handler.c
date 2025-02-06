/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 08:11:45 by irabesan          #+#    #+#             */
/*   Updated: 2025/02/06 13:53:05 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

int	no_comb(int keycode, t_data *rt)
{
	if (keycode == 120 || keycode == 121 || keycode == 122)
		rt->flag_rot = 0;
	return (0);
}
int	keyboard_handler(int keycode, t_data *rt)
{
	trs_x(rt->near_moove, keycode);
	trs_y(rt->near_moove, keycode);
	ft_comb_rotation(keycode, rt);
	mlx_destroy_image(rt->mlx_ptr, rt->img_ptr);
	rt->img_ptr = mlx_new_image(rt->mlx_ptr, rt->width, rt->height);
	ray_tracing(rt);
	mlx_put_image_to_window(rt->mlx_ptr, rt->win_ptr, rt->img_ptr, 0, 0);
	printf("keycode = %d\n",keycode);
	return (0);
}