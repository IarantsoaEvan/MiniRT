/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 08:00:24 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/12 10:06:24 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADOW_H
# define SHADOW_H
#include "../src/minirt.h"


int	ray_shadowing(t_data *rt, t_coord *impact,t_nearest *current);
int check_self(t_nearest *current,t_fct *fct);
#endif