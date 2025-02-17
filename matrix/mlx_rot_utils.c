/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_rot_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:14:08 by irabesan          #+#    #+#             */
/*   Updated: 2025/02/17 09:14:44 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

int	no_comb(int keycode, t_data *rt)
{
	if (keycode == 65307)
		esc_win(keycode, rt);
	if (keycode == 120)
		rt->flag_rot_x = 0;
	if (keycode == 121)
		rt->flag_rot_y = 0;
	if (keycode == 122)
		rt->flag_rot_z = 0;
	if (keycode == 99)
		rt->flag_cam = 0;
	if (keycode == 51)
		rt->flag_camx = 0;
	if (keycode == 52)
		rt->flag_camy = 0;
	if (keycode == 53)
		rt->flag_camz = 0;
	if (keycode == 114)
		rt->flag_radius = 0;
	if (keycode == 104)
		rt->flag_hcyl = 0;
	if (keycode == 108)
		rt->flag_rdisk = 0;
	return (0);
}

void	select_axe(t_data *rt, float angle, t_coord *vect)
{
	if (rt->flag_rot_x == 1 || rt->flag_camx == 1)
		rot_foll_x(vect, angle);
	if (rt->flag_rot_y == 1 || rt->flag_camy == 1)
		rot_foll_y(vect, angle);
	if (rt->flag_rot_z == 1 || rt->flag_camz == 1)
		rot_foll_z(vect, angle);
	return ;
}

void	select_sign(int keycode, float angle, t_coord *vect, t_data *rt)
{
	if (keycode == 45)
	{
		angle -= 0.1;
		select_axe(rt, angle, vect);
	}
	if (keycode == 61)
	{
		angle += 0.1;
		select_axe(rt, angle, vect);
	}
}

void	change_flag_rot(int keycode, t_data *rt)
{
	if (keycode == 120)
		rt->flag_rot_x = 1;
	if (keycode == 121)
		rt->flag_rot_y = 1;
	if (keycode == 122)
		rt->flag_rot_z = 1;
	if (keycode == 51)
		rt->flag_camx = 1;
	if (keycode == 52)
		rt->flag_camy = 1;
	if (keycode == 53)
		rt->flag_camz = 1;
	if (keycode == 114)
		rt->flag_radius = 1;
	if (keycode == 104)
		rt->flag_hcyl = 1;
	if (keycode == 108)
		rt->flag_rdisk = 1;
}
