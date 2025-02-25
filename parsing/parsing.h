/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:34:36 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/25 09:42:59 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../src/minirt.h"

int			fill_amb(t_ambiante **ambiante, char **element, t_data *data);
t_data		*init_data(void);
int			check_color(float color);
int			check_positive(float nb);
int			check_valid_element(char **element);
int			check_vec_or_rat(float vector, int type);
int			fill_data(t_data *data, char **element);
int			check_and_fill_color(char *val, t_color *color);
int			fill_cam(t_camera **cam, char **element, t_data *data);
void		ft_add_back_plane(t_plane **plane, t_plane *new);
int			fill_elem_cyl(t_cyl **cyl, char *element, int *flag);
void		ft_add_back_sphere(t_sphere **sphere, t_sphere *new);
int			fill_coord(char *val, t_coord *coord);
int			fill_sphere(t_sphere **sphere, char **elem, t_data *data);
int			fill_plane(t_plane **pl, char **elem, t_data *data);
t_nearest	*init_nearest(void);
t_ambiante	*init_amb(void);
t_color		*init_color(void);
void		fill_rgb_color(t_color *color, char **elem);
t_coord		*init_coord(void);
t_cyl		*init_cyl(void);
t_plane		*init_plane(void);
int			fill_cyl(t_cyl **cyl, char **elem, t_data *data);
t_camera	*init_cam(void);
t_light		*init_light(void);
int			check_map_name(char **argv, int argc);
void		free_data(t_data *data);
int         check_float(char *str);
char		*get_map(int fd);
t_sphere	*init_sphere(void);
int			check_excat_val(char **elem);
int			fill_and_check_map_valid(char *map, t_data *data);
int			get_element(char **v_map, t_data *data);
void		ft_add_back_cyl(t_cyl **cyl, t_cyl *new);
int			fill_light(t_light **light, char **elem, t_data *data);
int			check_angle(float angle);
int			fill_cam(t_camera **cam, char **element, t_data *s_data);
void		init_flt_data(t_data *data);

#endif