/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:23:59 by mrambelo          #+#    #+#             */
/*   Updated: 2025/01/14 19:48:10 by mrambelo         ###   ########.fr       */
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
	float r;
	float g;
	float b;
} t_color;


typedef struct s_ambiante
{
	char id[2];
	t_coord *ratio;
	t_color * color;
} t_ambiante;

typedef struct s_camera
{
	char id[2];
	t_coord *coord;
	t_coord *vector;
	float fov;
} t_camera;

typedef struct s_light
{
	char id[2];
	t_coord *coord;
	t_coord *ratio;
	t_color *color;
} t_light;

typedef struct s_sphere
{
	char id[3];
	t_coord	*coord;
	float	diam;
	t_color	*color;
} t_sphere;

typedef struct s_plane
{
	char id[3];
	t_coord	*coord;
	t_coord	*vector;
	t_color	*color;
} t_plane;

typedef struct s_cyl
{
	char id[3];
	t_coord	*coord;
	t_coord	*vector;
	float diam;
	float height;
	t_color	*color;
} t_cyl;

typedef struct s_data
{
	t_ambiante	*ambiante;
	t_camera	*cam;
	t_light		*light;
	t_sphere	*sphere;
	t_plane		*plane;
	t_cyl		*cyl;
} t_data;

