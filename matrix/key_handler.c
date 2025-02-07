/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 08:11:45 by irabesan          #+#    #+#             */
/*   Updated: 2025/02/07 08:13:31 by mrambelo         ###   ########.fr       */
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
int	keyboard_handler(int keycode, t_data *rt)
{
	trs_x(rt->near_moove, keycode);
	mlx_destroy_image(rt->mlx_ptr, rt->img_ptr);
	rt->img_ptr = mlx_new_image(rt->mlx_ptr, rt->width, rt->height);
	ray_tracing(rt);
	mlx_put_image_to_window(rt->mlx_ptr, rt->win_ptr, rt->img_ptr, 0, 0);
	printf("keycode = %d\n",keycode);
	return (0);
}