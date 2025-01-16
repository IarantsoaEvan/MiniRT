/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:20:29 by mrambelo          #+#    #+#             */
/*   Updated: 2025/01/16 11:52:10 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int fill_pl_vector(char *element,t_plane **pl)
{
	char **get_val;
	
	get_val = ft_split(element,',');
	fill_coord(get_val,(*pl)->vector);
	if (!check_vec_or_rat((*pl)->vector->x ,VECTOR)
		|| !check_vec_or_rat((*pl)->vector->y ,VECTOR)
		|| !check_vec_or_rat((*pl)->vector->z ,VECTOR))
		return (ft_free_str(get_val),0);
	
	return (ft_free_str(get_val),1);
}

int fill_elem_pl(t_plane **pl,char *element,int *flag)
{
	char **get_val;

	get_val = NULL;
	if (*flag == 0)
	{
			get_val = ft_split(element,',');
			fill_coord(get_val,(*pl)->coord);
			ft_free_str(get_val);
			*flag = 1;
	}
	else if (*flag == 1)
	{
			if (!fill_pl_vector(element,pl))
				return (0);
			*flag = 2;
	}
	else
	{
			get_val = ft_split(element,',');
			if (!check_and_fill_color(get_val,(*pl)->color))
				return (ft_free_str(get_val),0);
			ft_free_str(get_val);
	}
	return (1);
}

int fill_plane(t_plane **pl,char **elem)
{
	t_plane *temp;
	int flag;
	static int id;
	int i;

	i = 0;
	flag = 0;
	temp = init_plane();
	temp->id = id;
	while (elem[++i])
	{
		if (!fill_elem_pl(&temp,elem[i],&flag))
			return (0);
	}
	ft_add_back_plane(pl,temp);
	id++;
	return (1);
}