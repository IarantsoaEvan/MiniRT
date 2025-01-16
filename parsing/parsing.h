/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:34:36 by mrambelo          #+#    #+#             */
/*   Updated: 2025/01/16 14:47:16 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../src/minirt.h"

int     	fill_amb(t_ambiante **ambiante,char **element);
t_data  	*init_data(void);
int     	check_color(int color);
int check_valid_objet(char **element);
int check_positive(float nb);
int check_valid_element(char **element);
int     	check_vec_or_rat(float vector,int type);
int     	check_and_fill_color(char **elem,t_color *color);
int     	fill_cam(t_camera **cam,char **element);
void	ft_add_back_plane(t_plane **plane, t_plane *new);
int fill_elem_cyl(t_cyl **cyl,char *element,int *flag);
void	ft_add_back_sphere(t_sphere **sphere, t_sphere *new);
void        fill_coord(char **elem,t_coord *coord);
int fill_sphere(t_sphere **sphere,char **elem);
int fill_plane(t_plane **pl,char **elem);
t_ambiante  *init_amb(void);
t_color *init_color(void);
t_coord *init_coord(void);
t_cyl *init_cyl(void);
t_plane *init_plane(void);
int fill_cyl(t_cyl **cyl,char **elem);
t_camera    *init_cam(void);
t_light		*init_light(void);
t_sphere *init_sphere(void);
void print_sp(t_sphere *sphere);
void	ft_add_back_cyl(t_cyl **cyl, t_cyl *new);
void print_cyl(t_cyl *cyl);
void		print_ambiante(t_ambiante *ambiante);
void		print_cam(t_camera *cam);
void        print_pl(t_plane *pl);
void		print_light(t_light *light);
int fill_light(t_light **light,char **elem);
int			check_angle(float angle);
int fill_cam(t_camera **cam,char **element);

#endif