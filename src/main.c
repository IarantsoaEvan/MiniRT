/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:23:24 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/25 09:20:38 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_data_cyl(t_data *data)
{
	if (data->cyl)
	{
		// if (data->cyl->coord)
		// 	free(data->cyl->coord);
		// if (data->cyl->color)
		// 	free(data->cyl->color);
		// if (data->cyl->vector)
		// 	free(data->cyl->vector);
		// free(data->cyl->disk_top);
		// free(data->cyl->disk_bot);
		// free(data->cyl);
		free_cyl(data->cyl);
	}
}

void	free_obj(t_data *data)
{
	if (data->sphere)
	{
		free_sphere(data->sphere);
		// if (data->sphere->color)
		// 	free(data->sphere->color);
		// if (data->sphere->coord)
		// 	free(data->sphere->coord);
		// free(data->sphere);
	}
	if (data->plane)
	{
		free_plane(data->plane);
		// if (data->plane->color)
		// 	free(data->plane->color);
		// if (data->plane->coord)
		// 	free(data->plane->coord);
		// if (data->plane->vector)
		// 	free(data->plane->vector);
		// free(data->plane);
	}
	free_data_cyl(data);
}

void	free_data(t_data *data)
{
	if (data->ambiante)
	{
		if (data->ambiante->color)
			free(data->ambiante->color);
		free(data->ambiante);
	}
	if (data->cam)
	{
		if (data->cam->coord)
			free(data->cam->coord);
		if (data->cam->vector)
			free(data->cam->vector);
		free(data->cam);
	}
	if (data->light)
	{
		if (data->light->coord)
			free(data->light->coord);
		if (data->light->color)
			free(data->light->color);
		free(data->light);
	}
	free_obj(data);
}

int	fill_data(t_data *data, char **element)
{
	// int i = 0;
	// while (element[i])
	// 	printf("elem = %s\n",element[i++]);
	if (element)
	{
		if (!check_valid_element(element))
			return (free_data(data), 0);
		if (!ft_strcmp(element[0], "A"))
			return (fill_amb(&data->ambiante, element, data));
		else if (!ft_strcmp(element[0], "C"))
			return (fill_cam(&data->cam, element, data));
		else if (!ft_strcmp(element[0], "L"))
			return (fill_light(&data->light, element, data));
		else if (!ft_strcmp(element[0], "pl"))
			return (fill_plane(&data->plane, element, data));
		else if (!ft_strcmp(element[0], "sp"))
			return (fill_sphere(&data->sphere, element, data));
		else if (!ft_strcmp(element[0], "cy"))
			return (fill_cyl(&data->cyl, element, data));
		else
			return (free_data(data), printf("Error\n'%s' : Invalid id\n",
					element[0]), 0);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = init_data();
	data->near_moove = init_nearest();
	if (!check_map_name(argv, argc))
		return (free(data->near_moove), free(data), 1);
	if (!fill_and_check_map_valid(argv[1], data))
		return (free(data->near_moove), free(data), 1);
	init_graph(data);
	ray_tracing(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	mlx_hook(data->win_ptr, 17, 0L, close_win, data);
	mlx_hook(data->win_ptr, 4, 1L << 2, mouse_handler, data);
	mlx_hook(data->win_ptr, 2, 1L << 0, keyboard_handler, data);
	mlx_hook(data->win_ptr, 3, 1L << 1, no_comb, data);
	mlx_loop(data->mlx_ptr);
}
