/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speculaire.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 08:58:02 by irabesan          #+#    #+#             */
/*   Updated: 2025/02/12 09:24:34 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "diffuse_light.h"

float	calculate_spec(t_light *light, t_data *rt)
{
	float	lpl;
	t_phong	phong;

	phong.intensity = 0.4;
	phong.k = 0.3;
	phong.n_pw = 2;
	phong.

}