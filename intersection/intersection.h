/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:41:38 by mrambelo          #+#    #+#             */
/*   Updated: 2025/01/21 21:26:13 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H
#include "../src/minirt.h"

t_coord *ft_soustraction(t_coord *coord1,t_coord *coord2);
float get_t_plane(t_fct *fct,t_data *rt);
float ft_scal(t_coord *vect1,t_coord *vect2);
void set_direction(t_fct *fct, t_coord	*dir,t_camera *cam);
float get_t_sphere(t_pol *pol, float delta);
float	get_delta(t_pol *pol);
void	ft_ndc(float *x, float *y);
void	ft_screen(float *x_ndc, float *y_ndc, float *x_screen, float *y_screen);
t_pol *init_pol();
void	ft_as_ratio(t_fct *fct, t_camera *cam);
t_fct *init_fct(void);
void ft_set_abc_sphere(t_fct *fct,t_data *rt);
void	ft_ndc(float *x, float *y);
void	ft_screen(float *x_ndc, float *y_ndc, float *x_screen, float *y_screen);
void	ft_as_ratio(t_fct *fct, t_camera *cam);
t_pol *init_pol();
t_fct *init_fct(void);
void intersec_sphere(t_fct *fct,t_data *rt);
#endif