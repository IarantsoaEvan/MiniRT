/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 09:43:25 by irabesan          #+#    #+#             */
/*   Updated: 2025/02/05 14:59:38 by irabesan         ###   ########.fr       */
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
		free(rt);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	select_obj(t_data *rt, int x, int y,t_nearest *near)
{
	t_fct fct;

	near->near_obj = NULL;
	if (y < rt->height && x < rt->width)
	{
		ft_set_cfct(&fct, (float)x, (float)y, rt);
		printf("--------------------------------\n");
		intersec_obj(&fct, rt,near);
		printf("--------------------------------\n");
		if (near)
			printf("%d\n", near->type);
		if (near->t_near > 0 && near->near_obj
			&& near->type == SPHERE)
			return (SPHERE);
		if (near->t_near > 0 && near->near_obj
			&& near->type == PLANE)
			return (PLANE);
		if (near->t_near > 0 && near->near_obj
			&& near->type == CYL)
			return (CYL);
	}
	return (-1);
}
void zoom_object_pos(t_nearest *near,int type,int keycode)
{
	t_sphere *sphere;
	t_plane *plane;
	t_cyl *cyl;
	
	if (keycode == 4)
	{
		if (type == SPHERE)
		{
			sphere = near->near_obj;
			sphere->coord->z = sphere->coord->z + 1;
		}
		if (type == PLANE)
		{
			plane = near->near_obj;
			plane->coord->z += 0.2;
		}
		if (type == CYL)
		{
			cyl = near->near_obj;
			cyl->coord->z += 0.2;
		}

	}
}
int mouse_handler(int keycode , int x, int y, t_data *rt)
{
	int type;
	// (void)x;
	// t_sphere *tmp;
	// (void)y;
	t_nearest near;


	if (keycode == 1)
		type = select_obj(rt,  x,  y, &near);
	// sphere = rt->sphere;
	// tmp = near->near_obj;
	// while (sphere)
	// {
	// 	if (sphere->id == tmp->id)
	// 		break;
	// 	sphere = sphere->next;
	// }
	
	// printf("avant sphere->coord->x = %f\n",sphere->coord->x);
	if (keycode == 4)
	{
		// tmp->coord->x -= 0.5;
		// printf("apres sphere->coord->x = %f\n\n",sphere->coord->x);
		// printf("ato\n");
		zoom_object_pos(&near, near.type, keycode);
		// mlx_clear_window(rt->mlx_ptr, rt->win_ptr);
		mlx_destroy_image(rt->mlx_ptr, rt->img_ptr);
		rt->img_ptr = mlx_new_image(rt->mlx_ptr, rt->width, rt->height);
		ray_tracing(rt);
		mlx_put_image_to_window(rt->mlx_ptr, rt->win_ptr, rt->img_ptr, 0, 0);
	}
	return (0);
}