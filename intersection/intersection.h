/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:41:38 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/04 08:43:37 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H
#include "../src/minirt.h"

t_coord *ft_soustraction(t_coord *coord1,t_coord *coord2);
float get_t_plane(t_coord *direction,t_coord *origin,t_plane *plane);
float ft_scal(t_coord *vect1,t_coord *vect2);
void	real_ray_dir(t_fct *fct, t_camera *cam);
float get_t_sphere(t_pol *pol, float delta);
float	get_delta(t_pol *pol);
void get_nearest_obj(t_data *rt ,t_fct *fct ,float x,float y);
t_coord *ft_addition(t_coord *coord1,t_coord *coord2);
int create_sphere_rgb_finale(float t,t_fct *fct,t_data *rt,t_sphere *sphere);
int create_plane_rgb_finale(float t,t_fct *fct,t_data *rt,t_plane *plane);
int	create_cyl_rgb_finale(float t,t_fct *fct,t_data *rt, t_cyl *cyl);
// void	ft_screen(float *x_ndc, float *y_ndc, float *x_screen, float *y_screen);
void ft_set_abc_sphere(t_fct *fct,t_sphere *sphere,t_coord *origin);
float get_t_sphere(t_pol *pol, float delta);
// t_pol *init_pol();
t_fct *init_fct(t_data *rt);
t_pol *init_pol(void);
// void ft_set_abc_sphere(t_fct *fct,t_data *rt,t_sphere *sphere);
// void	ft_ndc(float *x, float *y, t_data *rt);
// void	ft_screen(float *x_ndc, float *y_ndc, float *x_screen, float *y_screen);
// void	ft_as_ratio(t_fct *fct, t_camera *cam, t_data *rt);
// t_pol *init_pol();
t_coord *normalize_vector_with_free(t_coord *coord);
void intersec_sphere(t_fct *fct,t_data *rt);
t_coord *ft_cross_product(t_coord *v1, t_coord *v2);
t_coord *normalize_vector(t_coord *coord);
t_coord	*ft_scal_one(t_coord *v1, float one);
t_coord	*vect_add(t_coord	*v1, t_coord *v2);
void get_abc_cyl(t_data *rt,t_fct *fct,t_cyl *cyl);
float get_t_cyl(t_fct *fct, float delta, t_data *rt,t_cyl *cyl);
void intersec_plane(t_fct *fct,t_data *rt);
void intersec_cyl(t_fct *fct,t_data *rt);
float	lenght_vector(t_coord *vect);

#endif