/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 09:42:07 by irabesan          #+#    #+#             */
/*   Updated: 2025/02/07 08:31:12 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H
# include "../src/minirt.h"

int	esc_win(int keycode, t_data *rt);
int mouse_handler(int keycode , int x, int y, t_data *rt);
int	keyboard_handler(int keycode, t_data *rt);
void trs_x(t_nearest *near_moove, int keycode);
void trs_y(t_nearest *near_moove, int keycode);
void	rot_foll_x(t_coord *rot, float alpha);
void	rot_foll_y(t_coord *rot, float beta);
void	rot_foll_z(t_coord *rot, float teta);
int no_comb(int keycode, t_data *rt);
void rot_x(int keycode, t_data *rt, t_nearest *near);


#endif