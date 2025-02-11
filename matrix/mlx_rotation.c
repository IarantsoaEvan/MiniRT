/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:21:02 by irabesan          #+#    #+#             */
/*   Updated: 2025/02/11 08:32:46 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

int no_comb(int keycode, t_data *rt)
{
	
	esc_win(keycode, rt);
	if (keycode == 120)
		rt->flag_rot_x = 0;
	if (keycode == 121)
		rt->flag_rot_y = 0;
	if (keycode == 122)
		rt->flag_rot_z = 0;
	if (keycode == 99)
		rt->flag_cam = 0;
	return (0);
}

void	select_axe(t_data *rt, float angle, t_coord *vect)
{
	if (rt->flag_rot_x == 1)
		rot_foll_x(vect, angle);
	if (rt->flag_rot_y == 1)
		rot_foll_y(vect, angle);
	if (rt->flag_rot_z == 1)
		rot_foll_z(vect, angle);
	// vect = normalize_vector(vect);
	return ;

}
void select_sign(int keycode, float angle, t_coord *vect, t_data *rt)
{
	if (keycode == 45)
	{
		angle -= 0.3;
		select_axe(rt, angle, vect);
	}
	if (keycode == 61)
	{
		angle += 0.3;
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
}

void rot_x(int keycode, t_data *rt, t_nearest *near)
{
	t_plane *plane;
	t_cyl *cyl;

	change_flag_rot(keycode, rt);
	if ((near->type == CYL || near->type == DISK)
		&& rt->flag_rot_x == 1 && near->near_obj)
	{
		if (near->type == DISK)
			cyl = near->cyl_parent;
		else
			cyl = (t_cyl *)near->near_obj;
		select_sign(keycode, rt->alpha, cyl->vector,rt);
	}
	if (near->type == PLANE && rt->flag_rot_x == 1)
	{
		plane = (t_plane *)near->near_obj;
		select_sign(keycode, rt->alpha, plane->vector,rt);
	}
}

void rot_y(int keycode, t_data *rt, t_nearest *near)
{
	t_plane *plane;
	t_cyl *cyl;

	change_flag_rot(keycode, rt);
	if ((near->type == CYL || near->type == DISK)
	&& rt->flag_rot_y == 1 && near->near_obj)
	{
		if (near->type == DISK)
			cyl = near->cyl_parent;
		else
			cyl = (t_cyl *)near->near_obj;
		select_sign(keycode, rt->beta, cyl->vector,rt);
	}
	if (near->type == PLANE && rt->flag_rot_y == 1)
	{
		plane = (t_plane *)near->near_obj;
		select_sign(keycode, rt->beta, plane->vector,rt);
	}
}

void rot_z(int keycode, t_data *rt, t_nearest *near)
{
	t_plane *plane;
	t_cyl *cyl;

	change_flag_rot(keycode, rt);
	if ((near->type == CYL || near->type == DISK)
		&& rt->flag_rot_z == 1 && near->near_obj)
	{
		if (near->type == DISK)
			cyl = near->cyl_parent;
		else
			cyl = (t_cyl *)near->near_obj;
		select_sign(keycode, rt->teta, cyl->vector, rt);
	}
	if (near->type == PLANE && rt->flag_rot_z == 1)
	{
		plane = (t_plane *)near->near_obj;
		select_sign(keycode, rt->teta, plane->vector, rt);
	}
}
