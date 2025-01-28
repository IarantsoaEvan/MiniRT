/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:01:07 by mrambelo          #+#    #+#             */
/*   Updated: 2025/01/28 12:02:33 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

void get_abc_cyl(t_data *rt,t_fct *fct)
{
	t_coord *norm_vec;
	t_coord *x;
	float scal_dir;

	norm_vec = normalize_vector(rt->cyl->vector);
	x = ft_soustraction(rt->cam->coord,rt->cyl->coord);
	scal_dir = ft_scal(fct->dir,fct->dir);
	fct->pol->a = scal_dir - powf(ft_scal(fct->dir,norm_vec),2);
	fct->pol->b = (ft_scal(fct->dir,x) - (ft_scal(fct->dir,norm_vec) * ft_scal(x,norm_vec))) * 2;
	fct->pol->c = ft_scal(x,x) - powf(ft_scal(x,norm_vec),2) - powf((float)(rt->cyl->diam / 2),2);
}

int	create_cyl_rgb_finale(float t,t_fct *fct,t_data *rt, float m,void *tmp)
{
	t_coord *point;
	t_color *color;
	t_color *rgb_diff;
	t_color *rgb_finale;
	t_cyl	*cyl;
	int rgb;

	cyl = (t_cyl *)tmp;
	point = ft_addition(rt->cam->coord,ft_scal_one(fct->dir, t));
	color = apply_amb(cyl->color, rt->ambiante->ratio);
	rt->light->normal = get_normal_light(rt,point);
	cyl->normal = get_normal_cyl(rt, point, m);
	rgb_diff = get_rgb_diff(cyl->normal
		,rt->light->normal,rt->light->ratio,cyl->color);
	rgb_finale = add_amb_and_diff(color,rgb_diff);
	rgb = create_trgb(rgb_finale->r, rgb_finale->g, rgb_finale->b);
	return (rgb);
}
float	get_m_scal(t_fct *fct, t_data *rt, float t,void *tmp)
{
	t_coord *norm_vec;
	t_cyl	*cyl;
	float	m;
	t_coord	*x;

	cyl = (t_cyl *)tmp;
	norm_vec = normalize_vector(cyl->vector);
	x = ft_soustraction(rt->cam->coord,cyl->coord);
	m = (ft_scal(fct->dir, norm_vec) * t) + ft_scal(x, norm_vec);
	return (m);
}

float get_t_cyl(t_fct *fct, float delta, t_data *rt,t_cyl *tmp)
{
    float   t1;
    float   t2;
    float   distance;
    float   m;
	
    distance = -1;
    if (delta == 0)
    {
        t1 = (fct->pol->b * (-1)) / (2 * fct->pol->a);
		m = get_m_scal(fct, rt, t1,tmp);
		if (m >= -tmp->height / 2 && m >= tmp->height / 2)
            distance = t1;
    }
    else if (delta > 0)
    {
        t1 = (((-1) * fct->pol->b) - (sqrt(delta))) / (2 * fct->pol->a);
        t2 = (((-1) * fct->pol->b) + (sqrt(delta))) / (2 * fct->pol->a);
        if (t1 > 0)
        {
            m = get_m_scal(fct, rt, t1,tmp);
            if (m >= -tmp->height / 2 && m <= tmp->height / 2)
                distance = t1;
        }
        if (t2 > 0)
        {
            m = get_m_scal(fct, rt, t2,tmp);
            if (m >= -tmp->height / 2 && m <= tmp->height / 2 && (distance < 0 || t2 < t1))
                distance = t2;
        }
    }
    return (distance);
}
void intersec_cyl(t_fct *fct,t_data *rt)
{
	t_cyl *tmp;
	float t;
	int rgb;
	// t_color *color;

	// color = init_color();
	rgb = 0;
	tmp = rt->cyl;
	while (tmp)
	{
		get_abc_cyl(rt,fct);
		t = get_t_cyl(fct, get_delta(fct->pol), rt,tmp);
		if (t < rt->obj_nearest->t)
		{
			rt->obj_nearest->t = t;
			rt->obj_nearest->obj = tmp;
			rt->obj_nearest->type = CYL;
			// rgb = create_cyl_rgb_finale(t, fct, rt, get_m_scal(fct, rt, t));
			// color = apply_amb(rt->cyl->color, rt->ambiante->ratio);
			// rgb = create_trgb(color->r, color->g, color->b);
			// mlx_pixel_put(rt->mlx_ptr, rt->win_ptr, (int)x, (int)y, rgb);
		}
		tmp = tmp->next;
	}
}