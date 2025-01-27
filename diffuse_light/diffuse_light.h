/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse_light.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:26:50 by mrambelo          #+#    #+#             */
/*   Updated: 2025/01/27 11:58:58 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIFFUSE_LIGHT
#define DIFFUSE_LIGHT
#include "../src/minirt.h"

t_color *get_rgb_diff(t_coord *norm_obj,t_coord *norm_light,t_data *rt);
t_color *add_amb_and_diff(t_color *amb,t_color *diff);
t_coord *get_normal_sphere(t_data *rt,float x,float y);
t_coord *get_normal_light(t_data *rt,float x,float y);
#endif