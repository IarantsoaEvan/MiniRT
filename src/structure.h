/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:23:59 by mrambelo          #+#    #+#             */
/*   Updated: 2025/01/20 15:06:00 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

typedef struct s_coord
{
	float x;
	float y;
	float z;
} t_coord;

typedef struct s_color
{
	int r;
	int g;
	int b;
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
	float	fov;
} t_camera;

typedef struct s_light
{
	t_coord	*coord;
	float	ratio;
	t_color	*color;
} t_light;

typedef struct s_sphere
{
	int id;
	t_coord	*coord;
	float	diam;
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
	float	diam;
	float	height;
	t_color	*color;
	struct s_cyl *next;
} t_cyl;

typedef struct s_fict
{
	float	x_ndc;
	float	y_ndc;
	float	x_screen;
	float	y_screen;
}	t_fict;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	t_ambiante	*ambiante;
	t_camera	*cam;
	t_light		*light;
	t_sphere	*sphere;
	t_plane		*plane;
	t_cyl		*cyl;
} t_data;

