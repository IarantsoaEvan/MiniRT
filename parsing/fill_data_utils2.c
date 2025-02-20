/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:55:09 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/20 22:08:10 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int check_excat_val(char **elem)
{
	int i;
	int len;

	i = -1;
	while (elem[++i])
	{
		len = ft_strlen(elem[i]);
		if (!ft_isdigit(elem[i][len - 1]) || (elem[i][0] == '.' || elem[i][0] == ','))
			return (0);
	}
	return (1);
}

void fill_rgb_color(t_color *color, char **elem)
{
	color->r = ft_atflo(elem[0]);
	color->g = ft_atflo(elem[1]);
	color->b = ft_atflo(elem[2]);
}