/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 08:00:09 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/01 13:03:35 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shadow.h"

void	ray_shadowing(t_fct *fct, t_data *rt, t_coord *impact)
{
	t_vect ray;
	float	direction;

	direction = 0.0;
	ray.origin = &impact;
	ray.direction = normalize_vector(ft_soustraction(rt->light->coord, impact));

	

}