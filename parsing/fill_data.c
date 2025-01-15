/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 08:56:30 by mrambelo          #+#    #+#             */
/*   Updated: 2025/01/15 22:39:55 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int fill_elem_light(char *elem,t_light **light,int *flag)
{
	char **get_val;

	get_val = NULL;
	if (*flag == 0)
	{
		get_val = ft_split(elem,',');
		fill_coord(get_val,(*light)->coord);
		ft_free_str(get_val);
		*flag = 1;
	}
	else if (*flag == 1)
	{
		(*light)->ratio = ft_atflo(elem);
		if (!check_vec_or_rat((*light)->ratio ,RATIO))
			return (0);
		*flag = 2;
	}
	else
	{
		get_val = ft_split(elem,',');
		if (!check_and_fill_color(get_val,(*light)->color))
			return (ft_free_str(get_val),0);
	}
	return (1);
}

int fill_light(t_light **light,char **elem)
{
	int flag;
	int i;

	flag = 0;
	i = 0;
	*light = init_light();
	while (elem[++i])
	{
		if (!fill_elem_light(elem[i],light,&flag))
			return (0);
	}
	return (1);
}
int fill_amb(t_ambiante **ambiante,char **element)
{
	int i;
	char **get_value;

	i = 0;
	(*ambiante) = init_amb();	
	while (element[++i])
	{
		get_value = NULL;
		if (ft_count_char_in_str(element[i],','))
		{
			get_value = ft_split(element[i],',');
			if (!check_and_fill_color(get_value,(*ambiante)->color))
				return (ft_free_str(get_value),0);
		}
		else
		{
			(*ambiante)->ratio = ft_atflo(element[i]);
			if (!check_vec_or_rat((*ambiante)->ratio ,RATIO))
				return (0);
		}
		if (get_value)
			ft_free_str(get_value);
	}
	return (1);
}



