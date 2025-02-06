/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:24:02 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/06 21:27:17 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# define RATIO 1
# define VECTOR 2
# define SPHERE 3
# define CYL 4
# define PLANE 5
# define SHADOW 6
# define NO_SHADOW 7
# define DISK 8
# include <stdio.h> 
# include "structure.h"
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "../parsing/parsing.h"
# include "../matrix/matrix.h"
# include "../intersection/intersection.h"
# include "../ambent_light/ambiente.h"
# include "../ombrage/shadow.h"
# include "../diffuse_light/diffuse_light.h"
# include <math.h>

int check_valid_object(char  **elem);
int check_valid_a_c_l(char  **elem);
int check_comma(char *str);
void	init_graph(t_data *rt);
void free_disk(t_plane *disk);
int	close_win(t_data *data);
void	ray_tracing(t_data *rt);
void	my_mlx_pxp(t_data *rt, int x, int y, int color);
void free_all(t_data *data);
void free_plane(t_plane *plane);
void ft_set_cfct(t_fct *fct, float x, float y, t_data *rt);
void intersec_obj(t_fct	*fct, t_data *rt,t_nearest *near);


#endif