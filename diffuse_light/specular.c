/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:23:12 by irabesan          #+#    #+#             */
/*   Updated: 2025/02/18 13:51:42 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "diffuse_light.h"

static void	free_blinn(t_blinn *blinn)
{
	free(blinn->obj_normal);
	free(blinn->ort_light);
	free(blinn->opp_cam);
	free(blinn->biss);
}

float	set_spec_sph(t_data *rt, t_nearest *object, t_coord *impact, t_fct *fct)
{
	float	l_sph;
	t_blinn	blinn;
	t_plane	*plane;
	float	prod;

	if (object->type == SPHERE)
		blinn.obj_normal = get_normal_sphere(impact,
				(t_sphere *)object->near_obj);
	if (object->type == CYL)
		blinn.obj_normal = get_normal_cyl(rt, impact,
				(t_cyl *)object->near_obj);
	if (object->type == PLANE)
	{
		plane = (t_plane *)object->near_obj;
		blinn.obj_normal = ft_scal_one(plane->vector, 1.0);
	}
	blinn.ort_light = normalize_vector_with_free(ft_soustraction(
				rt->light->coord, impact));
	blinn.opp_cam = ft_scal_one(fct->dir, -1.0);
	blinn.biss = normalize_vector_with_free(vect_add(blinn.opp_cam,
				blinn.ort_light));
	prod = powf(ft_scal(blinn.obj_normal, blinn.biss), 80.0f);
	l_sph = prod * 0.9 * 0.356;
	return (free_blinn(&blinn), l_sph);
}

t_color	*get_specular(t_data *rt, t_nearest *object, t_coord *impact,
		t_fct *fct)
{
	t_color	*color;
	float	spec;

	color = init_color();
	spec = set_spec_sph(rt, object, impact, fct);
	color->r = spec * rt->light->color->r * rt->light->ratio;
	color->g = spec * rt->light->color->g * rt->light->ratio;
	color->b = spec * rt->light->color->b * rt->light->ratio;
	return (color);
}
