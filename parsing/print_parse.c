/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 22:07:07 by mrambelo          #+#    #+#             */
/*   Updated: 2025/01/27 13:49:14 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

// void print_ambiante(t_ambiante *ambiante)
// {
// 	printf("-------------AMBIANTE------------\n");
// 	printf("ratio = %f\n",ambiante->ratio);
// 	printf("red = %d\n",ambiante->color->r);
// 	printf("green = %d\n",ambiante->color->g);
// 	printf("blue = %d\n",ambiante->color->b);
// 	printf("-------------------------\n");
// }
// void print_cam(t_camera *cam)
// {
// 	printf("----------CAM----------\n");
// 	printf("----------coord----------\n");
// 	printf("coord x = %f\n",cam->coord->x);
// 	printf("coord y = %f\n",cam->coord->y);
// 	printf("coord z = %f\n",cam->coord->z);
// 	printf("----------vector----------\n");
// 	printf("vector x = %f\n",cam->vector->x);
// 	printf("vector y = %f\n",cam->vector->y);
// 	printf("vector z = %f\n",cam->vector->z);
// 	printf("----------FOV----------\n");
// 	printf("FOV = %f\n",cam->fov);
// 	printf("-------------------------\n");
// }

// void print_light(t_light *light)
// {
// 	printf("----------LIGHT----------\n");
// 	printf("----------coord----------\n");
// 	printf("coord x = %f\n",light->coord->x);
// 	printf("coord y = %f\n",light->coord->y);
// 	printf("coord z = %f\n",light->coord->z);
// 	printf("----------COLOR----------\n");
// 	printf("color r = %d\n",light->color->r);
// 	printf("color g = %d\n",light->color->g);
// 	printf("color zb= %d\n",light->color->b);
// 	printf("----------RATIO----------\n");
// 	printf("RATIO = %f\n",light->ratio);
// 	printf("-------------------------\n");
// }


// void print_pl(t_plane *pl)
// {
// 	while (pl)
// 	{
// 		printf("----------PLANE----------\n");
// 		printf("ID = %d\n",pl->id);
// 		printf("----------coord----------\n");
// 		printf("coord x = %f\n",pl->coord->x);
// 		printf("coord y = %f\n",pl->coord->y);
// 		printf("coord z = %f\n",pl->coord->z);
// 		printf("----------vector----------\n");
// 		printf("vector x = %f\n",pl->vector->x);
// 		printf("vector y = %f\n",pl->vector->y);
// 		printf("vector z = %f\n",pl->vector->z);
// 		printf("----------COLOR----------\n");
// 		printf("color r = %d\n",pl->color->r);
// 		printf("color g = %d\n",pl->color->g);
// 		printf("color b= %d\n",pl->color->b);
// 		printf("\n\n");
// 		pl = pl->next;
// 	}

// }

// void print_sp(t_sphere *sphere)
// {
// 	while (sphere)
// 	{
// 		printf("----------SPHERE----------\n");
// 		printf("ID = %d\n",sphere->id);
// 		printf("----------COORD----------\n");
// 		printf("coord x = %f\n",sphere->coord->x);
// 		printf("coord y = %f\n",sphere->coord->y);
// 		printf("coord z = %f\n",sphere->coord->z);
// 		printf("----------DIAM----------\n");
// 		printf("diametre  = %f\n",sphere->diam);
// 		printf("----------COLOR----------\n");
// 		printf("color r = %d\n",sphere->color->r);
// 		printf("color g = %d\n",sphere->color->g);
// 		printf("color b= %d\n",sphere->color->b);
// 		printf("\n\n");
// 		sphere = sphere->next;
// 	}
// }

// void print_cyl(t_cyl *cyl)
// {
// 	while (cyl)
// 	{
// 		printf("----------CYLINDRE----------\n");
// 		printf("ID = %d\n",cyl->id);
// 		printf("----------COORD----------\n");
// 		printf("coord x = %f\n",cyl->coord->x);
// 		printf("coord y = %f\n",cyl->coord->y);
// 		printf("coord z = %f\n",cyl->coord->z);
// 		printf("----------VECTOR----------\n");
// 		printf("vector x = %f\n",cyl->vector->x);
// 		printf("vector y = %f\n",cyl->vector->y);
// 		printf("vector z = %f\n",cyl->vector->z);
// 		printf("----------DIAM----------\n");
// 		printf("diametre  = %f\n",cyl->diam);
// 		printf("----------HEIGHT----------\n");
// 		printf("heigth  = %f\n",cyl->height);
// 		printf("----------COLOR----------\n");
// 		printf("color r = %d\n",cyl->color->r);
// 		printf("color g = %d\n",cyl->color->g);
// 		printf("color b= %d\n",cyl->color->b);
// 		printf("\n\n");
// 		cyl = cyl->next;
// 	}
// }