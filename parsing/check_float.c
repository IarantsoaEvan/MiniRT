/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:31:20 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/27 10:24:37 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_float(char *str)
{
	if (ft_count_char_in_str(str, '.') > 1 || ft_count_char_in_str(str, '-') > 1
		|| ft_count_char_in_str(str, '+') > 1)
		return (0);
	if ((ft_count_char_in_str(str, '-') == 1 && str[0] != '-')
		|| (ft_count_char_in_str(str, '+') == 1 && str[0] != '+'))
		return (0);
	if (ft_count_char_in_str(str, '-') > 0 && ft_count_char_in_str(str,
			'+') > 0)
		return (0);
	return (1);
}

int	check_int_color(char *str)
{
	if (ft_count_char_in_str(str, '.') > 0 || ft_count_char_in_str(str,
			'+') > 1)
		return (0);
	if ((ft_count_char_in_str(str, '-') == 1 && str[0] != '-')
		|| (ft_count_char_in_str(str, '+') == 1 && str[0] != '+'))
		return (0);
	if (ft_count_char_in_str(str, '-') > 0 && ft_count_char_in_str(str,
			'+') > 0)
		return (0);
	return (1);
}
