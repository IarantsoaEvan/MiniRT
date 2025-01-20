/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:24:02 by mrambelo          #+#    #+#             */
/*   Updated: 2025/01/20 15:53:10 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# define RATIO 1
# define VECTOR 2
# define WIDTH 700
# define HEIGHT 540
# define AS_RATIO WIDTH / HEIGHT
# include <stdio.h> 
# include "structure.h"
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "../parsing/parsing.h"
# include <math.h>

int check_valid_object(char  **elem);
int check_valid_a_c_l(char  **elem);
int check_comma(char *str);
void	init_graph(t_data *rt);
int	close_win(t_data *data);


#endif