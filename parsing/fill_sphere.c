/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:20:19 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/17 09:28:45 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	fill_elem_sphere(t_sphere **sphere, char *element, int *flag)
{
	if (*flag == 0)
	{
		if (!fill_coord(element, (*sphere)->coord))
			return (0);
		*flag = 1;
	}
	else if (*flag == 1)
	{
		(*sphere)->diam = ft_atflo(element);
		if (!check_positive((*sphere)->diam))
			return (0);
		*flag = 2;
	}
	else
	{
		if (!check_and_fill_color(element, (*sphere)->color))
			return (0);
	}
	return (1);
}

int	fill_sphere(t_sphere **sphere, char **elem)
{
	static int	id;
	t_sphere	*temp;
	int			flag;
	int			i;

	i = 0;
	flag = 0;
	temp = init_sphere();
	temp->id = temp->id + id;
	while (elem[++i])
	{
		if (!fill_elem_sphere(&temp, elem[i], &flag))
			return (0);
	}
	ft_add_back_sphere(sphere, temp);
	id++;
	return (1);
}
