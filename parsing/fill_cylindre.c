/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_cylindre.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:06:43 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/25 11:00:05 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	fill_cyl_vector(char *element, t_cyl **cyl)
{
	if (!check_comma(element))
		return (0);
	if (!fill_coord(element, (*cyl)->vector))
		return (0);
	if (!check_vec_or_rat((*cyl)->vector->x, VECTOR)
		|| !check_vec_or_rat((*cyl)->vector->y, VECTOR)
		|| !check_vec_or_rat((*cyl)->vector->z, VECTOR))
		return (0);
	return (1);
}

int	fill_diam_and_height(int *flag, t_cyl **cyl, char *element)
{
	if (*flag == 1)
	{
		if (!fill_cyl_vector(element, cyl))
			return (0);
		*flag = 2;
	}
	else if (*flag == 2)
	{
		if (check_float(element) == 0)
			return (printf("Error\nInvalid cyl diameter\n"), 0);
		(*cyl)->diam = ft_atflo(element);
		if (!check_positive((*cyl)->diam))
			return (0);
		*flag = 3;
	}
	else if (*flag == 3)
	{
		if (check_float(element) == 0)
			return (printf("Error\nInvalid cyl heigth\n"), 0);
		(*cyl)->height = ft_atflo(element);
		if (!check_positive((*cyl)->height))
			return (0);
		*flag = 4;
	}
	return (1);
}

int	fill_elem_cyl(t_cyl **cyl, char *element, int *flag)
{
	if (*flag == 0)
	{
		if (!fill_coord(element, (*cyl)->coord))
			return (0);
		*flag = 1;
	}
	else if (*flag == 1 || *flag == 2 || *flag == 3)
	{
		if (!fill_diam_and_height(flag, cyl, element))
			return (0);
	}
	else
	{
		if (!check_and_fill_color(element, (*cyl)->color))
			return (0);
	}
	return (1);
}

int	fill_cyl(t_cyl **cyl, char **elem, t_data *data)
{
	static int	id;
	t_cyl		*temp;
	int			flag;
	int			i;
	int			len;

	i = 0;
	flag = 0;
	temp = init_cyl();
	if (ft_count_world(elem) != 6)
		return (printf("Error\nInvalid cyl element\n"), free_data(data),
			free_cyl(temp), 0);
	temp->id = temp->id + id;
	while (elem[++i])
	{
		len = ft_strlen(elem[i]);
		if (!ft_isdigit(elem[i][len - 1]) || (elem[i][0] == '.'
				|| elem[i][0] == ','))
			return (printf("Error\nInvalid cyl element\n"), free_data(data),
				free_cyl(temp), 0);
		if (!fill_elem_cyl(&temp, elem[i], &flag))
			return (free_data(data), free_cyl(temp), 0);
	}
	ft_add_back_cyl(cyl, temp);
	return (id++, 1);
}
