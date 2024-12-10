/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 02:10:19 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/10 16:46:35 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_enemies(t_enemy *enemy)
{
	t_enemy	*next ;

	while (enemy)
	{
		next = enemy->next ;
		free(enemy);
		enemy = next ;
	}
}

void	free_map(t_map *map)
{
	free_str_array(map->map);
	free_enemies(map->enemies);
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
