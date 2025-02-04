/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 08:00:09 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/04 11:43:12 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shadow.h"

void intersec_lum_sphere(t_fct *fct,t_data *rt,int id,float *t_near)
{
	t_sphere *tmp;
	float t;


	// (void)t_lum;
	tmp = rt->sphere;
	while (tmp)
	{
		printf("tmp->id = %d || id = %d\n",tmp->id,id);
		if (tmp->id != id)
		{
			ft_set_abc_sphere(fct,tmp,fct->origin);
			t = get_t_sphere(fct->pol, get_delta(fct->pol));
			if (t > 0 && t < *t_near)
				*t_near = t;
		}
		tmp = tmp->next;
	}
}

void intersec_lum_plane(t_fct *fct,t_data *rt,int id,float *t_near)
{
	t_plane *tmp;
	float t;
	
	tmp = rt->plane;
	while (tmp)
	{
		if (tmp->id != id)
		{
			t = get_t_plane(fct->dir,fct->origin,tmp);
			if (t > 0 && t < *t_near)
				*t_near = t;
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

int	ray_shadowing(t_data *rt, t_coord *impact,int id)
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
	intersec_lum_sphere(&fct,rt,id,&t_near);
	intersec_lum_plane(&fct, rt, id,&t_near);
	shadow = intersec_obj_lum(t_lum,t_near);
	return(shadow);
}