/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 22:04:37 by mrambelo          #+#    #+#             */
/*   Updated: 2025/01/16 13:10:21 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int fill_cam_vector(char *element,t_camera **cam)
{
	char **get_val;
	
	get_val = ft_split(element,',');
	fill_coord(get_val,(*cam)->vector);
	if (!check_vec_or_rat((*cam)->vector->x ,VECTOR)
		|| !check_vec_or_rat((*cam)->vector->y ,VECTOR)
		|| !check_vec_or_rat((*cam)->vector->z ,VECTOR))
		return (ft_free_str(get_val),0);
	
	return (ft_free_str(get_val),1);
}

int fill_cam_elem(t_camera **cam,char *element,int *flag)
{
	char ** get_val;

	get_val = NULL;
	if (*flag == 0)
	{
		get_val = ft_split(element,',');
		fill_coord(get_val,(*cam)->coord);
		ft_free_str(get_val);
		*flag = 1;
	}
	else if (*flag == 1)
	{
		if (!fill_cam_vector(element,cam))
			return (0);
		*flag = 2;
	}
	else
	{
		(*cam)->fov = ft_atflo(element);
		ft_free_str(get_val);
		return (check_angle((*cam)->fov));
	}
	return (1);
}

int fill_cam(t_camera **cam,char **element)
{
	int i;
	int flag;
	static int nb_cam;
	
	i = 0;
	flag = 0;
	if (nb_cam != 0)
		return (printf("Please enter only one cam!\n"),0);
	(*cam) = init_cam();
	while (element[++i])
	{
		if (!fill_cam_elem(cam,element[i],&flag))
			return (0);
	}
	nb_cam++;
	return (1);
}