/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 09:43:25 by irabesan          #+#    #+#             */
/*   Updated: 2025/02/05 10:03:39 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

int	esc_win(int keycode, t_data *rt)
{
	if (keycode == 65307)
	{
		mlx_destroy_image(rt->mlx_ptr, rt->img_ptr);
		mlx_destroy_window(rt->mlx_ptr, rt->win_ptr);
		mlx_destroy_display(rt->mlx_ptr);
		free(rt->mlx_ptr);
		free(rt);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int mouse_handler(int keycode , int x, int y, t_data *rt)
{
	(void)rt;
	if (keycode == 1 || keycode == 2)
	{
		printf("keycode = %d\n", keycode);
		printf("x = %d, y = %d\n", x, y);
	}
	return (0);
}