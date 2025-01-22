/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:04:58 by mrambelo          #+#    #+#             */
/*   Updated: 2025/01/22 08:55:05 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

float get_t_plane(t_fct *fct,t_data *rt)
{
    t_coord *xc;
    float t;

    xc = ft_soustraction(rt->cam->coord,rt->plane->coord);
    normalize_vector(rt->plane->vector);
    t = ((-1) * (ft_scal(xc,rt->plane->vector))) / ft_scal(fct->dir,rt->plane->vector);
    return (t);
}