/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:36:21 by mrambelo          #+#    #+#             */
/*   Updated: 2025/01/15 22:42:00 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_camera *init_cam(void)
{
	t_camera *cam;

	cam = malloc(sizeof(t_camera));
	cam->coord = init_coord();
	cam->vector = init_coord();
	cam->fov = 0;
	return (cam);
}

t_light *init_light(void)
{
	t_light *light;

	light = malloc(sizeof(t_light));
	light->color = init_color();
	light->coord = init_coord();
	light->ratio = 0;
	return (light);
}

t_data *init_data(void)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	data->ambiante = NULL;
	data->cam = NULL;
	data->light =  NULL;
	// data->plane = init_plane();
	// data->sphere = init_sphere();
	// data->cyl = init_cyl();
	return (data);
}