/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse_object.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:34:55 by mrambelo          #+#    #+#             */
/*   Updated: 2025/01/28 14:20:12 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "diffuse_light.h"

t_coord *get_normal_sphere(t_coord *point,t_sphere *sphere)
{
	t_coord *norm;

	norm = normalize_vector(ft_soustraction(point,sphere->coord));
	return (norm);
}

t_coord	*get_normal_cyl(t_data *rt, t_coord *point, float m)
{
	t_coord	*norm;
	t_coord	*norm_vec;
	t_coord	*vm;

	norm_vec = normalize_vector(rt->cyl->vector);
	vm = ft_scal_one(norm_vec, m);
	norm = normalize_vector(ft_soustraction(point, ft_soustraction(rt->cyl->coord, vm)));
	return (norm);
}