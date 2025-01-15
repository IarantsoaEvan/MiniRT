/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:34:36 by mrambelo          #+#    #+#             */
/*   Updated: 2025/01/15 22:41:20 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../src/minirt.h"

int     	fill_amb(t_ambiante **ambiante,char **element);
t_data  	*init_data(void);
int     	check_color(int color);
int     	check_vec_or_rat(float vector,int type);
int     	check_and_fill_color(char **elem,t_color *color);
int     	fill_cam(t_camera **cam,char **element);
void        fill_coord(char **elem,t_coord *coord);
t_ambiante  *init_amb(void);
t_color *init_color(void);
t_coord *init_coord(void);
t_camera    *init_cam(void);
t_light		*init_light(void);
void		print_ambiante(t_ambiante *ambiante);
void		print_cam(t_camera *cam);
void		print_light(t_light *light);
int fill_light(t_light **light,char **elem);
int			check_angle(float angle);
int fill_cam(t_camera **cam,char **element);

#endif