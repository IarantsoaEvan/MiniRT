/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:23:59 by mrambelo          #+#    #+#             */
/*   Updated: 2025/01/31 13:30:04 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H
# include "minirt.h"


typedef struct s_nearest
{
	float t_near;
	void *near_obj;
	int	type;
} t_nearest;

typedef struct s_coord
{
	float x;
	float y;
	float z;
} t_coord;

typedef struct s_color
{
	float r;
	float g;
	float b;
} t_color;


typedef struct s_ambiante
{
	float ratio;
	t_color	* color;
} t_ambiante;

typedef struct s_camera
{
	t_coord	*coord;
	t_coord	*vector;
	t_coord	*cam_right;
	t_coord	*cam_up;
	float	fov;
	float	rad_fov;
} t_camera;

typedef struct s_light
{
	t_coord	*coord;
	float	ratio;
	t_color	*color;
	t_coord *normal;
} t_light;

typedef struct s_sphere
{
	int id;
	t_coord	*coord;
	float	diam;
	t_coord *normal;
	t_color	*color;
	struct s_sphere *next;
} t_sphere;

typedef struct s_plane
{
	int id;
	t_coord	*coord;
	t_coord	*vector;
	t_color	*color;
	struct s_plane *next;
} t_plane;

typedef struct s_cyl
{
	int id;
	t_coord	*coord;
	t_coord	*vector;
	t_coord	*normal;
	t_plane *disk;
	float	diam;
	float	height;
	float m;
	t_color	*color;
	struct s_cyl *next;
} t_cyl;

typedef struct s_pol
{
	float a;
	float b;
	float c;

} t_pol;

typedef struct s_lbrt
{
	float	left;
	float	right;
	float	top;
	float	bottom;
}	t_lbrt;

typedef struct s_fct
{
	float	as_x;
	float	as_y;
	float	as_z;
	float	as_wi;
	float	as_he;
	float	as_ratio;
	t_pol	*pol;
	t_coord *dir;
}	t_fct;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_data;
	int	bpp;
	int	endian;
	int	size_line;
	t_ambiante	*ambiante;
	t_camera	*cam;
	t_light		*light;
	t_nearest	*near;
	t_sphere	*sphere;
	t_plane		*plane;
	t_cyl		*cyl;
	float	width;
	float	height;
} t_data;

#endif