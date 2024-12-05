/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:24:48 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/05 05:29:42 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	map_has_empty_line(char *map_in_line)
{
	if (ft_strnstr(map_in_line, "\n\n", ft_strlen(map_in_line)))
	{
		error_map(NULL);
		return (true);
	}
	return (false);
}

static char	**read_map(char *map_file)
{
	char	**res ;
	char	*line ;
	char	*map_in_line ;
	char	*tmp ;
	int		fd ;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		return (perror(map_file), NULL);
	map_in_line = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		tmp = ft_strjoin(map_in_line, line);
		(free(map_in_line), free(line));
		map_in_line = tmp;
		line = get_next_line(fd);
	}
	close(fd);
	if (map_has_empty_line(map_in_line))
		return (free(map_in_line), NULL);
	res = ft_split(map_in_line, '\n');
	free(map_in_line);
	return (res);
}

static t_map	*map_init(char *map_file)
{
	t_map	*map ;

	map = malloc(sizeof(t_map));
	map->map = read_map(map_file);
	map->P = 0 ;
	map->C = 0 ;
	map->E = 0 ;
	map->next = NULL ;
	return (map);
}

t_map	*maps_init(int argc, char *argv[])
{
	t_map	*maps ;
	t_map	*current ;
	t_map	*next ;
	int		i ;

	i = 1 ;
	maps = map_init(argv[i]);
	if (!maps->map || !pars_map(maps))
		return (free_maps(maps), NULL);
	current = maps ;
	while (++i < argc)
	{
		next = map_init(argv[i]);
		current->next = next ;
		if (!next->map || !pars_map(next))
			return (free_maps(maps), NULL);
		current = current->next ;
	}
	return (maps);
}
