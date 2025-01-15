/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 22:40:29 by mrambelo          #+#    #+#             */
/*   Updated: 2025/01/15 22:41:06 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_color *init_color(void)
{
	t_color *color;
	
	color = malloc(sizeof(t_color));
	color->r = 0;
	color->g = 0;
	color->b = 0;
	return (color);
}
t_coord *init_coord(void)
{
	t_coord *coord;
	
	coord = malloc(sizeof(t_coord));
	coord->x = 0;
	coord->y = 0;
	coord->z = 0;
	return (coord);
}
t_ambiante *init_amb(void)
{
	t_ambiante *amb;

	amb = malloc(sizeof(t_ambiante));
	amb->color = init_color();
	amb->ratio = 0;
	return (amb);
}