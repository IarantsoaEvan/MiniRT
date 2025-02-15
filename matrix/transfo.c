/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 09:43:25 by irabesan          #+#    #+#             */
/*   Updated: 2025/02/15 10:14:50 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

int	esc_win(int keycode, t_data *rt)
{
	if (keycode == 65307)
	{
		mlx_destroy_image(rt->mlx_ptr, rt->img_ptr);
		mlx_destroy_window(rt->mlx_ptr, rt->win_ptr);
		mlx_destroy_display(rt->mlx_ptr);
		free(rt->mlx_ptr);
		if (rt->sphere)
			free_sphere(rt->sphere);
		if (rt->plane)
			free_plane(rt->plane);
		if (rt->cyl)
			free_cyl(rt->cyl);
		free_light_cam_amb(rt);
		free(rt->near_moove);
		free(rt);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	select_obj(t_data *rt, int x, int y,t_nearest *near)
{
	t_fct *fct;

	near->near_obj = NULL;
	fct = init_fct(rt);
	if (y < rt->height && x < rt->width)
	{
		ft_set_cfct(fct, (float)x, (float)y, rt);
		intersec_obj(fct, rt,near);
		if (near->t_near > 0 && near->near_obj
			&& near->type == SPHERE)
			return (free_fct(fct),SPHERE);
		if (near->t_near > 0 && near->near_obj
			&& near->type == PLANE)
			return (free_fct(fct),PLANE);
		if (near->t_near > 0 && near->near_obj
			&& near->type == CYL)
			return (free_fct(fct),CYL);
		if (near->t_near > 0 && near->near_obj && near->cyl_parent
			&& near->type == DISK)
			return (free_fct(fct),DISK);
	}
	return (free_fct(fct),-1);
}
void zoom_object_pos(t_nearest *near,int type)
{
	t_sphere *sphere;
	t_plane *plane;
	t_cyl *cyl;
	
	if (type == SPHERE)
	{
		sphere = (t_sphere *)near->near_obj;
		sphere->coord->z += 0.2;
	}
	if (type == PLANE)
	{
		plane = near->near_obj;
		plane->coord->z += 0.2;
	}
	if (type == CYL ||  type == DISK)
	{
		if (type == DISK)
			cyl = near->cyl_parent;
		else
			cyl = near->near_obj;
		cyl->coord->z += 0.2;
	}

}

void zoom_object_neg(t_nearest *near,int type)
{
	t_sphere *sphere;
	t_plane *plane;
	t_cyl *cyl;
	

	if (type == SPHERE)
	{
		sphere = (t_sphere *)near->near_obj;
		sphere->coord->z -= 0.4;
	}
	if (type == PLANE)
	{
		plane = (t_plane *)near->near_obj;
		plane->coord->z -= 0.2;
	}
	if (type == CYL ||  type == DISK)
	{
			if (type == DISK)
				cyl = near->cyl_parent;
			else
				cyl = near->near_obj;
			cyl->coord->z -= 0.2;
	}

}
int mouse_handler(int keycode , int x, int y, t_data *rt)
{
	static int  type;
	// static t_nearest near;

	if (keycode == 1)
		type = select_obj(rt,  x,  y,rt->near_moove);	
	if (keycode == 4 || keycode == 5)
	{
		if (keycode == 4)
			zoom_object_pos(rt->near_moove,type);
		if (keycode == 5)
			zoom_object_neg(rt->near_moove,type);
		mlx_destroy_image(rt->mlx_ptr, rt->img_ptr);
		rt->img_ptr = mlx_new_image(rt->mlx_ptr, rt->width, rt->height);
		ray_tracing(rt);
		mlx_put_image_to_window(rt->mlx_ptr, rt->win_ptr, rt->img_ptr, 0, 0);
	}
	return (0);
}