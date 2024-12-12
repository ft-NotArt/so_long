/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_extend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:23:35 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/12 16:35:11 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	extend_left(t_map *map)
{
	char	extend[MIN_WIDTH];
	char	*tmp ;
	size_t	i ;
	size_t	j ;

	ft_bzero(extend, MIN_WIDTH * sizeof(char));
	i = 0 ;
	while (i < (MIN_WIDTH - map->width) / 2)
	{
		extend[i] = '1' ;
		i++ ;
	}
	map->player->x += i ;
	j = 0 ;
	while (map->map[j])
	{
		tmp = ft_strjoin(extend, map->map[j]);
		free(map->map[j]);
		map->map[j] = tmp ;
		j++ ;
	}
	return (i);
}

static size_t	extend_right(t_map *map)
{
	char	extend[MIN_WIDTH];
	char	*tmp ;
	size_t	i ;
	size_t	j ;

	ft_bzero(extend, MIN_WIDTH * sizeof(char));
	i = 0 ;
	while (i < ((MIN_WIDTH - map->width) / 2) + ((MIN_WIDTH - map->width) % 2))
	{
		extend[i] = '1' ;
		i++ ;
	}
	j = 0 ;
	while (map->map[j])
	{
		tmp = ft_strjoin(map->map[j], extend);
		free(map->map[j]);
		map->map[j] = tmp ;
		j++ ;
	}
	return (i);
}

void	map_extend(t_map *map)
{
	size_t	ext_left ;
	size_t	ext_right ;

	ext_left = extend_left(map);
	ext_right = extend_right(map);
	map->width += ext_left + ext_right ;
}
