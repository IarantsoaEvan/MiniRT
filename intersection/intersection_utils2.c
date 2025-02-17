/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:04:38 by irabesan          #+#    #+#             */
/*   Updated: 2025/02/17 09:05:50 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

void	init_current_sp(t_nearest *sp_current, t_sphere *sphere)
{
	sp_current->near_obj = sphere;
	sp_current->type = SPHERE;
	sp_current->id = sphere->id;
}
