/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:46:34 by mrambelo          #+#    #+#             */
/*   Updated: 2025/01/22 13:14:03 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

void	ft_ndc(float *x, float *y)
{
	*x = (*x + 0.5) / (WIDTH / 2);
	*y = (*y + 0.5) / (HEIGHT / 2);
}

void	ft_screen(float *x_ndc, float *y_ndc, float *x_screen, float *y_screen)
{
	*x_screen = 2 * (*x_ndc) - 1;
	*y_screen = 2 * (*y_ndc) - 1;
}

void	ft_as_ratio(t_fct *fct, t_camera *cam)
{
	float	rad_alpha;

	rad_alpha = cam->fov * (M_PI / 180);
	fct->as_x = (2 * fct->x_screen - 1) * AS_RATIO * tan(rad_alpha / 2);
	fct->as_y = (1 - (2 * fct->y_screen)) * tan(rad_alpha / 2);
}


t_pol *init_pol()
{
	t_pol *pol;

	pol = malloc(sizeof(t_pol));
	pol->a = 0;
	pol->b = 0;
	pol->c = 0;
	return (pol);
}

t_fct *init_fct(void)
{
	t_fct *fct;

	fct = malloc(sizeof(t_fct));
	fct->as_x = 0;
	fct->as_y = 0;
	fct->x_ndc = 0;
	fct->y_ndc = 0;
	fct->x_screen = 0;
	fct->y_screen = 0;
	fct->as_z = 1;
	fct->dir = init_coord();
	fct->pol = init_pol();
	fct->ray = init_coord();
	fct->ort_y = init_coord(); 
	fct->cam_ort = init_coord();
	return (fct);
}