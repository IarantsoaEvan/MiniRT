/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse_light.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:26:50 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/17 10:03:34 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIFFUSE_LIGHT_H
# define DIFFUSE_LIGHT_H
# include "../src/minirt.h"
# include "../src/structure.h"
t_color	*get_rgb_diff(t_coord *norm_obj, t_coord *norm_light, float ratio,
			t_color *color);
t_color	*add_amb_and_diff(t_color *amb, t_color *diff, t_color *spec);
t_coord	*get_normal_sphere(t_coord *point, t_sphere *sphere);
t_coord	*get_normal_light(t_data *rt, t_coord *point);
t_coord	*get_normal_cyl(t_data *rt, t_coord *point, t_cyl *cyl);
t_color	*get_specular(t_data *rt, t_nearest *object, t_coord *impact,
			t_fct *fct);
#endif