/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:04:38 by irabesan          #+#    #+#             */
/*   Updated: 2025/02/27 10:44:44 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

void	init_current_sp(t_nearest *sp_current, t_sphere *sphere)
{
	sp_current->near_obj = sphere;
	sp_current->type = SPHERE;
	sp_current->id = sphere->id;
}

void	check_scal_nl(float scal_nl, t_rgb *rgb, t_color *spec)
{
	if (scal_nl < 0)
		rgb->rgb_finale = apply_shadow_color(rgb->color);
	else
		rgb->rgb_finale = add_amb_and_diff(rgb->color, rgb->rgb_diff, spec);
}

void	init_current_pl(t_nearest *pl_current, t_plane *plane)
{
	pl_current->near_obj = plane;
	pl_current->type = PLANE;
	pl_current->id = plane->id;
}

void	check_free_element(char **element)
{
	if (element)
		ft_free_str(element);
}

void	free_n_close(int fd, char *g_map)
{
	free(g_map);
	close(fd);
}
