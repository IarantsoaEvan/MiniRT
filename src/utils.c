/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:20:10 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/18 12:59:45 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_valid_object(char **elem)
{
	int		i;
	int		j;
	int		objet;
	char	**spl_val;

	i = -1;
	objet = 0;
	while (elem[++i])
	{
		spl_val = NULL;
		spl_val = ft_split(elem[i], ' ');
		j = -1;
		while (spl_val[++j])
		{
			if (!ft_strcmp(spl_val[j], "cy") || !ft_strcmp(spl_val[j], "pl")
				|| !ft_strcmp(spl_val[j], "sp"))
				objet++;
		}
		ft_free_str(spl_val);
	}
	if (objet == 0)
		return (printf("Error:\nNo objet deteced!\n"), 0);
	return (1);
}

void	check_nb_a_c_l(int *a, int *c, int *l, char **spl_val)
{
	int	j;

	j = -1;
	while (spl_val[++j])
	{
		if (!ft_strcmp(spl_val[j], "A"))
			(*a)++;
		if (!ft_strcmp(spl_val[j], "C"))
			(*c)++;
		if (!ft_strcmp(spl_val[j], "L"))
			(*l)++;
	}
}

int	check_valid_a_c_l(char **elem)
{
	int		a;
	int		c;
	int		l;
	int		i;
	char	**spl_val;

	i = -1;
	a = 0;
	c = 0;
	l = 0;
	while (elem[++i])
	{
		spl_val = NULL;
		spl_val = ft_split(elem[i], ' ');
		check_nb_a_c_l(&a, &c, &l, spl_val);
		ft_free_str(spl_val);
	}
	if (a != 1 || c != 1 || l != 1)
		return (printf("Error:\nInvalid map!\n"), 0);
	return (1);
}

int	check_comma(char *str)
{
	if (ft_count_char_in_str(str, ',') != 2)
		return (printf("Error:\nPlease check comma in coord or vector!\n"), 0);
	return (1);
}
