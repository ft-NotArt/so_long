/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:00:55 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/16 21:16:39 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_east(t_game *game, t_player *player, t_enemy *enemy)
{
	if (player != NULL && game->maps->map[player->y][player->x + 1] != '1'
		&& game->maps->map[player->y][player->x + 1] != 'E')
	{
		game->maps->map[player->y][player->x + 1] = 'P' ;
		game->maps->map[player->y][player->x] = '0' ;
		player->image->instances->x += BITS ;
		player->x++ ;
		update_step_count(game);
	}
	else if (enemy != NULL && game->maps->map[enemy->y][enemy->x + 1] != '1'
		&& game->maps->map[enemy->y][enemy->x + 1] != 'E'
		&& !is_enemy(game->maps->map[enemy->y][enemy->x + 1]))
	{
		game->maps->map[enemy->y][enemy->x + 1] = enemy->type ;
		game->maps->map[enemy->y][enemy->x] = '0' ;
		enemy->image->instances->x += BITS ;
		enemy->x++ ;
	}
}

void	move_south(t_game *game, t_player *player, t_enemy *enemy)
{
	if (player != NULL && game->maps->map[player->y + 1][player->x] != '1'
			&& game->maps->map[player->y + 1][player->x] != 'E')
	{
		game->maps->map[player->y + 1][player->x] = 'P' ;
		game->maps->map[player->y][player->x] = '0' ;
		player->image->instances->y += BITS ;
		player->y++ ;
		update_step_count(game);
	}
	else if (enemy != NULL && game->maps->map[enemy->y + 1][enemy->x] != '1'
		&& game->maps->map[enemy->y + 1][enemy->x] != 'E'
		&& !is_enemy(game->maps->map[enemy->y + 1][enemy->x]))
	{
		game->maps->map[enemy->y + 1][enemy->x] = enemy->type ;
		game->maps->map[enemy->y][enemy->x] = '0' ;
		enemy->image->instances->y += BITS ;
		enemy->y++ ;
	}
}

void	move_west(t_game *game, t_player *player, t_enemy *enemy)
{
	if (player != NULL && game->maps->map[player->y][player->x - 1] != '1'
		&& game->maps->map[player->y][player->x - 1] != 'E')
	{
		game->maps->map[player->y][player->x - 1] = 'P' ;
		game->maps->map[player->y][player->x] = '0' ;
		player->image->instances->x -= BITS ;
		player->x-- ;
		update_step_count(game);
	}
	else if (enemy != NULL && game->maps->map[enemy->y][enemy->x - 1] != '1'
		&& game->maps->map[enemy->y][enemy->x - 1] != 'E'
		&& !is_enemy(game->maps->map[enemy->y][enemy->x - 1]))
	{
		game->maps->map[enemy->y][enemy->x - 1] = enemy->type ;
		game->maps->map[enemy->y][enemy->x] = '0' ;
		enemy->image->instances->x -= BITS ;
		enemy->x-- ;
	}
}

void	move_north(t_game *game, t_player *player, t_enemy *enemy)
{
	if (player != NULL && game->maps->map[player->y - 1][player->x] != '1'
		&& game->maps->map[player->y - 1][player->x] != 'E')
	{
		game->maps->map[player->y - 1][player->x] = 'P' ;
		game->maps->map[player->y][player->x] = '0' ;
		player->image->instances->y -= BITS ;
		player->y-- ;
		update_step_count(game);
	}
	else if (enemy != NULL && game->maps->map[enemy->y - 1][enemy->x] != '1'
		&& game->maps->map[enemy->y - 1][enemy->x] != 'E'
		&& !is_enemy(game->maps->map[enemy->y - 1][enemy->x]))
	{
		game->maps->map[enemy->y - 1][enemy->x] = enemy->type ;
		game->maps->map[enemy->y][enemy->x] = '0' ;
		enemy->image->instances->y -= BITS ;
		enemy->y-- ;
	}
}
