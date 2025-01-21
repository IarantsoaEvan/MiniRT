/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 09:27:27 by irabesan          #+#    #+#             */
/*   Updated: 2025/01/21 14:16:05 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	get_delta(t_pol *pol)
{
	float delta;

	delta = (pol->b * pol->b) - (4 * (pol->a * pol->c));
	return (delta);
}

float get_t(t_pol *pol, float delta)
{
	float	t1;
	float	t2;
	float	distance;

	distance = -1;

	if (delta == 0)
	{
		t1 = (pol->b * (-1)) / (2 * pol->a);
		return (t1);
	}
	else if (delta > 0)
	{
		t1 = (((-1) * pol->b) - (sqrt(delta))) / (2 * pol->a);
		t2 = (((-1) * pol->b) + (sqrt(delta))) / (2 * pol->a);
		if (t1 > 0)
			distance = t1;
		if (t2 > 0 && (t2 < t1))
			distance = t2;
		if (t2 > 0 && t1 < 0)
			distance = t2;
	}
	return (distance);

}

void	ft_ndc(float *x, float *y)
{
	*x = (*x + 0.5) / (WIDTH / 2);
	*y = (*y + 0.5) / (HEIGHT / 2);
}

void	ft_screen(float *x_ndc, float *y_ndc, float *x_screen, float *y_screen)
{
	*x_screen = 2 * (*x_ndc) - 1;
	*y_screen = 2 * (*y_ndc) - 1;
}

void	ft_as_ratio(t_fct *fct, t_camera *cam)
{
	float	rad_alpha;

	rad_alpha = cam->fov * (M_PI / 180);
	fct->as_x = (2 * fct->x_screen - 1) * AS_RATIO * tan(rad_alpha / 2);
	fct->as_y = (1 - (2 * fct->y_screen)) * tan(rad_alpha / 2);
}


t_pol *init_pol()
{
	t_pol *pol;

	pol = malloc(sizeof(t_pol));
	pol->a = 0;
	pol->b = 0;
	pol->c = 0;
	return (pol);
}

t_fct *init_fct(void)
{
	t_fct *fct;

	fct = malloc(sizeof(t_fct));
	fct->as_x = 0;
	fct->as_y = 0;
	fct->x_ndc = 0;
	fct->y_ndc = 0;
	fct->x_screen = 0;
	fct->y_screen = 0;
	fct->as_z = 1;
	fct->dir = init_coord();
	fct->pol = init_pol();
	return (fct);
}



void set_direction(t_fct *fct, t_coord	*dir,t_camera *cam)
{
	float	magn;
	
	dir->x = fct->as_x - cam->coord->x;
	dir->y = fct->as_y - cam->coord->y;
	dir->z = fct->as_z - cam->coord->z;
	magn = sqrt((dir->x * dir->x) + (dir->y *dir->y) + (dir->z * dir->z));
	dir->x /= magn;
	dir->y /= magn;
	dir->z /= magn;
}



float ft_scal(t_coord *vect1,t_coord *vect2)
{
	float res;

	res = (vect1->x * vect2->x) + (vect1->y * vect2->y) + (vect1->z * vect2->z);
	return (res);
}

t_coord *ft_soustraction(t_data *rt)
{
	t_coord *oc;

	oc = init_coord();
	oc->x = rt->cam->coord->x - rt->sphere->coord->x;
	oc->y = rt->cam->coord->y - rt->sphere->coord->y;
	oc->z = rt->cam->coord->z - rt->sphere->coord->z;
	return(oc);
}


void ft_set_abc(t_fct *fct,t_data *rt)
{
	t_coord *oc;
	float r;

	r = rt->sphere->diam / 2;
	oc = ft_soustraction(rt);
	fct->pol->a = 1;
	fct->pol->b = 2 * ft_scal(oc,fct->dir);
	fct->pol->c = ft_scal(oc,oc) - (r * r);
}

void	ray_tracing(t_data *rt)
{
	float x;
	float	y;
	float	t;
	t_fct *fct;

	y = 0;
	fct = init_fct();
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			fct->x_ndc = x;
			fct->y_ndc = y;
			ft_ndc(&fct->x_ndc, &fct->y_ndc);
			ft_screen(&fct->x_ndc, &fct->y_ndc, &fct->x_screen, &fct->y_screen);
			ft_as_ratio(fct, rt->cam);
			set_direction(fct, fct->dir,rt->cam);
			ft_set_abc(fct, rt);
			t = get_t(fct->pol, get_delta(fct->pol));
			if (t > 0)
				mlx_pixel_put(rt->mlx_ptr, rt->win_ptr, (int)x, (int)y, 0xFF0000);
			// printf("x_x = %f   | d_y = %f   | d_z = %f\n",fct->dir->dx,fct->dir->y,fct->dir->y);
			x++;
		}
		y++;
	}
}