/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trs_y.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:24:27 by irabesan          #+#    #+#             */
/*   Updated: 2025/02/06 10:33:30 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

void	trp_following_y(t_nearest *near_moove, int keycode)
{
	t_sphere *sphere;
	t_plane *plane;
	t_cyl *cyl;
	
	if (near_moove->type == SPHERE && keycode == 65364 && near_moove->near_obj)
	{
		sphere = (t_sphere *)near_moove->near_obj;
		sphere->coord->y -= 0.5;
	}
	if (near_moove->type == PLANE && keycode == 65364 && near_moove->near_obj)
	{
		plane = (t_plane *)near_moove->near_obj;
		plane->coord->y -= 0.5;
	}
	if (near_moove->type == CYL && keycode == 65364 && near_moove->near_obj)
	{
		cyl = (t_cyl *)near_moove->near_obj;
		cyl->coord->y -= 0.5;
	}
}

void	trn_following_y(t_nearest *near_moove, int keycode)
{
	t_sphere *sphere;
	t_plane *plane;
	t_cyl *cyl;
	
	if (near_moove->type == SPHERE && keycode == 65362 && near_moove->near_obj)
	{
		sphere = (t_sphere *)near_moove->near_obj;
		sphere->coord->y += 0.5;
	}
	if (near_moove->type == PLANE && keycode == 65362 && near_moove->near_obj)
	{
		plane = (t_plane *)near_moove->near_obj;
		plane->coord->y += 0.5;
	}
	if (near_moove->type == CYL && keycode == 65362 && near_moove->near_obj)
	{
		cyl = (t_cyl *)near_moove->near_obj;
		cyl->coord->y += 0.5;
	}
}
void trs_y(t_nearest *near_moove, int keycode)
{
	trn_following_y(near_moove, keycode);
	trp_following_y(near_moove, keycode);
}