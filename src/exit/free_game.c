/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 00:13:00 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/18 15:21:53 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map)
{
	if (map != NULL)
	{
		free_str_array(map->map);
		free_enemies(&map->enemies);
		free_bosses(&map->bosses);
		free(map->player->attack);
		free(map->player);
		free(map);
	}
}

void	free_maps(t_map *maps)
{
	t_map	*next ;

	while (maps)
	{
		next = maps->next ;
		free_map(maps);
		maps = next ;
	}
}

void	free_game(t_game *game)
{
	free_maps(game->maps);
	free(game);
}
