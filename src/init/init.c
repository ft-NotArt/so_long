/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:46:43 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/10 02:00:40 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_player	*player_init(void)
{
	t_player	*player ;

	player = malloc(sizeof(t_player));
	player->image = NULL ;
	player->x = 0 ;
	player->y = 0 ;
	player->orient = EAST ;
	player->pose = STANDING ;
	player->last_action_time = 0 ;
	return (player);
}

t_map	*map_init(char *map_file)
{
	t_map	*map ;

	map = malloc(sizeof(t_map));
	map->map = read_map(map_file);
	map->width = 0 ;
	map->height = 0 ;
	map->C = 0 ;
	map->player = player_init();
	map->next = NULL ;
	return (map);
}

t_game	*game_init(t_map *maps)
{
	t_game	*game ;

	game = malloc(sizeof(t_game));
	game->maps = maps ;
	game->mlx = mlx_init(game->maps->width * BITS, game->maps->height * BITS,
		"TEST", true);
	return (game);
}
