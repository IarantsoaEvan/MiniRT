/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:30:50 by irabesan          #+#    #+#             */
/*   Updated: 2025/02/17 11:28:50 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_nearest	*init_nearest(void)
{
	t_nearest	*near;

	near = malloc(sizeof(t_nearest));
	near->near_obj = NULL;
	near->t_near = 0;
	near->type = -1;
	return (near);
}

t_camera	*init_cam(void)
{
	t_camera	*cam;

	cam = malloc(sizeof(t_camera));
	cam->coord = init_coord();
	cam->vector = init_coord();
	cam->fov = 0;
	cam->rad_fov = 0;
	return (cam);
}

// void	init_flt_data(t_data *data)
// {
// 	data->alpha = 0.0;
// 	data->beta = 0.0;
// 	data->flag_spec = 0;
// 	data->teta = 0.0;
// 	data->alpha_cam = 0.0;
// 	data->beta_cam = 0.0;
// 	data->teta_cam = 0.0;
// }
