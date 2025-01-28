/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:36:21 by mrambelo          #+#    #+#             */
/*   Updated: 2025/01/24 10:57:20 by irabesan         ###   ########.fr       */
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
	cam->rad_fov = 0;
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
t_plane *init_plane(void)
{
	t_plane *plane;

	plane = malloc(sizeof(t_plane));
	plane->coord = init_coord();
	plane->color = init_color();
	plane->vector = init_coord();
	plane->id = 0;
	plane->next = NULL;
	return (plane);
}
t_sphere *init_sphere(void)
{
	t_sphere *sphere;

	sphere = malloc(sizeof(t_sphere));
	sphere->coord = init_coord();
	sphere->color = init_color();
	sphere->diam = 0;
	sphere->id = 0;
	sphere->next = NULL;
	return (sphere);
}

t_cyl *init_cyl(void)
{
	t_cyl *cyl;

	cyl = malloc(sizeof(t_cyl));
	cyl->color = init_color();
	cyl->coord = init_coord();
	cyl->vector = init_coord();
	cyl->diam = 0;
	cyl->height = 0;
	cyl->id = 0;
	cyl->next = NULL;
	return (cyl);
}

t_data *init_data(void)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	data->ambiante = NULL;
	data->cam = NULL;
	data->light =  NULL;
	data->plane = NULL;
	data->sphere = NULL;
	data->cyl = NULL;
	data->width = 700;
	data->height = 540;
	return (data);
}