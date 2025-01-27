/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:08:35 by mrambelo          #+#    #+#             */
/*   Updated: 2025/01/27 10:32:51 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ambiente.h"

t_color	*apply_amb(t_color *col_obj, float ratio_amb)
{
	t_color *color;

	color = init_color();
	color->r = col_obj->r * ratio_amb;
	color->g = col_obj->g * ratio_amb;
	color->b = col_obj->b * ratio_amb;
	return (color);
}