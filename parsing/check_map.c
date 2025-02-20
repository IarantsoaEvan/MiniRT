/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:39:30 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/20 20:19:40 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_map_name(char **argv, int argc)
{
	int	len;

	if (argc != 2)
	{
		printf("Error\nPlease enter only one map!\n");
		return (0);
	}
	len = ft_strlen(argv[1]);
	len--;
	if ((argv && argv[1] && (argv[1][len] == 't' && argv[1][len - 1] == 'r'
			&& argv[1][len - 2] == '.') && argv[1][0] != '.' ))
		return (1);
	printf("Error\nThe map name must be a file with .rt extention\n");
	return (0);
}

char	*get_map(int fd)
{
	char	*map;
	char	*buf;

	map = ft_strdup("");
	while (1)
	{
		buf = get_next_line(fd);
		if (buf == NULL)
			break ;
		map = ft_strjoin(map, buf);
		free(buf);
	}
	return (map);
}

int	fill_and_check_map_valid(char *map, t_data *data)
{
	int		fd;
	char	*g_map;
	char	**v_map;

	g_map = NULL;
	v_map = NULL;
	fd = open(map, O_RDONLY);
	if (fd >= 3)
	{
		g_map = get_map(fd);
		close(fd);
		v_map = ft_split(g_map, '\n');
		if (g_map)
			free(g_map);
		if (!get_element(v_map, data))
		{
			if (v_map)
				return (ft_free_str(v_map), 0);
		}
		if (v_map)
			ft_free_str(v_map);
		return (1);
	}
	printf("Error\nMap does not exist\n");
	return (0);
}

int	get_element(char **v_map, t_data *data)
{
	char	**element;
	int		i;

	i = -1;
	if (!check_valid_object(v_map) || !check_valid_a_c_l(v_map))
		return (0);
	while (v_map[++i])
	{
		element = NULL;
		element = ft_split(v_map[i], ' ');
		if (!fill_data(data, element))
		{
			if (element)
				ft_free_str(element);
			return (0);
		}
		if (element)
			ft_free_str(element);
	}
	return (1);
}
