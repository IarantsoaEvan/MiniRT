/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse_light.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:26:50 by mrambelo          #+#    #+#             */
/*   Updated: 2025/01/27 15:25:52 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIFFUSE_LIGHT
#define DIFFUSE_LIGHT
#include "../src/minirt.h"

t_color *get_rgb_diff(t_coord *norm_obj,t_coord *norm_light,float ratio,t_color *color);
t_color *add_amb_and_diff(t_color *amb,t_color *diff);
t_coord *get_normal_sphere(t_data *rt,t_coord *point);
t_coord *get_normal_light(t_data *rt,t_coord *point);
t_coord	*get_normal_cyl(t_data *rt, t_coord *point, float m);
#endif