/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:23:24 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/12 21:09:05 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


int fill_data(t_data *data,char **element)
{
	if (element)
	{
		if (!check_valid_element(element))
			return (0);
		if (!ft_strcmp(element[0],"A"))	
			return (fill_amb(&data->ambiante,element));
		else if (!ft_strcmp(element[0],"C"))
			return (fill_cam(&data->cam,element));
		else if (!ft_strcmp(element[0],"L"))
			return (fill_light(&data->light,element));
		else if (!ft_strcmp(element[0],"pl"))
			return (fill_plane(&data->plane,element));
		else if (!ft_strcmp(element[0],"sp"))
			return (fill_sphere(&data->sphere,element));
		else if (!ft_strcmp(element[0],"cy"))
			return (fill_cyl(&data->cyl,element));
		else
			return (printf("'%s' : invalid id\n",element[0]),0);
		return (1);
	}
	return (0);
}

int	main(int argc ,char **argv)
{
	t_data *data;
	
	data = init_data();
	data->near_moove = init_nearest();
	if (!check_map_name(argv,argc))
		return (1);
	if (!fill_and_check_map_valid(argv[1],data))
		return(1);
	init_graph(data);
	ray_tracing(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	// mlx_key_hook(data->win_ptr, esc_win, data);
	mlx_hook(data->win_ptr, 17, 0L, close_win, data);
	mlx_hook(data->win_ptr, 4, 1L << 2, mouse_handler, data);
	mlx_hook(data->win_ptr, 2, 1L << 0, keyboard_handler, data);
	mlx_hook(data->win_ptr, 3, 1L << 1, no_comb, data);
	mlx_loop(data->mlx_ptr);
}