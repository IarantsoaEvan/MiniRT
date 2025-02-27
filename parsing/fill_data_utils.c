/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:28:07 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/27 10:45:54 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_color(float color)
{
	if (color >= 0.000f && color <= 255.0000f)
		return (1);
	return (0);
}

int	check_vec_or_rat(float vector, int type)
{
	if (type == RATIO)
	{
		if (vector >= 0.000f && vector <= 1.000f)
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
	if (!check_excat_val(elem))
		return (printf("Error\nInvalid color element\n"), ft_free_str(elem), 0);
	if (ft_count_world(elem) != 3)
		return (printf("Error\nColor must have 3 values\n"), ft_free_str(elem),
			0);
	if (elem)
	{
		if (check_int_color(elem[0]) == 0 || check_int_color(elem[1]) == 0
			|| check_int_color(elem[2]) == 0)
			return (printf("Error\nPlease check the colors values\n"),
				ft_free_str(elem), 0);
		fill_rgb_color(color, elem);
		if (!check_color(color->r) || !check_color(color->g)
			|| !check_color(color->b))
			return (printf("Error\nColor must be between 0 - 255\n"),
				ft_free_str(elem), 0);
	}
	check_free_element(elem);
	return (1);
}

int	fill_coord(char *val, t_coord *coord)
{
	char	**elem;

	elem = NULL;
	if (!check_comma(val))
		return (0);
	elem = ft_split(val, ',');
	if (!check_excat_val(elem))
		return (printf("Error\nInvalid coord or vector element\n"),
			ft_free_str(elem), 0);
	if (ft_count_world(elem) != 3)
		return (printf("Error\n Coord or vector must have 3 values\n"),
			ft_free_str(elem), 0);
	if (elem)
	{
		if (check_float(elem[0]) == 0 || check_float(elem[1]) == 0
			|| check_float(elem[2]) == 0)
			return (printf("Error\n Please check the coord or vector values\n"),
				ft_free_str(elem), 0);
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
