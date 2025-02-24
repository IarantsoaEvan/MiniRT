/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 08:56:30 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/20 22:19:48 by mrambelo         ###   ########.fr       */
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

int	fill_light(t_light **light, char **elem, t_data *data)
{
	int	flag;
	int	i;
	int	len;

	flag = 0;
	i = 0;
	*light = init_light();
	while (elem[++i])
	{
		len = ft_strlen(elem[i]);
		if (!ft_isdigit(elem[i][len - 1]) || (elem[i][0] == '.'
				|| elem[i][0] == ','))
			return (printf("Error\nInvalid light element\n"), free_data(data),
				0);
		if (!fill_elem_light(elem[i], light, &flag))
			return (free_data(data), 0);
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

int	fill_amb(t_ambiante **ambiante, char **element, t_data *data)
{
	int	i;
	int	len;

	i = 0;
	*ambiante = init_amb();
	while (element[++i])
	{
		len = ft_strlen(element[i]);
		if (!ft_isdigit(element[i][len - 1]) || (element[i][0] == '.'
				|| element[i][0] == ','))
			return (printf("Error\nInvalid ambiante element\n"),
				free_data(data), 0);
		if (!fill_amb_elem(element[i], ambiante))
			return (free_data(data), 0);
	}
	return (1);
}
