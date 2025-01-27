/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse_object.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:34:55 by mrambelo          #+#    #+#             */
/*   Updated: 2025/01/27 14:36:34 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "diffuse_light.h"

t_coord *get_normal_sphere(t_data *rt,t_coord *point)
{
	t_coord *norm;

	norm = normalize_vector(ft_soustraction(point,rt->sphere->coord));
	return (norm);
}