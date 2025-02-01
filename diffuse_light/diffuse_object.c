/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse_object.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:34:55 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/01 21:22:09 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "diffuse_light.h"

t_coord *get_normal_sphere(t_coord *point,t_sphere *sphere)
{
	t_coord *norm;

	norm = normalize_vector_with_free(ft_soustraction(point,sphere->coord));
	return (norm);
}

t_coord	*get_normal_cyl(t_data *rt, t_coord *point, t_cyl *cyl)
{
	t_coord	*norm;
	t_coord	*norm_vec;
	t_coord	*vm;
	t_coord	*sous_vec;

	(void)rt;
	norm_vec = normalize_vector(cyl->vector);
	vm = ft_scal_one(norm_vec, cyl->m);
	sous_vec = ft_soustraction(cyl->coord, vm);
	norm = normalize_vector_with_free(ft_soustraction(point, sous_vec));
	free(sous_vec);
	free(vm);
	free(norm_vec);
	return (norm);
}