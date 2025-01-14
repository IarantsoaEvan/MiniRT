/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:23:24 by mrambelo          #+#    #+#             */
/*   Updated: 2025/01/14 19:56:02 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_map_name(char **argv,int argc)
{
	int len;

	if (argc != 2)
	{
		printf("Please enter only one map!\n");
		return (0);
	}
	len = ft_strlen(argv[1]);
	len--;
	if (argv  && argv[1] && (argv[1][len] == 't' && argv[1][len - 1] == 'r'
		&& argv[1][len - 2] == '.'))
		return (1);
	printf("The map name must be a .rt file\n");
	return (0);
}

int	check_map_valid(char *map)
{
	int fd;

	fd = open(map,O_RDONLY);
	if (fd >= 3)
	{
		
	}
	return (0);
}

int	main(int argc ,char **argv)
{
	if (!check_map_name(argv,argc))
		return (1);
	check_map_valid(argv[1]);
	
}