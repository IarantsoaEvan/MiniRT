/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 08:00:09 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/03 09:33:29 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shadow.h"

void	ray_shadowing(t_fct *fct, t_data *rt, t_coord *impact)
{
	t_vect ray;
	float	l_dist;
	t_coord *tmp_dir;

	ray.origin = impact;
	ray.direction = ft_soustraction(rt->light->coord, impact);
	tmp_dir = ft_soustraction(rt->light->coord, impact);
	l_dist = lenght_vector(tmp_dir);	 
}