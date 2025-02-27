/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:20:29 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/27 10:29:22 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	fill_pl_vector(char *element, t_plane **pl)
{
	if (!check_comma(element))
		return (0);
	if (!fill_coord(element, (*pl)->vector))
		return (0);
	if (!check_vec_or_rat((*pl)->vector->x, VECTOR)
		|| !check_vec_or_rat((*pl)->vector->y, VECTOR)
		|| !check_vec_or_rat((*pl)->vector->z, VECTOR))
		return (0);
	return (1);
}

int	fill_elem_pl(t_plane **pl, char *element, int *flag)
{
	if (*flag == 0)
	{
		if (!fill_coord(element, (*pl)->coord))
			return (0);
		*flag = 1;
	}
	else if (*flag == 1)
	{
		if (!fill_pl_vector(element, pl))
			return (0);
		*flag = 2;
	}
	else
	{
		if (!check_and_fill_color(element, (*pl)->color))
			return (0);
	}
	return (1);
}

int	fill_plane(t_plane **pl, char **elem, t_data *data)
{
	static int	id;
	t_plane		*temp;
	int			flag;
	int			i;
	int			len;

	i = 0;
	flag = 0;
	temp = init_plane();
	if (ft_count_world(elem) != 4)
		return (printf("Error\nInvalid plane element\n"), free_data(data),
			free_plane(temp), 0);
	temp->id = temp->id + id;
	while (elem[++i])
	{
		len = ft_strlen(elem[i]);
		if (!ft_isdigit(elem[i][len - 1]) || (elem[i][0] == '.'
				|| elem[i][0] == ','))
			return (printf("Error\nInvalid plane element\n"), free_data(data),
				free_plane(temp), 0);
		if (!fill_elem_pl(&temp, elem[i], &flag))
			return (free_data(data), free_plane(temp), 0);
	}
	return (ft_add_back_plane(pl, temp), id++, 1);
}
