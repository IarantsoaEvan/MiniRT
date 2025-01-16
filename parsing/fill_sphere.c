/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:20:19 by mrambelo          #+#    #+#             */
/*   Updated: 2025/01/16 12:43:17 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int fill_elem_sphere(t_sphere **sphere,char *element,int *flag)
{
	char **get_val;

	get_val = NULL;
	if (*flag == 0)
	{
		get_val = ft_split(element,',');
		fill_coord(get_val,(*sphere)->coord);
		ft_free_str(get_val);
		*flag = 1;
	}
	else if (*flag == 1)
	{
		(*sphere)->diam = ft_atflo(element);
		*flag = 2;
	}	
	else
	{
		get_val = ft_split(element,',');
		if (!check_and_fill_color(get_val,(*sphere)->color))
			return (ft_free_str(get_val),0);
		ft_free_str(get_val);
	}
	return (1);
}

int fill_sphere(t_sphere **sphere,char **elem)
{
	t_sphere *temp;
	int flag;
	int i;
	static int id;

	i = 0;
	flag = 0;
	temp = init_sphere();
	temp->id = id;
	while (elem[++i])
	{
		if (!fill_elem_sphere(&temp,elem[i],&flag))
			return (0);
	}
	ft_add_back_sphere(sphere,temp);
	id++;
	return (1);
}