/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:01:07 by mrambelo          #+#    #+#             */
/*   Updated: 2025/01/28 19:10:04 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

void get_abc_cyl(t_data *rt,t_fct *fct,t_cyl *cyl)
{
	t_coord *norm_vec;
	t_coord *x;
	float scal_dir;

	norm_vec = normalize_vector(cyl->vector);
	x = ft_soustraction(rt->cam->coord,cyl->coord);
	scal_dir = ft_scal(fct->dir,fct->dir);
	fct->pol->a = scal_dir - powf(ft_scal(fct->dir,norm_vec),2);
	fct->pol->b = (ft_scal(fct->dir,x) - (ft_scal(fct->dir,norm_vec) * ft_scal(x,norm_vec))) * 2;
	fct->pol->c = ft_scal(x,x) - powf(ft_scal(x,norm_vec),2) - powf((float)(cyl->diam / 2),2);
}

int	create_cyl_rgb_finale(float t,t_fct *fct,t_data *rt, t_cyl *cyl)
{
	t_coord *point;
	t_color *color;
	t_color *rgb_diff;
	t_color *rgb_finale;
	int rgb;
	
	point = ft_addition(rt->cam->coord,ft_scal_one(fct->dir, t));
	color = apply_amb(cyl->color, rt->ambiante->ratio);
	rt->light->normal = get_normal_light(rt,point);
	cyl->normal = get_normal_cyl(rt, point, cyl);
	rgb_diff = get_rgb_diff(cyl->normal
		,rt->light->normal,rt->light->ratio,cyl->color);
	rgb_finale = add_amb_and_diff(color,rgb_diff);
	rgb = create_trgb(rgb_finale->r, rgb_finale->g, rgb_finale->b);
	return (rgb);
}
float	get_m_scal(t_fct *fct, t_data *rt, float t,t_cyl *cyl)
{
	t_coord *norm_vec;
	t_coord	*x;

	norm_vec = normalize_vector(cyl->vector);
	x = ft_soustraction(rt->cam->coord,cyl->coord);
	cyl->m = (ft_scal(fct->dir, norm_vec) * t) + ft_scal(x, norm_vec);
	return (cyl->m);
}

float get_t_cyl(t_fct *fct, float delta, t_data *rt,t_cyl *cyl)
{
    float   t1;
    float   t2;
    float   distance;
	
    distance = -1;
    if (delta == 0)
    {
        t1 = (fct->pol->b * (-1)) / (2 * fct->pol->a);
		cyl->m = get_m_scal(fct, rt, t1,cyl);
		if (cyl->m >= -cyl->height / 2 && cyl->m >= cyl->height / 2)
            distance = t1;
    }
    else if (delta > 0)
    {
        t1 = (((-1) * fct->pol->b) - (sqrt(delta))) / (2 * fct->pol->a);
        t2 = (((-1) * fct->pol->b) + (sqrt(delta))) / (2 * fct->pol->a);
        if (t1 > 0)
        {
            cyl->m = get_m_scal(fct, rt, t1,cyl);
            if (cyl->m >= -cyl->height / 2 && cyl->m <= cyl->height / 2)
                distance = t1;
        }
        if (t2 > 0)
        {
           cyl->m = get_m_scal(fct, rt, t2,cyl);
            if (cyl->m >= -cyl->height / 2 &&cyl->m <= cyl->height / 2 && (distance < 0 || t2 < t1))
                distance = t2;
        }
    }
    return (distance);
}
void intersec_cyl(t_fct *fct,t_data *rt)
{
	t_cyl *tmp;
	float t;
	// int rgb;
	// t_color *color;

	// color = init_color();
	// rgb = 0;
	tmp = rt->cyl;
	rt->near->t_near = INFINITY;
	while (tmp)
	{
		get_abc_cyl(rt,fct,tmp);
		t = get_t_cyl(fct, get_delta(fct->pol), rt,tmp);
		if (t > 0 && t < rt->near->t_near)
		{
			rt->near->t_near = t;
			rt->near->near_obj = tmp;
			rt->near->type = CYL; 
		}
		// if (t > 0)
		// {
			// rgb = create_cyl_rgb_finale(t, fct, rt, get_m_scal(fct, rt, t));
			// color = apply_amb(rt->cyl->color, rt->ambiante->ratio);
			// rgb = create_trgb(color->r, color->g, color->b);
			// mlx_pixel_put(rt->mlx_ptr, rt->win_ptr, (int)x, (int)y, rgb);
		// }
		tmp = tmp->next;
	}
}