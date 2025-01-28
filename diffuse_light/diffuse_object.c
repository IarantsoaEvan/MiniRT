/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse_object.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:34:55 by mrambelo          #+#    #+#             */
/*   Updated: 2025/01/28 19:10:40 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "diffuse_light.h"

t_coord *get_normal_sphere(t_coord *point,t_sphere *sphere)
{
	t_coord *norm;

	norm = normalize_vector(ft_soustraction(point,sphere->coord));
	return (norm);
}

t_coord	*get_normal_cyl(t_data *rt, t_coord *point, t_cyl *cyl)
{
	t_coord	*norm;
	t_coord	*norm_vec;
	t_coord	*vm;

	(void)rt;
	norm_vec = normalize_vector(cyl->vector);
	vm = ft_scal_one(norm_vec, cyl->m);
	norm = normalize_vector(ft_soustraction(point, ft_soustraction(cyl->coord, vm)));
	return (norm);
}