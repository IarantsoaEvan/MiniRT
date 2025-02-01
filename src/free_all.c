/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:57:09 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/01 22:15:51 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_sphere(t_sphere *sphere)
{
	t_sphere *tmp_sp;

	while (sphere)
	{
		tmp_sp = sphere;
		sphere = sphere->next;
		free(tmp_sp->coord);
		free(tmp_sp->color);
		// free(tmp_sp->normal);
		free(tmp_sp);
	}

}

void free_plane(t_plane *plane)
{
	t_plane *tmp_pl;

	while (plane)
	{
		tmp_pl = plane;
		plane = plane->next;
		free(tmp_pl->coord);
		free(tmp_pl->color);
		free(tmp_pl->vector);
		free(tmp_pl);
	}
}

void free_cyl(t_cyl *cyl)
{
	t_cyl *tmp_cyl;

	while (cyl)
	{
		tmp_cyl = cyl;
		cyl = cyl->next;
		free(tmp_cyl->coord);
		free(tmp_cyl->color);
		free(tmp_cyl->disk);
		free(tmp_cyl->vector);
		free(tmp_cyl);
	}
}

void free_light_cam_amb(t_data *data)
{
	free(data->light->coord);
	free(data->light->color);
	// free(data->light->normal);
	free(data->light);
	// free(data->cam->cam_right);
	// free(data->cam->cam_up);
	free(data->cam->coord);
	free(data->cam->vector);
	free(data->cam);
	free(data->ambiante->color);
	free(data->ambiante);

}
void free_all(t_data *data)
{
	if (data->sphere)
		free_sphere(data->sphere);
	if (data->plane)
		free_plane(data->plane);
	if (data->cyl)
		free_cyl(data->cyl);
	free_light_cam_amb(data);
	free(data->near);
	free(data->mlx_ptr);
	// free(data->win_ptr);
	// free(data->img_ptr);
	free(data);
}
