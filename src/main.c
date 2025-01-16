/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:23:24 by mrambelo          #+#    #+#             */
/*   Updated: 2025/01/16 12:55:02 by mrambelo         ###   ########.fr       */
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
int fill_data(t_data *data,char **element)
{
	if (element)
	{
		if (!ft_strcmp(element[0],"A"))	
			return (fill_amb(&data->ambiante,element));
		else if (!ft_strcmp(element[0],"C"))
			return (fill_cam(&data->cam,element));
		else if (!ft_strcmp(element[0],"L"))
			return (fill_light(&data->light,element));
		else if (!ft_strcmp(element[0],"pl"))
			return (fill_plane(&data->plane,element));
		else if (!ft_strcmp(element[0],"sp"))
			return (fill_sphere(&data->sphere,element));
		else if (!ft_strcmp(element[0],"cy"))
			return (fill_cyl(&data->cyl,element));
		else
			return (printf("'%s' : invalid id\n",element[0]),0);
		return (1);
	}
	return (0);
}

int get_element(char **v_map,t_data *data)
{
	char **element;
	int i;

	i = -1;
	while (v_map[++i])
	{
		element = NULL;
		element = ft_split(v_map[i],' ');
		if (!fill_data(data,element))
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

int	fill_and_check_map_valid(char *map,t_data *data)
{
	int fd;
	char *g_map;
	char **v_map;

	g_map = NULL;
	v_map = NULL;
	fd = open(map,O_RDONLY);
	if (fd >= 3)
	{
		g_map = get_map(fd);
		v_map = ft_split(g_map,'\n');
		if (g_map)
			free(g_map);
		if (!get_element(v_map,data))
		{
			if (v_map)
				ft_free_str(v_map);
			return (0);
		}
		if (v_map)
			ft_free_str(v_map);
		return (1);
	}
	return (0);
}

int	main(int argc ,char **argv)
{
	t_data *data;
	
	data = init_data();
	if (!check_map_name(argv,argc))
		return (1);
	if (!fill_and_check_map_valid(argv[1],data))
		return(1);
	print_ambiante(data->ambiante);
	print_cam(data->cam);
	print_light(data->light);
	print_pl(data->plane);
	print_sp(data->sphere);
	print_cyl(data->cyl);
}