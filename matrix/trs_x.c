/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trs_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:22:43 by irabesan          #+#    #+#             */
/*   Updated: 2025/02/11 11:06:11 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

void cyl_dimension(int keycode, t_cyl *cyl)
{
	if (keycode == 65360)
		cyl->diam += 0.2;
	if (keycode == 65367)
		cyl->diam -= 0.2;
	if (keycode == 65365)
		cyl->height += 0.2;
	if (keycode == 65366)
		cyl->height -= 0.2;
}
void	set_dimension(t_nearest *near_moove, int keycode)
{
	t_sphere *sphere;
	t_cyl	*cyl;

	// change_flag_rot(keycode, rt);
	if (near_moove->type == SPHERE && near_moove->near_obj)
	{
		sphere = (t_sphere *)near_moove->near_obj;
		if (keycode == 65379)
		 	sphere->diam += 0.2;
		if (keycode == 65535)
			sphere->diam -= 0.2;
	}
	if ((near_moove->type == CYL || near_moove->type == DISK) && near_moove->near_obj)
	{
		cyl = (t_cyl *)near_moove->near_obj;
		cyl_dimension(keycode, cyl);
	}
}
void	trp_following_x(t_nearest *near_moove, int keycode)
{
	t_sphere *sphere;
	t_plane *plane;
	t_cyl *cyl;
	
	if (near_moove->type == SPHERE && keycode == 65361 && near_moove->near_obj)
	{
		sphere = (t_sphere *)near_moove->near_obj;
		sphere->coord->x -= 0.5;
	}
	if (near_moove->type == PLANE && keycode == 65361 && near_moove->near_obj)
	{
		plane = (t_plane *)near_moove->near_obj;
		plane->coord->x -= 0.5;
	}
	if ((near_moove->type == CYL || near_moove->type == DISK)
		&& keycode == 65361 && near_moove->near_obj )
	{
		if (near_moove->type == DISK && near_moove->cyl_parent)
			cyl = near_moove->cyl_parent;
		else
			cyl = (t_cyl *)near_moove->near_obj;
		cyl->coord->x -= 0.5;
	}
}

void	trn_following_x(t_nearest *near_moove, int keycode)
{
	t_sphere *sphere;
	t_plane *plane;
	t_cyl *cyl;
	
	if (near_moove->type == SPHERE && keycode == 65363 && near_moove->near_obj)
	{
		sphere = (t_sphere *)near_moove->near_obj;
		sphere->coord->x += 0.5;
	}
	if (near_moove->type == PLANE && keycode == 65363 && near_moove->near_obj)
	{
		plane = (t_plane *)near_moove->near_obj;
		plane->coord->x += 0.5;
	}
	if ((near_moove->type == CYL || near_moove->type == DISK)
		&& keycode == 65363 && near_moove->near_obj)
	{
		if (near_moove->type == DISK)
			cyl = near_moove->cyl_parent;
		else
			cyl = (t_cyl *)near_moove->near_obj;
		cyl->coord->x += 0.5;
	}
}
void trs_x(t_nearest *near_moove, int keycode)
{
	set_dimension(near_moove, keycode);
	trn_following_x(near_moove, keycode);
	trp_following_x(near_moove, keycode);
}