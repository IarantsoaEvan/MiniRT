/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:46:34 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/17 08:28:13 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

t_pol	*init_pol(void)
{
	t_pol	*pol;

	pol = malloc(sizeof(t_pol));
	pol->a = 0;
	pol->b = 0;
	pol->c = 0;
	return (pol);
}

t_fct	*init_fct(t_data *rt)
{
	t_fct	*fct;

	fct = malloc(sizeof(t_fct));
	fct->as_x = 0;
	fct->as_y = 0;
	fct->as_z = 1;
	fct->dir = NULL;
	fct->pol = init_pol();
	fct->as_ratio = rt->width / rt->height;
	fct->as_wi = (2 * fct->as_z) * tan(rt->cam->rad_fov / 2);
	fct->as_he = fct->as_ratio * fct->as_wi;
	return (fct);
}

void	free_fct(t_fct *fct)
{
	free(fct->pol);
	free(fct->dir);
	free(fct);
}

void	free_rgb(t_rgb *rgb)
{
	free(rgb->point);
	free(rgb->color);
	free(rgb->rgb_diff);
	free(rgb->rgb_finale);
}
