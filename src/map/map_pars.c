/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 00:40:37 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/05 12:05:32 by anoteris         ###   ########.fr       */
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

static bool	map_is_rectangle(char **map)
{
	size_t	len_ref ;
	int		i ;
	
	i = 0 ;
	len_ref = ft_strlen(map[i]);
	while (map[++i])
	{
		if (ft_strlen(map[i]) != len_ref)
			return (false);
	}
	return (true);
}

static bool	map_is_close(char **map)
{
	int	height ;
	int	width ;
	int	i ;

	i = 0 ;
	height = 0 ;
	while (map[i++])
		height++;
	width = ft_strlen(map[0]) ;
	i = -1 ;
	while (++i < width)
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (false);
	i = -1 ;
	while (++i < height)
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (false);
	return (true);
}

static bool	map_content(t_map *map)
{
	int i ;
	int j ;
	int P ;
	int E ;

	P = 0 ;
	E = 0 ;
	i = 0 ;
	while (map->map[++i])
	{
		j = 0 ;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == 'P')
				P++ ;
			if (map->map[i][j] == 'C')
				map->C++ ;
			if (map->map[i][j] == 'E')
				E++ ;
		}
	}
	if (P != 1 || E != 1 || map->C < 1)
		return (false);
	return (true);
}

bool	pars_map(t_map *map)
{
	if (!check_map_char(map->map, "01PEC")
		|| !map_is_rectangle(map->map)
		|| !map_is_close(map->map)
		|| !map_content(map)
		|| !check_flood_fill(map))
	{
		error_map();
		return (false);
	}
	return (true);
}
