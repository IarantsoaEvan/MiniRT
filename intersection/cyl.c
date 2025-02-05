/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:01:07 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/05 14:41:13 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

void get_abc_cyl(t_coord *origin,t_fct *fct,t_cyl *cyl)
{
	t_coord *norm_vec;
	t_coord *x;
	float scal_dir;

	norm_vec = normalize_vector(cyl->vector);
	x = ft_soustraction(origin,cyl->coord);
	scal_dir = ft_scal(fct->dir,fct->dir);
	fct->pol->a = scal_dir - powf(ft_scal(fct->dir,norm_vec),2);
	fct->pol->b = (ft_scal(fct->dir,x) - (ft_scal(fct->dir,norm_vec) * ft_scal(x,norm_vec))) * 2;
	fct->pol->c = ft_scal(x,x) - powf(ft_scal(x,norm_vec),2) - powf((float)(cyl->diam / 2),2);
	free(norm_vec);
	free(x);
}

int	create_cyl_rgb_finale(float t,t_fct *fct,t_data *rt, t_cyl *cyl)
{
	// t_coord *point;
	// t_color *color;
	// t_color *rgb_diff;
	// t_color *rgb_finale;
	// int rgb;
	t_rgb rgb;
	
	rgb.point = ft_addition(rt->cam->coord,ft_scal_one(fct->dir, t));
	rgb.flag = NO_SHADOW;
	rgb.color = apply_amb(cyl->color, rt->ambiante->ratio);
	rgb.flag = ray_shadowing(rt, rgb.point,cyl->id);
	rt->light->normal = get_normal_light(rt,rgb.point);
	cyl->normal = get_normal_cyl(rt, rgb.point, cyl);
	rgb.rgb_diff = get_rgb_diff(cyl->normal
		,rt->light->normal,rt->light->ratio,cyl->color);
	rgb.rgb_finale = add_amb_and_diff(rgb.color,rgb.rgb_diff);
	if (rgb.flag == SHADOW)
		rgb.rgb_finale = apply_shadow_color(rgb.rgb_finale);
	rgb.rgb = create_trgb(rgb.rgb_finale->r, rgb.rgb_finale->g, rgb.rgb_finale->b);
	free(rt->light->normal);
	// free(point);
	// free(color);
	// free(rgb_diff);
	// free(rgb_finale);
	free(cyl->normal);
	return (rgb.rgb);
}
float	get_m_scal(t_coord *dir, t_coord *origin, float t,t_cyl *cyl)
{
	t_coord *norm_vec;
	t_coord	*x;

	norm_vec = normalize_vector(cyl->vector);
	x = ft_soustraction(origin,cyl->coord);
	cyl->m = (ft_scal(dir, norm_vec) * t) + ft_scal(x, norm_vec);
	free(norm_vec);
	free(x);
	return (cyl->m);
}

float get_t_cyl(t_fct *fct, float delta, t_coord *origin,t_cyl *cyl)
{
    float   t1;
    float   t2;
    float   distance;
	
    distance = -1;
    if (delta == 0)
    {
        t1 = (fct->pol->b * (-1)) / (2 * fct->pol->a);
		cyl->m = get_m_scal(fct->dir, origin, t1,cyl);
		if (cyl->m >= -cyl->height / 2 && cyl->m >= cyl->height / 2)
            distance = t1;
    }
    else if (delta > 0)
    {
        t1 = (((-1) * fct->pol->b) - (sqrt(delta))) / (2 * fct->pol->a);
        t2 = (((-1) * fct->pol->b) + (sqrt(delta))) / (2 * fct->pol->a);
        if (t1 > 0)
        {
            cyl->m = get_m_scal(fct->dir, origin, t1,cyl);
            if (cyl->m >= -cyl->height / 2 && cyl->m <= cyl->height / 2)
                distance = t1;
        }
        if (t2 > 0)
        {
           cyl->m = get_m_scal(fct->dir, origin, t2,cyl);
            if (cyl->m >= -cyl->height / 2 &&cyl->m <= cyl->height / 2 && (distance < 0 || t2 < t1))
                distance = t2;
        }
    }
    return (distance);
}
t_plane	*set_disk(t_cyl *cyl,int check_pos)
{
	t_plane *plane;
	t_coord *norm_vec;


	// plane = init_plane();
	plane = malloc(sizeof(t_plane));
	norm_vec = normalize_vector(cyl->vector);
	if (check_pos == 0)
	{
		plane->coord = ft_addition(cyl->coord, ft_scal_one(norm_vec, -cyl->height/ 2));
		plane->vector = ft_scal_one(cyl->vector, -1.0);
	}
	else
	{
		plane->coord = ft_addition(cyl->coord, ft_scal_one(norm_vec, cyl->height/ 2));
		plane->vector = ft_scal_one(cyl->vector, 1.0);
	}
	plane->color = cyl->color;
	free(norm_vec);
	return (plane);
}
void free_disk(t_plane *disk)
{
	if (disk->coord)
		free(disk->coord);
	if (disk->vector)
		free(disk->vector);
	if (disk)
		free(disk);
}
float	get_base_cyl(t_coord *dir, t_coord *origin,  t_cyl *cyl,int check_pos)
{
	t_coord *xc;
	t_coord *norm;
	t_coord	*impact;
	float	t_disk;

	cyl->disk = set_disk(cyl,check_pos);
	xc = ft_soustraction(origin, cyl->disk->coord);
	norm = normalize_vector(cyl->disk->vector);
	t_disk = ((-1) * (ft_scal(xc,norm))) / ft_scal(dir,norm);
	impact = ft_addition(origin, ft_scal_one(dir, t_disk));
	if (t_disk > 0.001 && lenght_vector(ft_soustraction(impact, cyl->disk->coord)) <= cyl->diam /  2)
	{
		// free_disk(cyl->disk);
		return (free(impact),free(xc),free(norm),t_disk);
	}
	free(impact);
	// free_disk(cyl->disk);
	free(xc);
	free(norm);
	return (-1);
}

void intersec_disk_cyl(t_nearest *near,t_cyl *tmp,float t_top,float t_bot)
{
	if (t_top > 0 && t_top < near->t_near)
	{
		near->t_near = t_top;
		near->near_obj = tmp->disk;
		near->type = PLANE; 
	}
	if (t_bot > 0 && t_bot < near->t_near)
	{
		near->t_near = t_bot;
		near->near_obj = tmp->disk;
		near->type = PLANE; 
	}
}
void intersec_cyl(t_fct *fct,t_data *rt,t_nearest *near)
{
	t_cyl *tmp;
	float	t;
	float	t_top;
	float	t_bot;
	tmp = rt->cyl;

	while (tmp)
	{
		get_abc_cyl(rt->cam->coord,fct,tmp);
		t = get_t_cyl(fct, get_delta(fct->pol), rt->cam->coord,tmp);
		t_top = get_base_cyl(fct->dir, rt->cam->coord, tmp,1);
		t_bot = get_base_cyl(fct->dir, rt->cam->coord, tmp,0);
		if (t > 0 && t < near->t_near)
		{
			near->t_near = t;
			near->near_obj = tmp;
			near->type = CYL; 
		}
		intersec_disk_cyl(near, tmp, t_top, t_bot);
		tmp = tmp->next;
	}
}
