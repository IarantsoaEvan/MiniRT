/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_cylindre.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:06:43 by mrambelo          #+#    #+#             */
/*   Updated: 2025/01/16 13:25:19 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int fill_cyl_vector(char *element,t_cyl **cyl)
{
	char **get_val;
	
	get_val = ft_split(element,',');
	fill_coord(get_val,(*cyl)->vector);
	if (!check_vec_or_rat((*cyl)->vector->x ,VECTOR)
		|| !check_vec_or_rat((*cyl)->vector->y ,VECTOR)
		|| !check_vec_or_rat((*cyl)->vector->z ,VECTOR))
		return (ft_free_str(get_val),0);
	
	return (ft_free_str(get_val),1);
}

int fill_diam_and_height(int *flag,t_cyl **cyl,char *element)
{
	if (*flag == 1)
	{
		if (!fill_cyl_vector(element,cyl))
			return (0);
		*flag = 2;
	}	
	else if (*flag == 2)
	{
		(*cyl)->diam = ft_atflo(element);
		if (!check_positive((*cyl)->diam))
			return (0);
		*flag = 3;
	}
	else if (*flag == 3)
	{
		(*cyl)->height = ft_atflo(element);
		if (!check_positive((*cyl)->height))
			return (0);
		*flag = 4;
	}
	return (1);
}

int fill_elem_cyl(t_cyl **cyl,char *element,int *flag)
{
	char **get_val;

	get_val = NULL;
	if (*flag == 0)
	{
		get_val = ft_split(element,',');
		fill_coord(get_val,(*cyl)->coord);
		ft_free_str(get_val);
		*flag = 1;
	}
	else if (*flag == 1 || *flag == 2 || *flag == 3)
	{
		if (!fill_diam_and_height(flag,cyl,element))
			return (0);
	}	
	else
	{
		get_val = ft_split(element,',');
		if (!check_and_fill_color(get_val,(*cyl)->color))
			return (ft_free_str(get_val),0);
		ft_free_str(get_val);
	}
	return (1);
}

int fill_cyl(t_cyl **cyl,char **elem)
{
	t_cyl *temp;
	int flag;
	int i;
	static int id;

	i = 0;
	flag = 0;
	temp = init_cyl();
	temp->id = id;
	while (elem[++i])
	{
		if (!fill_elem_cyl(&temp,elem[i],&flag))
			return (0);
	}
	ft_add_back_cyl(cyl,temp);
	id++;
	return (1);
}