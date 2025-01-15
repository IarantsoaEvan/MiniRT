/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 22:07:07 by mrambelo          #+#    #+#             */
/*   Updated: 2025/01/15 22:24:49 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void print_ambiante(t_ambiante *ambiante)
{
	printf("-------------AMBIANTE------------\n");
	printf("ratio = %f\n",ambiante->ratio);
	printf("red = %d\n",ambiante->color->r);
	printf("green = %d\n",ambiante->color->g);
	printf("blue = %d\n",ambiante->color->b);
	printf("-------------------------\n");
}
void print_cam(t_camera *cam)
{
	printf("----------CAM----------\n");
	printf("----------coord----------\n");
	printf("coord x = %f\n",cam->coord->x);
	printf("coord y = %f\n",cam->coord->y);
	printf("coord z = %f\n",cam->coord->z);
	printf("----------vector----------\n");
	printf("vector x = %f\n",cam->vector->x);
	printf("vector y = %f\n",cam->vector->y);
	printf("vector z = %f\n",cam->vector->z);
	printf("----------FOV----------\n");
	printf("FOV = %f\n",cam->fov);
	printf("-------------------------\n");
}

void print_light(t_light *light)
{
	printf("----------LIGHT----------\n");
	printf("----------coord----------\n");
	printf("coord x = %f\n",light->coord->x);
	printf("coord y = %f\n",light->coord->y);
	printf("coord z = %f\n",light->coord->z);
	printf("----------COLOR----------\n");
	printf("color r = %d\n",light->color->r);
	printf("color g = %d\n",light->color->g);
	printf("color zb= %d\n",light->color->g);
	printf("----------RATIO----------\n");
	printf("RATIO = %f\n",light->ratio);
	printf("-------------------------\n");
}