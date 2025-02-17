/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 08:56:30 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/17 09:26:44 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	fill_elem_light(char *elem, t_light **light, int *flag)
{
	if (*flag == 0)
	{
		if (!fill_coord(elem, (*light)->coord))
			return (0);
		*flag = 1;
	}
	else if (*flag == 1)
	{
		(*light)->ratio = ft_atflo(elem);
		if (!check_vec_or_rat((*light)->ratio, RATIO))
			return (0);
		*flag = 2;
	}
	else
	{
		if (!check_and_fill_color(elem, (*light)->color))
			return (0);
	}
	return (1);
}

int	fill_light(t_light **light, char **elem)
{
	int	flag;
	int	i;

	flag = 0;
	i = 0;
	*light = init_light();
	while (elem[++i])
	{
		if (!fill_elem_light(elem[i], light, &flag))
			return (0);
	}
	return (1);
}

int	fill_amb_elem(char *element, t_ambiante **ambiante)
{
	if (ft_count_char_in_str(element, ','))
	{
		if (!check_and_fill_color(element, (*ambiante)->color))
			return (0);
	}
	else
	{
		(*ambiante)->ratio = ft_atflo(element);
		if (!check_vec_or_rat((*ambiante)->ratio, RATIO))
			return (0);
	}
	return (1);
}

int	fill_amb(t_ambiante **ambiante, char **element)
{
	int	i;

	i = 0;
	*ambiante = init_amb();
	while (element[++i])
	{
		if (!fill_amb_elem(element[i], ambiante))
			return (0);
	}
	return (1);
}
