/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:23:59 by mrambelo          #+#    #+#             */
/*   Updated: 2025/01/14 12:44:29 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

typedef struct s_coord
{
   float x;
   float y;
   float z;
} t_coord;

typedef struct s_color
{
   float x;
   float y;
   float z;
} t_color;


typedef struct s_ambiante
{
    char *id;
    t_coord *coord;
    t_color * color;
   
   
} t_ambiante;
