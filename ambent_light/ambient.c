/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:08:35 by mrambelo          #+#    #+#             */
/*   Updated: 2025/01/27 14:19:44 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ambiente.h"

t_color	*apply_amb(t_color *col_obj, float ratio_amb)
{
	t_color *color;

	color = init_color();
	color->r = (col_obj->r / 255.0f) * ratio_amb;
	color->g = (col_obj->g / 255.0f) * ratio_amb;
	color->b = (col_obj->b / 255.0f) * ratio_amb;
	return (color);
}