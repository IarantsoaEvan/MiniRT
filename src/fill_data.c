/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 08:56:30 by mrambelo          #+#    #+#             */
/*   Updated: 2025/01/15 14:31:38 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void print_ambiante(t_ambiante *ambiante)
{
	printf("ratio = %f\n",ambiante->ratio);
	printf("red = %d\n",ambiante->color->r);
	printf("green = %d\n",ambiante->color->r);
	printf("blue = %d\n",ambiante->color->r);
}

int check_color(int color)
{
	if (color >= 0 && color <= 255)
		return (1);
	return (0);
}

int check_vector_or_ratio(float vector,int type)
{
	if (type == RATIO)
	{
		if (vector >= 0.0 && vector <= 1.0)
			return (1);
		printf("Ratio must be between 0.0 - 1.0\n");
	}
	else
	{
		if (vector >= -1 && vector <= 1)
			return (1);
		printf("Vector must be between -1 - 1\n");
	}	
	return (0);
}

int check_and_fill_color(char **elem,t_color *color)
{
	if (elem)
	{
		color->r = ft_atoi(elem[0]);
		color->g = ft_atoi(elem[1]);
		color->b = ft_atoi(elem[2]);
		if (!check_color(color->r) || !check_color(color->g)
			|| !check_color(color->b))
		{
			printf("Color must be between 0 - 255\n");
			return (0);
		}	
	}
	return (1);
}

int fill_amb(t_ambiante **ambiante,char **element)
{
	int i;
	char **get_value;

	i = 0;
	get_value = NULL;
	(*ambiante) = init_amb();
	while (element[++i])
	{
		if (ft_count_char_in_str(element[i],','))
		{
			get_value = ft_split(element[i],',');
			if (!check_and_fill_color(get_value,(*ambiante)->color))
				return (0);
		}
		else
		{
			(*ambiante)->ratio = ft_atflo(element[i]);
			if (!check_vector_or_ratio((*ambiante)->ratio ,RATIO))
				return (0);
		}	
	}
	return (1);
}


int fill_cam(t_camera **cam,char **element)
{
	int i;
	char **get_val;
	
	i = 0;
	(*cam) = init_cam();
	while (element[i])
	{
		
	}
}