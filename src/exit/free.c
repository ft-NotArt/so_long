/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 00:13:00 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/16 08:27:23 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_enemy(t_enemy *enemy)
{
	if (enemy->attack != NULL)
	{
		enemy->attack->image->enabled = false ;
		free(enemy->attack);
	}
	free(enemy);
}

void	free_enemies(t_enemy *enemies)
{
	t_enemy	*next ;

	while (enemies)
	{
		next = enemies->next ;
		free_enemy(enemies);
		enemies = next ;
	}
}

void	free_map(t_map *map)
{
	free_str_array(map->map);
	free_enemies(map->enemies);
	free(map->player->attack);
	free(map->player);
	free(map);
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
	free_map(game->maps);
	free(game);
}
