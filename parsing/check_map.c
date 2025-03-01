/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:39:30 by mrambelo          #+#    #+#             */
/*   Updated: 2025/03/01 09:07:38 by mrambelo         ###   ########.fr       */
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
		&& argv[1][len - 2] == '.') && argv[1][0] != '.'))
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
	char	*trim_gmap;
	char	**v_map;

	g_map = NULL;
	v_map = NULL;
	fd = open(map, O_RDONLY);
	if (fd >= 3)
	{
		g_map = get_map(fd);
		if (!g_map || ft_strlen(g_map) == 0)
			return (free(g_map),printf("Error\nMap is empty\n"), 0);
		trim_gmap = ft_strtrim(g_map, " \n\t");
		free_n_close(fd, g_map);
		v_map = ft_split(trim_gmap, '\n');
		if (trim_gmap)
			free(trim_gmap);
		if (!get_element(v_map, data))
		{
			if (v_map)
				return (ft_free_str(v_map), 0);
		}
		check_free_element(v_map);
		return (1);
	}
	return (printf("Error\nMap does not exist\n"), 0);
}

int	get_element(char **v_map, t_data *data)
{
	char	**element;
	char	*trim_vmap;
	int		i;

	i = -1;
	if (!check_valid_object(v_map) || !check_valid_a_c_l(v_map))
		return (0);
	while (v_map[++i])
	{
		if (ft_isspace(v_map[i]))
			continue ;
		trim_vmap = ft_strtrim(v_map[i], " \n\t");
		element = NULL;
		element = ft_split(trim_vmap, ' ');
		if (trim_vmap)
			free(trim_vmap);
		if (!fill_data(data, element))
		{
			check_free_element(element);
			return (0);
		}
		if (element)
			ft_free_str(element);
	}
	return (1);
}
