/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:00:55 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/18 15:54:50 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_east(t_game *game, t_player *player, t_enemy *enemy)
{
	if (player != NULL && !is_wall(game->maps->map[player->y][player->x + 1]))
	{
		game->maps->map[player->y][player->x + 1] = 'P' ;
		game->maps->map[player->y][player->x] = '0' ;
		player->image->instances->x += BITS ;
		player->x++ ;
		update_step_count(game);
	}
	else if (enemy != NULL && !is_wall(game->maps->map[enemy->y][enemy->x + 1])
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
	if (player != NULL && !is_wall(game->maps->map[player->y + 1][player->x]))
	{
		game->maps->map[player->y + 1][player->x] = 'P' ;
		game->maps->map[player->y][player->x] = '0' ;
		player->image->instances->y += BITS ;
		player->y++ ;
		update_step_count(game);
	}
	else if (enemy != NULL && !is_wall(game->maps->map[enemy->y + 1][enemy->x])
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
	if (player != NULL && !is_wall(game->maps->map[player->y][player->x - 1]))
	{
		game->maps->map[player->y][player->x - 1] = 'P' ;
		game->maps->map[player->y][player->x] = '0' ;
		player->image->instances->x -= BITS ;
		player->x-- ;
		update_step_count(game);
	}
	else if (enemy != NULL && !is_wall(game->maps->map[enemy->y][enemy->x - 1])
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
	if (player != NULL && !is_wall(game->maps->map[player->y - 1][player->x]))
	{
		game->maps->map[player->y - 1][player->x] = 'P' ;
		game->maps->map[player->y][player->x] = '0' ;
		player->image->instances->y -= BITS ;
		player->y-- ;
		update_step_count(game);
	}
	else if (enemy != NULL && !is_wall(game->maps->map[enemy->y - 1][enemy->x])
		&& !is_enemy(game->maps->map[enemy->y - 1][enemy->x]))
	{
		game->maps->map[enemy->y - 1][enemy->x] = enemy->type ;
		game->maps->map[enemy->y][enemy->x] = '0' ;
		enemy->image->instances->y -= BITS ;
		enemy->y-- ;
	}
}
