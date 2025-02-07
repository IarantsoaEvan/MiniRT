/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trs_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:22:43 by irabesan          #+#    #+#             */
/*   Updated: 2025/02/07 08:49:30 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

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
	trn_following_x(near_moove, keycode);
	trp_following_x(near_moove, keycode);
}