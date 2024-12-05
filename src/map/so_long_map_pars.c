/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_pars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 00:40:37 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/05 04:04:55 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	map_has_empty_line(char *map_in_line)
{
	if (ft_strnstr(map_in_line, "\n\n", ft_strlen(map_in_line)))
	{
		error_map(NULL);
		return (true);
	}
	return (false);
}

bool	map_is_rectangle(char **map)
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

bool	map_is_close(char **map)
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

bool	map_content(t_map *map)
{
	int i ;
	int j ;

	i = 0 ;
	while (map->map[++i])
	{
		j = 0 ;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == 'P')
				map->P++ ;
			if (map->map[i][j] == 'C')
				map->C++ ;
			if (map->map[i][j] == 'E')
				map->E++ ;
		}
	}
	if (map->P == 0 || map->P > 1
		|| map->E == 0 || map->E > 1
		|| map->C < 1)
		return (false);
	return (true);
}

bool	pars_map(t_map *map)
{
	if (!map_is_rectangle(map->map)
		|| !map_is_close(map->map)
		|| !map_content(map))
	{
		error_map();
		return (false);
	}
	return (true);
}
