/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:41:38 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/24 09:09:58 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H
# include "../src/minirt.h"

t_coord	*ft_soustraction(t_coord *coord1, t_coord *coord2);
float	get_t_plane(t_coord *direction, t_coord *origin, t_plane *plane);
float	ft_scal(t_coord *vect1, t_coord *vect2);
void	real_ray_dir(t_fct *fct, t_camera *cam);
float	get_t_sphere(t_pol *pol, float delta);
float	get_delta(t_pol *pol);
void	get_nearest_obj(t_data *rt, t_fct *fct, float x, float y);
t_coord	*ft_addition(t_coord *coord1, t_coord *coord2);
int		create_sphere_rgb_finale(float t, t_fct *fct, t_data *rt,
			t_sphere *sphere);
t_coord	*change_plane_vect(t_coord *plane_vect, t_coord *dir);
int		create_plane_rgb_finale(float t, t_fct *fct, t_data *rt,
			t_plane *plane);
float	get_m_scal(t_coord *dir, t_coord *origin, float t, t_cyl *cyl);
void	get_abc_cyl(t_coord *origin, t_fct *fct, t_cyl *cyl);
int		create_cyl_rgb_finale(float t, t_fct *fct, t_data *rt, t_cyl *cyl);
void	ft_set_abc_sphere(t_fct *fct, t_sphere *sphere, t_coord *origin);
float	get_t_sphere(t_pol *pol, float delta);
t_fct	*init_fct(t_data *rt);
float	get_base_cyl(t_coord *dir, t_coord *origin, t_cyl *cyl, int check_pos);
t_pol	*init_pol(void);
void	free_rgb(t_rgb *rgb);
void	free_fct(t_fct *fct);

t_coord	*normalize_vector_with_free(t_coord *coord);
void	intersec_sphere(t_fct *fct, t_data *rt, t_nearest *near);
t_coord	*ft_cross_product(t_coord *v1, t_coord *v2);
t_coord	*normalize_vector(t_coord *coord);
t_coord	*ft_scal_one(t_coord *v1, float one);
t_coord	*vect_add(t_coord *v1, t_coord *v2);
float	get_t_cyl(t_fct *fct, float delta, t_coord *origin, t_cyl *cyl);
void	intersec_plane(t_fct *fct, t_data *rt, t_nearest *near);
void	intersec_cyl(t_fct *fct, t_data *rt, t_nearest *near);
float	lenght_vector(t_coord *vect);
void	init_current_cyl(t_nearest *cyl_current, t_cyl *cyl);
void	set_disk_pos_neg(t_cyl *cyl, int check_pos, t_coord *norm_vec);
void	set_disk(t_cyl *cyl, int check_pos);
void	intersec_disk_cyl(t_nearest *near, t_cyl *tmp, float t_top,
			float t_bot);
float	get_m_scal(t_coord *dir, t_coord *origin, float t, t_cyl *cyl);
float	get_base_cyl(t_coord *dir, t_coord *origin, t_cyl *cyl, int check_pos);
void	aply_color_cyl(t_fct *fct, t_rgb *rgb, t_data *rt, t_cyl *cyl);
void	free_cam_ur(t_camera *cam, t_coord *cam_ort);
void	init_current_sp(t_nearest *sp_current, t_sphere *sphere);
void	check_scal_nl(float scal_nl, t_rgb *rgb, t_color *spec);
void	init_current_pl(t_nearest *pl_current, t_plane *plane);

#endif