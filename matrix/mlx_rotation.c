/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:21:02 by irabesan          #+#    #+#             */
/*   Updated: 2025/02/17 12:31:52 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

void	rot_x(int keycode, t_data *rt, t_nearest *near)
{
	t_plane	*plane;
	t_cyl	*cyl;

	change_flag_rot(keycode, rt);
	if ((near->type == CYL || near->type == DISK) && rt->flag_rot_x == 1
		&& near->near_obj)
	{
		if (near->type == DISK && near->cyl_parent)
			cyl = near->cyl_parent;
		else
			cyl = (t_cyl *)near->near_obj;
		select_sign(keycode, rt->alpha, cyl->vector, rt);
	}
	if (near->type == PLANE && rt->flag_rot_x == 1 &&  near->near_obj)
	{
		plane = (t_plane *)near->near_obj;
		select_sign(keycode, rt->alpha, plane->vector, rt);
	}
}

void	rot_y(int keycode, t_data *rt, t_nearest *near)
{
	t_plane	*plane;
	t_cyl	*cyl;

	change_flag_rot(keycode, rt);
	if ((near->type == CYL || near->type == DISK) && rt->flag_rot_y == 1
		&& near->near_obj)
	{
		if (near->type == DISK && near->cyl_parent)
			cyl = near->cyl_parent;
		else
			cyl = (t_cyl *)near->near_obj;
		select_sign(keycode, rt->beta, cyl->vector, rt);
	}
	if (near->type == PLANE && rt->flag_rot_y == 1 && near->near_obj)
	{
		plane = (t_plane *)near->near_obj;
		select_sign(keycode, rt->beta, plane->vector, rt);
	}
}

void	rot_z(int keycode, t_data *rt, t_nearest *near)
{
	t_plane	*plane;
	t_cyl	*cyl;

	change_flag_rot(keycode, rt);
	if ((near->type == CYL || near->type == DISK) && rt->flag_rot_z == 1
		&& near->near_obj)
	{
		if (near->type == DISK && near->cyl_parent)
			cyl = near->cyl_parent;
		else
			cyl = (t_cyl *)near->near_obj;
		select_sign(keycode, rt->teta, cyl->vector, rt);
	}
	if (near->type == PLANE && rt->flag_rot_z == 1 && near->near_obj)
	{
		plane = (t_plane *)near->near_obj;
		select_sign(keycode, rt->teta, plane->vector, rt);
	}
}
