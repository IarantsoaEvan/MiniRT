/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 22:04:37 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/20 22:09:22 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	fill_cam_vector(char *element, t_camera **cam)
{
	if (!check_comma(element))
		return (0);
	if (!fill_coord(element, (*cam)->vector))
		return (0);
	if (!check_vec_or_rat((*cam)->vector->x, VECTOR)
		|| !check_vec_or_rat((*cam)->vector->y, VECTOR)
		|| !check_vec_or_rat((*cam)->vector->z, VECTOR))
		return (0);
	return (1);
}

int	fill_cam_elem(t_camera **cam, char *element, int *flag)
{
	if (*flag == 0)
	{
		if (!fill_coord(element, (*cam)->coord))
			return (0);
		*flag = 1;
	}
	else if (*flag == 1)
	{
		if (!fill_cam_vector(element, cam))
			return (0);
		*flag = 2;
	}
	else
	{
		(*cam)->fov = ft_atflo(element);
		(*cam)->rad_fov = (*cam)->fov * (M_PI / 180);
		return (check_angle((*cam)->fov));
	}
	return (1);
}

int	fill_cam(t_camera **cam, char **element, t_data *data)
{
	int	i;
	int	flag;
	int len;
	
	flag = 0;
	i = 0;
	(*cam) = init_cam();
	while (element[++i])
	{
		len = ft_strlen(element[i]);
		if (!ft_isdigit(element[i][len - 1]) || (element[i][0] == '.' || element[i][0] == ','))
			return (printf("Error\nInvalid cam element\n"),free_data(data), 0);
		if (!fill_cam_elem(cam, element[i], &flag))
			return (free_data(data), 0);
	}
	return (1);
}
