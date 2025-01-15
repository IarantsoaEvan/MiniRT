/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:24:02 by mrambelo          #+#    #+#             */
/*   Updated: 2025/01/15 14:30:43 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# define RATIO 1
# define VECTOR 2
# include <stdio.h> 
# include "structure.h"
# include "../libft/libft.h"

int fill_amb(t_ambiante **ambiante,char **element);
t_data *init_data(void);
t_ambiante  *init_amb(void);
t_camera    *init_cam(void);
void print_ambiante(t_ambiante *ambiante);
#endif