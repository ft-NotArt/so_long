/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 00:40:37 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/18 08:04:53 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	check_map_char(char **map, char *charset)
{
	int	x ;
	int	y ;

	y = -1 ;
	while (map[++y])
	{
		x = -1 ;
		while (map[y][++x])
		{
			if (!ft_strchr(charset, map[y][x]))
				return (false);
		}
	}
	return (true);
}

static bool	map_is_rectangle(t_map *map)
{
	int		i ;

	i = 0 ;
	map->width = ft_strlen(map->map[i]);
	while (map->map[++i])
	{
		if (ft_strlen(map->map[i]) != map->width)
			return (false);
	}
	map->height = i ;
	return (true);
}

static bool	map_is_closed(t_map *map)
{
	size_t	i ;

	i = 0 ;
	while (i < map->width)
	{
		if (map->map[0][i] != '1' || map->map[map->height - 1][i] != '1')
			return (false);
		i++ ;
	}
	i = 0 ;
	while (i < map->height)
	{
		if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
			return (false);
		i++ ;
	}
	return (true);
}

static bool	map_content(t_map *map)
{
	int	i ;
	int	j ;
	int	p ;
	int	e ;

	p = 0 ;
	e = 0 ;
	i = 0 ;
	while (map->map[++i])
	{
		j = 0 ;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == 'P')
				p++ ;
			if (is_enemy(map->map[i][j]))
				map->enemy_number++ ;
			if (map->map[i][j] == 'E')
				e++ ;
		}
	}
	if (p != 1 || e != 1 || map->enemy_number < 1)
		return (false);
	return (true);
}

bool	pars_map(t_map *map)
{
	if (!check_map_char(map->map, MAP_CHARSET)
		|| !map_is_rectangle(map)
		|| !map_is_closed(map)
		|| !map_content(map)
		|| !check_flood_fill(map))
		return (false);
	return (true);
}
