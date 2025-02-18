/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:57:09 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/18 12:34:47 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_sphere(t_sphere *sphere)
{
	t_sphere	*tmp_sp;

	while (sphere)
	{
		tmp_sp = sphere;
		sphere = sphere->next;
		if (tmp_sp->coord)
			free(tmp_sp->coord);
		if (tmp_sp->color)
			free(tmp_sp->color);
		if (tmp_sp)
			free(tmp_sp);
	}
}

void	free_plane(t_plane *plane)
{
	t_plane	*tmp_pl;

	while (plane)
	{
		tmp_pl = plane;
		plane = plane->next;
		if (tmp_pl->coord)
			free(tmp_pl->coord);
		if (tmp_pl->color)
			free(tmp_pl->color);
		if (tmp_pl->vector)
			free(tmp_pl->vector);
		free(tmp_pl);
	}
}

void	free_cyl(t_cyl *cyl)
{
	t_cyl	*tmp_cyl;

	while (cyl)
	{
		tmp_cyl = cyl;
		cyl = cyl->next;
		free(tmp_cyl->coord);
		free(tmp_cyl->color);
		if (tmp_cyl->disk_top)
			free_disk(tmp_cyl->disk_top);
		if (tmp_cyl->disk_bot)
			free_disk(tmp_cyl->disk_bot);
		if (tmp_cyl->vector)
			free(tmp_cyl->vector);
		if (tmp_cyl)
			free(tmp_cyl);
	}
}

void	free_light_cam_amb(t_data *data)
{
	if (data->light->coord)
		free(data->light->coord);
	if (data->light->color)
		free(data->light->color);
	if (data->light)
		free(data->light);
	if (data->cam->coord)
		free(data->cam->coord);
	if (data->cam->vector)
		free(data->cam->vector);
	if (data->cam)
		free(data->cam);
	if (data->ambiante->color)
		free(data->ambiante->color);
	if (data->ambiante)
		free(data->ambiante);
}

void	free_all(t_data *data)
{
	if (data->sphere)
		free_sphere(data->sphere);
	if (data->plane)
		free_plane(data->plane);
	if (data->cyl)
		free_cyl(data->cyl);
	free_light_cam_amb(data);
	if (data->mlx_ptr)
		free(data->mlx_ptr);
	if (data)
		free(data);
}
