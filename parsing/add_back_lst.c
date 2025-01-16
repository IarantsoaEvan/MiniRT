/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_back_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:57:48 by mrambelo          #+#    #+#             */
/*   Updated: 2025/01/16 12:47:12 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_add_back_plane(t_plane **plane, t_plane *new)
{
	t_plane	*temp;

	temp = *plane;
	while (temp && temp->next)
		temp = temp->next;
	if (!temp)
		*plane = new;
	else
		temp->next = new;
}

void	ft_add_back_sphere(t_sphere **sphere, t_sphere *new)
{
	t_sphere	*temp;

	temp = *sphere;
	while (temp && temp->next)
		temp = temp->next;
	if (!temp)
		*sphere = new;
	else
		temp->next = new;
}

void	ft_add_back_cyl(t_cyl **cyl, t_cyl *new)
{
	t_cyl	*temp;

	temp = *cyl;
	while (temp && temp->next)
		temp = temp->next;
	if (!temp)
		*cyl = new;
	else
		temp->next = new;
}