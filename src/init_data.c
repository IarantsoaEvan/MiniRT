/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:36:21 by mrambelo          #+#    #+#             */
/*   Updated: 2025/01/15 14:11:37 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color *init_color(void)
{
	t_color *color;
	
	color = malloc(sizeof(t_color));
	color->r = 0;
	color->g = 0;
	color->b = 0;
	return (color);
}
t_coord *init_coord(void)
{
	t_coord *coord;
	
	coord = malloc(sizeof(t_coord));
	coord->x = 0;
	coord->y = 0;
	coord->z = 0;
	return (coord);
}
t_ambiante *init_amb(void)
{
	t_ambiante *amb;

	amb = malloc(sizeof(t_ambiante));
	amb->color = init_color();
	amb->ratio = 0;
	return (amb);
}
t_camera *init_cam(void)
{
	t_camera *cam;

	cam = malloc(sizeof(t_camera));
	cam->coord = init_coord();
	cam->vector = init_coord();
	cam->fov = 0;
	return (cam);
}

t_data *init_data(void)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	data->ambiante = NULL;
	data->cam = NULL;
	// data->light = init_light();
	// data->plane = init_plane();
	// data->sphere = init_sphere();
	// data->cyl = init_cyl();
	return (data);
}