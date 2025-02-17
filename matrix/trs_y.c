/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trs_y.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:24:27 by irabesan          #+#    #+#             */
/*   Updated: 2025/02/17 09:18:49 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

void	trp_following_y(t_nearest *near_moove, int keycode, t_data *rt)
{
	t_sphere	*sphere;
	t_plane		*plane;
	t_cyl		*cyl;

	if (near_moove->type == SPHERE && keycode == 65364 && near_moove->near_obj
		&& rt->flag_cam != 1)
	{
		sphere = (t_sphere *)near_moove->near_obj;
		sphere->coord->y -= 0.2;
	}
	if (near_moove->type == PLANE && keycode == 65364 && near_moove->near_obj
		&& rt->flag_cam != 1)
	{
		plane = (t_plane *)near_moove->near_obj;
		plane->coord->y -= 0.2;
	}
	if ((near_moove->type == CYL || near_moove->type == DISK)
		&& keycode == 65364 && near_moove->near_obj && rt->flag_cam != 1)
	{
		if (near_moove->type == DISK && near_moove->cyl_parent)
			cyl = near_moove->cyl_parent;
		else
			cyl = (t_cyl *)near_moove->near_obj;
		cyl->coord->y -= 0.2;
	}
}

void	trn_following_y(t_nearest *near_moove, int keycode, t_data *rt)
{
	t_sphere	*sphere;
	t_plane		*plane;
	t_cyl		*cyl;

	if (near_moove->type == SPHERE && keycode == 65362 && near_moove->near_obj
		&& rt->flag_cam != 1)
	{
		sphere = (t_sphere *)near_moove->near_obj;
		sphere->coord->y += 0.2;
	}
	if (near_moove->type == PLANE && keycode == 65362 && near_moove->near_obj
		&& rt->flag_cam != 1)
	{
		plane = (t_plane *)near_moove->near_obj;
		plane->coord->y += 0.2;
	}
	if ((near_moove->type == CYL || near_moove->type == DISK)
		&& keycode == 65362 && near_moove->near_obj && rt->flag_cam != 1)
	{
		if (near_moove->type == DISK)
			cyl = near_moove->cyl_parent;
		else
			cyl = (t_cyl *)near_moove->near_obj;
		cyl->coord->y += 0.2;
	}
}

void	trs_y(t_nearest *near_moove, int keycode, t_data *rt)
{
	trn_following_y(near_moove, keycode, rt);
	trp_following_y(near_moove, keycode, rt);
}
