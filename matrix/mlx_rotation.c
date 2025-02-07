/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:21:02 by irabesan          #+#    #+#             */
/*   Updated: 2025/02/07 08:30:41 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

int no_comb(int keycode, t_data *rt)
{
	if (keycode)
		printf("keycode == %d\n", keycode);
	if (keycode == 120)
		rt->flag_rot_x = 0;
	if (keycode == 121)
		rt->flag_rot_y = 0;
	if (keycode == 122)
		rt->flag_rot_z = 0;
	return (0);
}

void select_sign(int keycode, float angle, t_coord *vect)
{
	if (keycode == 45)
	{
		angle -= 0.3;
		rot_foll_x(vect, angle);
	}
	if (keycode == 61)
	{
		angle += 0.3;
		rot_foll_x(vect, angle);
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
}

void rot_x(int keycode, t_data *rt, t_nearest *near)
{
	t_plane *plane;
	t_cyl *cyl;

	change_flag_rot(keycode, rt);
	if (near->type == CYL && rt->flag_rot_x == 1)
	{
		cyl = (t_cyl *)near->near_obj;
		select_sign(keycode, rt->alpha, cyl->vector);
	}
	if (near->type == PLANE && rt->flag_rot_x == 1)
	{
		plane = (t_plane *)near->near_obj;
		select_sign(keycode, rt->alpha, plane->vector);
	}
}