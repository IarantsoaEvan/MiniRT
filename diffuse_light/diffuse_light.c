/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:26:39 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/11 14:11:46 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "diffuse_light.h"
t_color	*calculate_spec(t_light *lum, t_nearest)
{
	t_color *spec_light;
	float	lphi;
	t_phong	phong;	

	lphi = 0.0;
	spec_light = init_color();
	phong.intensity = 0.3;
	phong.k = 0.3;
	phong.n_pw = 2;
	phong.

}
t_coord *get_normal_light(t_data *rt,t_coord *point)
{
	t_coord *norm;

	norm = normalize_vector_with_free(ft_soustraction(rt->light->coord, point));
	return (norm);
}

float check_plage_color(float color)
{
	if (color > 255)
		return (255);
	if (color < 0)
		return (0);
	return (color);
}

t_color *get_rgb_diff(t_coord *norm_obj,t_coord *norm_light,float ratio,t_color *color)
{
	t_color *rgb_diff;
	float scal_nl;

	rgb_diff = init_color();
	scal_nl = ratio * ft_scal(norm_obj, norm_light);
	rgb_diff->r = scal_nl * (color->r / 255);
	rgb_diff->g = scal_nl * (color->g / 255); 
	rgb_diff->b = scal_nl * (color->b / 255);
	return (rgb_diff);
}

t_color *add_amb_and_diff(t_color *amb,t_color *diff)
{
	t_color *res;

	res = init_color();
	res->r = amb->r + diff->r;
	res->g = amb->g + diff->g;
	res->b = amb->b + diff->b;
	
	res->r = res->r * 255;
	res->g = res->g * 255;
	res->b = res->b * 255;
	res->r = check_plage_color(res->r);
	res->g = check_plage_color(res->g);
	res->b = check_plage_color(res->b);
	return (res);
}