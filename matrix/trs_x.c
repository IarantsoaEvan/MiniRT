/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trs_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:22:43 by irabesan          #+#    #+#             */
/*   Updated: 2025/02/06 14:02:21 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

void	trp_following_x(t_nearest *near_moove, int keycode)
{
	t_sphere *sphere;
	t_plane *plane;
	t_cyl *cyl;
	
	if (near_moove->type == SPHERE && keycode == 65361)
	{
		sphere = (t_sphere *)near_moove->near_obj;
		sphere->coord->x -= 0.5;
	}
	if (near_moove->type == PLANE && keycode == 65361)
	{
		plane = (t_plane *)near_moove->near_obj;
		plane->coord->x -= 0.5;
	}
	if (near_moove->type == CYL && keycode == 65361)
	{
		cyl = (t_cyl *)near_moove->near_obj;
		cyl->coord->x -= 0.5;
	}
}

// void moove(t_coord *coord,int keycode)
// {
// 	if (keycode == 65363)
// 		coord->x += 0.5
// 	if (keycode == 65361)
// 		coord->x -= 0.5
// 	if (keycode == 65364)
// 		coord->y -= 0.5

// }

void	trn_following_x(t_nearest *near_moove, int keycode)
{
	t_sphere *sphere;
	t_plane *plane;
	t_cyl *cyl;
	
	if (near_moove->type == SPHERE && keycode == 65363)
	{
		sphere = (t_sphere *)near_moove->near_obj;
		sphere->coord->x += 0.5;
	}
	if (near_moove->type == PLANE && keycode == 65363)
	{
		plane = (t_plane *)near_moove->near_obj;
		plane->coord->x += 0.5;
	}
	if (near_moove->type == CYL && keycode == 65363)
	{
		cyl = (t_cyl *)near_moove->near_obj;
		cyl->coord->x += 0.5;
	}
}
void trs_x(t_nearest *near_moove, int keycode)
{
	trn_following_x(near_moove, keycode);
	trp_following_x(near_moove, keycode);
}