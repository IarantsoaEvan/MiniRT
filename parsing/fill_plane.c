/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:20:29 by mrambelo          #+#    #+#             */
/*   Updated: 2025/01/16 22:06:26 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int fill_pl_vector(char *element,t_plane **pl)
{
	if (!check_comma(element))
		return (0);
	fill_coord(element,(*pl)->vector);
	if (!check_vec_or_rat((*pl)->vector->x ,VECTOR)
		|| !check_vec_or_rat((*pl)->vector->y ,VECTOR)
		|| !check_vec_or_rat((*pl)->vector->z ,VECTOR))
		return (0);
	
	return (1);
}

int fill_elem_pl(t_plane **pl,char *element,int *flag)
{
	if (*flag == 0)
	{
		if (!fill_coord(element,(*pl)->coord))
			return (0);
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
		if (!check_and_fill_color(element,(*pl)->color))
			return (0);
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