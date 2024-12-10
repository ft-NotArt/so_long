/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:00:55 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/10 14:43:38 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	move_east(t_game *game, int player_y, int player_x)
// {
// 	if (game->maps->map[player_y][player_x + 1] != '1'
// 		&& game->maps->map[player_y][player_x + 1] != 'E')
// 	{
// 		game->maps->map[player_y][player_x + 1] = 'P' ;
// 		game->maps->map[player_y][player_x] = '0' ;
// 		game->maps->player->image->instances->x += BITS ;
// 		game->maps->player->x++ ;
// 	}
// }

void	move_east(t_game *game, t_player *player, t_enemy *enemy)
{
	if (player != NULL)
	{
		if (game->maps->map[player->y][player->x + 1] != '1'
			&& game->maps->map[player->y][player->x + 1] != 'E')
		{
			game->maps->map[player->y][player->x + 1] = 'P' ;
			game->maps->map[player->y][player->x] = '0' ;
			player->image->instances->x += BITS ;
			player->x++ ;
		}
	}
	else if (enemy != NULL)
	{
		if (game->maps->map[enemy->y][enemy->x + 1] != '1'
			&& game->maps->map[enemy->y][enemy->x + 1] != 'E'
			&& !is_enemy(game->maps->map[enemy->y][enemy->x + 1]))
		{
			game->maps->map[enemy->y][enemy->x + 1] = enemy->type ;
			game->maps->map[enemy->y][enemy->x] = '0' ;
			enemy->image->instances->x += BITS ;
			enemy->x++ ;
		}
	}
}

void	move_south(t_game *game, t_player *player, t_enemy *enemy)
{
	if (player != NULL)
	{
		if (game->maps->map[player->y + 1][player->x] != '1'
			&& game->maps->map[player->y + 1][player->x] != 'E')
		{
			game->maps->map[player->y + 1][player->x] = 'P' ;
			game->maps->map[player->y][player->x] = '0' ;
			player->image->instances->y += BITS ;
			player->y++ ;
		}
	}
	else if (enemy != NULL)
	{
		if (game->maps->map[enemy->y + 1][enemy->x] != '1'
			&& game->maps->map[enemy->y + 1][enemy->x] != 'E'
			&& !is_enemy(game->maps->map[enemy->y + 1][enemy->x]))
		{
			game->maps->map[enemy->y + 1][enemy->x] = enemy->type ;
			game->maps->map[enemy->y][enemy->x] = '0' ;
			enemy->image->instances->y += BITS ;
			enemy->y++ ;
		}
	}
}

void	move_west(t_game *game, t_player *player, t_enemy *enemy)
{
	if (player != NULL)
	{
		if (game->maps->map[player->y][player->x - 1] != '1'
			&& game->maps->map[player->y][player->x - 1] != 'E')
		{
			game->maps->map[player->y][player->x - 1] = 'P' ;
			game->maps->map[player->y][player->x] = '0' ;
			player->image->instances->x -= BITS ;
			player->x-- ;
		}
	}
	else if (enemy != NULL)
	{
		if (game->maps->map[enemy->y][enemy->x - 1] != '1'
			&& game->maps->map[enemy->y][enemy->x - 1] != 'E'
			&& !is_enemy(game->maps->map[enemy->y][enemy->x - 1]))
		{
			game->maps->map[enemy->y][enemy->x - 1] = enemy->type ;
			game->maps->map[enemy->y][enemy->x] = '0' ;
			enemy->image->instances->x -= BITS ;
			enemy->x-- ;
		}
	}
}

void	move_north(t_game *game, t_player *player, t_enemy *enemy)
{
	if (player != NULL)
	{
		if (game->maps->map[player->y - 1][player->x] != '1'
			&& game->maps->map[player->y - 1][player->x] != 'E')
		{
			game->maps->map[player->y - 1][player->x] = 'P' ;
			game->maps->map[player->y][player->x] = '0' ;
			player->image->instances->y -= BITS ;
			player->y-- ;
		}
	}
	else if (enemy != NULL)
	{
		if (game->maps->map[enemy->y - 1][enemy->x] != '1'
			&& game->maps->map[enemy->y - 1][enemy->x] != 'E'
			&& !is_enemy(game->maps->map[enemy->y - 1][enemy->x]))
		{
			game->maps->map[enemy->y - 1][enemy->x] = enemy->type ;
			game->maps->map[enemy->y][enemy->x] = '0' ;
			enemy->image->instances->y -= BITS ;
			enemy->y-- ;
		}
	}
}
