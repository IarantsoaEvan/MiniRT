/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:21:02 by irabesan          #+#    #+#             */
/*   Updated: 2025/02/06 14:04:59 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

void	change_flag_rot(int keycode, t_data *rt)
{
	if (keycode == 120)
		rt->flag_rot_x = 1;
	if (keycode == 121)
		rt->flag_rot_y = 1;
	if (keycode == 122)
		rt->flag_rot_z = 1;
}
int	ft_comb_rotation(int keycode, t_nearest *near_moove, t_data *rt)
{
	t_sphere *sphere;
	t_plane *plane;
	t_cyl *cyl;

	change_flag_rot(keycode, rt);	
	if (rt->flag_rot_x == 1 && )

}