/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:28:07 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/18 13:11:45 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_color(int color)
{
	if (color >= 0 && color <= 255)
		return (1);
	return (0);
}

int	check_vec_or_rat(float vector, int type)
{
	if (type == RATIO)
	{
		if (vector >= 0.0 && vector <= 1.0)
			return (1);
		printf("Error\nRatio must be between 0.0 - 1.0\n");
	}
	else
	{
		if (vector >= -1.0 && vector <= 1.0)
			return (1);
		printf("Error\nVector must be between -1 - 1\n");
	}
	return (0);
}

int	check_and_fill_color(char *val, t_color *color)
{
	char	**elem;

	elem = NULL;
	if (!check_comma(val))
		return (0);
	elem = ft_split(val, ',');
	if (ft_count_world(elem) != 3)
		return (printf("Error\nColor must have 3 values\n"), ft_free_str(elem),
			0);
	if (elem)
	{
		color->r = ft_atflo(elem[0]);
		color->g = ft_atflo(elem[1]);
		color->b = ft_atflo(elem[2]);
		if (!check_color(color->r) || !check_color(color->g)
			|| !check_color(color->b))
		{
			printf("Error\nColor must be between 0 - 255\n");
			return (ft_free_str(elem), 0);
		}
	}
	if (elem)
		ft_free_str(elem);
	return (1);
}

int	fill_coord(char *val, t_coord *coord)
{
	char	**elem;

	elem = NULL;
	if (!check_comma(val))
		return (0);
	elem = ft_split(val, ',');
	if (ft_count_world(elem) != 3)
		return (printf("Error\n Coord or vector must have 3 values\n"),
			ft_free_str(elem), 0);
	if (elem)
	{
		coord->x = ft_atflo(elem[0]);
		coord->y = ft_atflo(elem[1]);
		coord->z = ft_atflo(elem[2]);
	}
	if (elem)
		ft_free_str(elem);
	return (1);
}

int	check_angle(float angle)
{
	if (angle >= 0 && angle <= 180)
		return (1);
	printf("Error\nAngle of the camera must be between 0 - 180\n");
	return (0);
}
