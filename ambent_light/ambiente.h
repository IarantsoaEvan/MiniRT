/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambiente.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:09:26 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/10 10:56:32 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMBIENTE_H
# define AMBIENTE_H
# include "../src/minirt.h"

t_color	*apply_amb(t_color *col_obj, float ratio_amb);
int		create_trgb(int r, int g, int b);
t_color	*apply_shadow_color(t_color *col_obj);

#endif