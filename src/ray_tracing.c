/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 09:27:27 by irabesan          #+#    #+#             */
/*   Updated: 2025/01/20 15:36:16 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_ndc(float *x, float y)
{
	*x = (x + 0.5) / (WIDTH / 2);
	*y = (y + 0.5) / (HEIGHT / 2);
}

void	ft_screen(float *x_ndc, float *y_ndc, float *x_screen, float *y_screen)
{
	*x_screen = 2 * x_ndc - 1;
	*y_screen = 2 * y_ndc - 1;
}

void	ray_tracing(t_data *rt)
{
	float x;
	float	y;
	t_fict fct = NULL;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			fct.x_ndc = x;
			fct.y_ndc = y;
			ft_ndc(&fct.x_ndc, &fct.y_ndc);
			ft_screen(&fct.x_ndc, &fct.y_ndc, &fct.x_screen, &fct.y_screen);
			x++;
		}
		y++;
	}
}