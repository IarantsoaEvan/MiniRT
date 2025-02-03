/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 08:00:09 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/03 14:38:23 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shadow.h"

int intersec_lum_sphere(t_fct *fct,t_data *rt,int id,float t_lum)
{
	t_sphere *tmp;
	float t;


	// (void)t_lum;
	tmp = rt->sphere;
	while (tmp)
	{
		if (tmp->id != id)
		{
			ft_set_abc_sphere(fct,tmp,fct->origin);
			t = get_t_sphere(fct->pol, get_delta(fct->pol));
			printf("t  = %f\n",t);
			printf("t_lum = %f\n\n",t_lum);
			if (t > 0 && t < t_lum)
				return (SHADOW);
		}
		tmp = tmp->next;
	}
	return (NO_SHADOW);
}

int	ray_shadowing(t_data *rt, t_coord *impact,int id)
{
	
	t_fct	fct;
	float	t_lum;
	t_coord *tmp_dir;
	int shadow;

	
	// shadow = NO_SHADOW;
	fct.origin = impact;
	fct.pol = init_pol();
	fct.dir = ft_soustraction(rt->light->coord, impact);
	tmp_dir = ft_soustraction(impact, rt->light->coord);
	t_lum = lenght_vector(tmp_dir);
	shadow = intersec_lum_sphere(&fct,rt,id,t_lum);
	return(shadow);
}