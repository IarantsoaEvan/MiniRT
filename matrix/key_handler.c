/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 08:11:45 by irabesan          #+#    #+#             */
/*   Updated: 2025/02/06 09:30:36 by irabesan         ###   ########.fr       */
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