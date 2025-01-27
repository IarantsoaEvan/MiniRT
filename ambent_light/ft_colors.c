/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:21:13 by irabesan          #+#    #+#             */
/*   Updated: 2025/01/27 11:04:07 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ambiente.h"

int	create_trgb(int r, int g, int b)
{
		return (r << 16 | g << 8 | b);
}

// int	get_r(int trgb)
// {
// 	return ((trgb >> 16) & 0xFF);
// }

// int get_g(int trgb)
// {
// 	return ((trgb >> 8) & 0xFF);
// }

// int get_b(int	trgb)
// {
// 	return (trgb & 0xFF);
// }