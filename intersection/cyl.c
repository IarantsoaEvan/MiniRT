/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:01:07 by mrambelo          #+#    #+#             */
/*   Updated: 2025/01/22 15:02:45 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

void get_abc_cyl(t_data *rt,t_fct *fct)
{
	t_coord *norm_vec;
	t_coord *x;
	float scal_dir;

	norm_vec = normalize_vector(rt->cyl->vector);
	x = ft_soustraction(fct->dir,rt->cyl->coord);
	scal_dir = ft_scal(fct->dir,fct->dir);
	fct->pol->a = (scal_dir - powf(ft_scal(fct->dir,norm_vec),2));
	fct->pol->b = (ft_scal(fct->dir,x) - (ft_scal(fct->dir,norm_vec) * ft_scal(x,norm_vec))) * 2;
	fct->pol->c = ft_scal(x,x) - powf(ft_scal(x,norm_vec),2) - powf((float)(rt->cyl->diam / 2),2);
	// printf("a = %f  | b = %f | c = %f\n",fct->pol->a,fct->pol->b,fct->pol->c);
	// return ()
}

float	get_m_scal(t_fct *fct, t_data *rt, float t)
{
	t_coord *norm_vec;
	float	m;
	t_coord	*x;

	norm_vec = normalize_vector(rt->cyl->vector);
	x = ft_soustraction(fct->dir,rt->cyl->coord);
	m = (ft_scal(fct->dir, norm_vec) * t) + ft_scal(x, norm_vec);
	return (m);
}

float get_t_cyl(t_fct *fct, float delta, t_data *rt)
{
	
	float	t1;
	float	t2;
	float	distance;

	distance = -1;

	if (delta == 0)
	{
		t1 = (fct->pol->b * (-1)) / (2 * fct->pol->a);
		return (t1);
	}
	else if (delta > 0)
	{
		t1 = (((-1) * fct->pol->b) - (sqrt(delta))) / (2 * fct->pol->a);
		t2 = (((-1) * fct->pol->b) + (sqrt(delta))) / (2 * fct->pol->a);
		if (t1 > 0 && get_m_scal(fct, rt, t1) >= 0
			&& get_m_scal(fct, rt, 1) <= rt->cyl->height)
			distance = t1;
		if (t2 > 0 && t2 < t1 && get_m_scal(fct, rt, t2) >= 0 && get_m_scal(fct, rt, t2) <= rt->cyl->height)
			distance = t2;
		if (t2 > 0 && t1 < 0  && get_m_scal(fct, rt, t2) >= 0 && get_m_scal(fct, rt, t2) <= rt->cyl->height)
			distance = t2;
	}
	return (distance);
}