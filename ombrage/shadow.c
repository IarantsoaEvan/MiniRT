/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 08:00:09 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/11 14:16:41 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shadow.h"

void intersec_lum_sphere(t_fct *fct,t_data *rt,t_nearest *current,float *t_near)
{
	t_sphere *tmp;
	float t;
	float te;
	t_sphere *sphere;

	sphere = (t_sphere *)current->near_obj;
	tmp = rt->sphere;
	if (current->type == SPHERE)
	{
		ft_set_abc_sphere(fct,sphere,fct->origin);
		te = get_t_sphere(fct->pol, get_delta(fct->pol));
		if (te > 0.001)
			return ;
	}
	while (tmp)
	{
		if (tmp->id != current->id)
		{
			ft_set_abc_sphere(fct,tmp,fct->origin);
			t = get_t_sphere(fct->pol, get_delta(fct->pol));
			if (t > 0 && t < *t_near)
				*t_near = t;
		}
		tmp = tmp->next;
	}
}

void intersec_lum_plane(t_fct *fct,t_data *rt,t_nearest *current,float *t_near)
{
	t_plane *tmp;
	float t;
	// float te;
	
	tmp = rt->plane;
	// te = get_t_plane(fct->dir,fct->origin,plane);
	// if (te > 0.001)
	// 	return ;
	while (tmp)
	{
		if (tmp->id != current->id)
		{
			t = get_t_plane(fct->dir,fct->origin,tmp);
			if (t > 0 && t < *t_near)
				*t_near = t;
		}
		tmp = tmp->next;
	}
}

void intersec_lum_cyl(t_fct *fct,t_data *rt,t_nearest *current,float *t_near)
{
	t_cyl *tmp;
	float	t;
	float	t_top;
	float	t_bot;
	float	te;
	t_cyl *cyl;

	cyl = (t_cyl *)current->near_obj;
	tmp = rt->cyl;
	te = INFINITY;
	if (current->type == CYL)
	{
		get_abc_cyl(fct->origin,fct,tmp);
		te = get_t_cyl(fct, get_delta(fct->pol), fct->origin,tmp);
		// t_top = get_base_cyl(fct->dir, fct->origin, tmp,1);
		// t_bot = get_base_cyl(fct->dir, fct->origin, tmp,0);
		// if (t > 0.0001 && t < te)
		// 	te = t;
		// if (t_top > 0.0001 && t_top < te)
		// 	te = t_top;
		// if (t_bot > 0.0001 && t_bot < te)
		// 	te = t_bot;
		
		if (te > 0.001)
		{
			printf("%f ato\n", te);
			return ;
		}
	}
	while (tmp)
	{
		// if (tmp->id == current->id)
		// 	printf("current->id = %d\n",current->id);
		if (tmp->id != current->id)
		{
			get_abc_cyl(fct->origin,fct,tmp);
			t = get_t_cyl(fct, get_delta(fct->pol), fct->origin,tmp);
			t_top = get_base_cyl(fct->dir, fct->origin, tmp,1);
			t_bot = get_base_cyl(fct->dir, fct->origin, tmp,0);
			if (t > 0.0001 && t < *t_near)
				*t_near = t;
			if (t_top > 0.0001 && t_top < *t_near)
				*t_near = t_top;
			if (t_bot > 0.0001 && t_bot < *t_near)
				*t_near = t_bot;
		}
		tmp = tmp->next;
	}
}


int intersec_obj_lum(float t_lum,float t_near)
{
	if (t_near < t_lum)
		return (SHADOW);
	return (NO_SHADOW);
}

int	ray_shadowing(t_data *rt, t_coord *impact,t_nearest *current)
{
	
	t_fct	fct;
	float	t_lum;
	t_coord *tmp_dir;
	float t_near;
	int shadow;

	
	// shadow = NO_SHADOW;
	t_near = INFINITY;
	fct.origin = impact;
	fct.pol = init_pol();
	fct.dir = normalize_vector_with_free(ft_soustraction(rt->light->coord, impact));
	tmp_dir = ft_soustraction(rt->light->coord, impact);
	t_lum = lenght_vector(tmp_dir);
	intersec_lum_sphere(&fct,rt, current,&t_near);
	intersec_lum_plane(&fct, rt, current,&t_near);
	intersec_lum_cyl(&fct, rt, current, &t_near);
	shadow = intersec_obj_lum(t_lum,t_near);
	free(fct.pol);
	free(fct.dir);
	return(shadow);
}