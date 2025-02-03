/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:46:34 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/03 10:05:24 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

// void	ft_ndc(float *x, float *y, t_data *rt)
// {
// 	*x = (*x + 0.5) / (rt->width);
// 	*y = (*y + 0.5) / (rt->height);
// }

// void	ft_screen(float *x_ndc, float *y_ndc, float *x_screen, float *y_screen)
// {
// 	*x_screen = (2 * (*x_ndc)) - 1;
// 	*y_screen = (2 * (*y_ndc)) - 1;
// 	// *y_screen = 1  + (-(2 * (*y_ndc)));
// }

// void	ft_as_ratio(t_fct *fct, t_camera *cam, t_data *rt)
// {
// 	float	rad_alpha;
// 	float	as_ratio;

// 	as_ratio = rt->width / rt->height;
// 	rad_alpha = cam->fov * (M_PI / 180);
// 	fct->as_x = ((2 * fct->x_screen) - 1) * as_ratio * tan(rad_alpha / 2);
// 	fct->as_y = (1 + (-2 * fct->y_screen)) * tan(rad_alpha / 2);
// }


t_pol *init_pol(void)
{
	t_pol *pol;

	pol = malloc(sizeof(t_pol));
	pol->a = 0;
	pol->b = 0;
	pol->c = 0;
	return (pol);
}

t_fct *init_fct(t_data *rt)
{
	t_fct *fct;

	fct = malloc(sizeof(t_fct));
	fct->as_x = 0;
	fct->as_y = 0;
	fct->as_z = 1;
	// fct->dir = init_coord();
	fct->dir = NULL;
	fct->pol = init_pol();
	fct->as_ratio = rt->width / rt->height;
	fct->as_wi = (2 * fct->as_z) * tan(rt->cam->rad_fov / 2);
	fct->as_he = fct->as_ratio * fct->as_wi;
	return (fct);
}