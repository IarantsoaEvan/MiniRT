/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:01:07 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/15 11:56:44 by mrambelo         ###   ########.fr       */
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

void init_current_cyl(t_nearest *cyl_current,t_cyl *cyl)
{	
	cyl_current->near_obj = cyl;
	cyl_current->type = CYL;
	cyl_current->id = cyl->id;
}

void aply_color_cyl(t_fct *fct,t_rgb *rgb,t_data *rt,t_cyl *cyl)
{
	float scal_nl;
	t_color *spec;
	t_nearest cyl_current;
	
	
	init_current_cyl(&cyl_current,cyl);
	spec = init_color();
	scal_nl = ft_scal(cyl->normal,rt->light->normal);
	if (rt->flag_spec)
	{
		if (spec)
			free(spec);
		spec =  get_specular(rt ,&cyl_current,rgb->point,fct);
	}
	if (scal_nl < 0)
		rgb->rgb_finale = apply_shadow_color(rgb->color);
	else
		rgb->rgb_finale = add_amb_and_diff(rgb->color,rgb->rgb_diff,spec);
	if (rgb->flag == SHADOW)
	{
		if (rgb->rgb_finale)
			free(rgb->rgb_finale);
		rgb->rgb_finale = apply_shadow_color(rgb->color);
	}
	free(spec);
}


int	create_cyl_rgb_finale(float t,t_fct *fct,t_data *rt, t_cyl *cyl)
{
	t_rgb rgb;
	t_nearest cyl_current;
	
	
	init_current_cyl(&cyl_current,cyl);
	rgb.point = ft_addition(rt->cam->coord,ft_scal_one(fct->dir, t));
	rgb.flag = NO_SHADOW;
	rgb.color = apply_amb(cyl->color, rt->ambiante->ratio);
	rgb.flag = ray_shadowing(rt, rgb.point,&cyl_current);
	rt->light->normal = get_normal_light(rt,rgb.point);
	cyl->normal = get_normal_cyl(rt, rgb.point, cyl);
	rgb.rgb_diff = get_rgb_diff(cyl->normal
		,rt->light->normal,rt->light->ratio,cyl->color);
	aply_color_cyl(fct,&rgb,rt,cyl);
	rgb.rgb = create_trgb(rgb.rgb_finale->r, rgb.rgb_finale->g, rgb.rgb_finale->b);
	free(cyl->normal);
	return (free(rt->light->normal),free_rgb(&rgb),rgb.rgb);
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

float  get_t_cyl_delta_pos(t_fct *fct, t_cyl *cyl, float delta,t_coord *origin)
{
	float   t1;
    float   t2;
    float   distance;

	distance = -1;
	t1 = (((-1) * fct->pol->b) - (sqrt(delta))) / (2 * fct->pol->a);
	t2 = (((-1) * fct->pol->b) + (sqrt(delta))) / (2 * fct->pol->a);
	if (t1 > 0.0001)
	{
		cyl->m = get_m_scal(fct->dir, origin, t1,cyl);
		if (cyl->m >= -cyl->height / 2 && cyl->m <= cyl->height / 2)
			distance = t1;
	}
	if (t2 > 0.0001)
	{
	   cyl->m = get_m_scal(fct->dir, origin, t2,cyl);
		if (cyl->m >= -cyl->height / 2 &&cyl->m <= cyl->height / 2 && (distance < 0 || t2 < t1))
			distance = t2;
	}
	return (distance);
}

float get_t_cyl(t_fct *fct, float delta, t_coord *origin,t_cyl *cyl)
{
	float   t1;
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
		distance = get_t_cyl_delta_pos(fct, cyl,delta,origin);
	return (distance);
}

void set_disk_pos_neg(t_cyl *cyl,int check_pos,t_coord *norm_vec)
{
	if (check_pos == 0)
	{
		cyl->disk_bot->id = cyl->id;
		if (cyl->disk_bot->coord)
			free(cyl->disk_bot->coord);
		cyl->disk_bot->coord = ft_addition(cyl->coord, ft_scal_one(norm_vec, -cyl->height/ 2));
		if (cyl->disk_bot->vector)
			free(cyl->disk_bot->vector);
		cyl->disk_bot->vector = ft_scal_one(cyl->vector, -1.0);
		cyl->disk_bot->color = cyl->color;
	}
	else
	{
		cyl->disk_top->id = cyl->id;
		if (cyl->disk_top->coord)
			free(cyl->disk_top->coord);
		cyl->disk_top->coord = ft_addition(cyl->coord, ft_scal_one(norm_vec, cyl->height/ 2));
		if (cyl->disk_top->vector)
			free(cyl->disk_top->vector);
		cyl->disk_top->vector = ft_scal_one(cyl->vector, 1.0);
		cyl->disk_top->color = cyl->color;
	}
}

void set_disk(t_cyl *cyl,int check_pos)
{
	t_coord *norm_vec;

	norm_vec = normalize_vector(cyl->vector);
	set_disk_pos_neg(cyl, check_pos,norm_vec);
	free(norm_vec);
}

float	get_base_cyl(t_coord *dir, t_coord *origin,  t_cyl *cyl,int check_pos)
{
	t_coord *xc;
	t_coord *norm;
	t_coord	*impact;
	t_coord *disk_coord;
	float	t_disk;

	set_disk(cyl,check_pos);
	if (check_pos == 0)
	{
		xc = ft_soustraction(origin, cyl->disk_bot->coord);
		norm = normalize_vector(cyl->disk_bot->vector);
		disk_coord = cyl->disk_bot->coord;
	}
	else 
	{
		xc = ft_soustraction(origin, cyl->disk_top->coord);
		norm = normalize_vector(cyl->disk_top->vector);
		disk_coord = cyl->disk_top->coord;
	}
	t_disk = ((-1) * (ft_scal(xc,norm))) / ft_scal(dir,norm);
	impact = ft_addition(origin, ft_scal_one(dir, t_disk));
	if (t_disk > 0.0001 && lenght_vector(ft_soustraction(impact, disk_coord)) <= cyl->diam /  2)
		return (free(impact),free(xc),free(norm),t_disk);
	return (free(impact),free(xc),free(norm),-1);
}

void intersec_disk_cyl(t_nearest *near,t_cyl *tmp,float t_top,float t_bot)
{
	if (t_top > 0.0001 && t_top < near->t_near)
	{
		near->t_near = t_top;
		near->near_obj = tmp->disk_top;
		near->cyl_parent = tmp;
		near->type = DISK; 
	}
	if (t_bot > 0.0001 && t_bot < near->t_near)
	{
		near->t_near = t_bot;
		near->near_obj = tmp->disk_bot;
		near->cyl_parent = tmp;
		near->type = DISK; 
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
		if (t > 0.0001 && t < near->t_near)
		{
			near->t_near = t;
			near->near_obj = tmp;
			near->type = CYL; 
		}
		intersec_disk_cyl(near, tmp, t_top, t_bot);
		tmp = tmp->next;
	}
}
