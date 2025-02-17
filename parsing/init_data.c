/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:36:21 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/17 20:18:51 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_light	*init_light(void)
{
	t_light	*light;

	light = malloc(sizeof(t_light));
	light->color = init_color();
	light->coord = init_coord();
	light->ratio = 0;
	return (light);
}

t_plane	*init_plane(void)
{
	t_plane	*plane;

	plane = malloc(sizeof(t_plane));
	plane->coord = init_coord();
	plane->color = init_color();
	plane->vector = init_coord();
	plane->id = 0;
	plane->next = NULL;
	return (plane);
}

t_sphere	*init_sphere(void)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	sphere->coord = init_coord();
	sphere->color = init_color();
	sphere->diam = 0;
	sphere->id = 1000;
	sphere->next = NULL;
	return (sphere);
}

t_cyl	*init_cyl(void)
{
	t_cyl	*cyl;

	cyl = malloc(sizeof(t_cyl));
	cyl->color = init_color();
	cyl->coord = init_coord();
	cyl->vector = init_coord();
	cyl->diam = 0;
	cyl->disk_top = malloc(sizeof(t_plane));
	cyl->disk_top->coord = NULL;
	cyl->disk_top->vector = NULL;
	cyl->disk_bot = malloc(sizeof(t_plane));
	cyl->disk_bot->coord = NULL;
	cyl->disk_bot->vector = NULL;
	cyl->m = 0;
	cyl->height = 0;
	cyl->id = 2000;
	cyl->next = NULL;
	return (cyl);
}

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->ambiante = NULL;
	data->cam = NULL;
	data->light = NULL;
	data->plane = NULL;
	data->sphere = NULL;
	data->cyl = NULL;
	data->width = 650;
	data->height = 490;
	data->near = NULL;
	data->flag_rot_x = 0;
	data->flag_rot_y = 0;
	data->flag_rot_z = 0;
	data->flag_cam = 0;
	data->flag_camx = 0;
	data->flag_camy = 0;
	data->flag_camz = 0;
	data->flag_radius = 0;
	data->flag_rdisk = 0;
	// data->alpha = 0.0;
	// data->beta = 0.0;
	// data->flag_spec = 0;
	// data->teta = 0.0;
	// data->alpha_cam = 0.0;
	// data->beta_cam = 0.0;
	// data->teta_cam = 0.0;
	data->flag_hcyl = 0;
	init_flt_data(data);
	return (data);
}
