/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 08:00:09 by mrambelo          #+#    #+#             */
/*   Updated: 2025/01/31 15:17:28 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shadow.h"

void	ray_shadowing(t_fct *fct, t_data *rt, float t)
{
	t_coord *impact;
	t_coord *ray_dir;

	impact = init_coord();
	impact = ft_addition(rt->cam->coord, ft_scal_one(fct->dir, t));

}