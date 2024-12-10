/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:00:55 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/10 00:44:58 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_east(t_game *game, int player_y, int player_x)
{
	if (game->maps->map[player_y][player_x + 1] != '1'
		&& game->maps->map[player_y][player_x + 1] != 'E')
	{
		game->maps->map[player_y][player_x + 1] = 'P' ;
		game->maps->map[player_y][player_x] = '0' ;
		game->maps->player->image->instances->x += BITS ;
		game->maps->player->x++ ;
	}
}

void	move_south(t_game *game, int player_y, int player_x)
{
	if (game->maps->map[player_y + 1][player_x] != '1'
		&& game->maps->map[player_y + 1][player_x] != 'E')
	{
		game->maps->map[player_y + 1][player_x] = 'P' ;
		game->maps->map[player_y][player_x] = '0' ;
		game->maps->player->image->instances->y += BITS ;
		game->maps->player->y++ ;
	}
}

void	move_west(t_game *game, int player_y, int player_x)
{
	if (game->maps->map[player_y][player_x - 1] != '1'
		&& game->maps->map[player_y][player_x - 1] != 'E')
	{
		game->maps->map[player_y][player_x - 1] = 'P' ;
		game->maps->map[player_y][player_x] = '0' ;
		game->maps->player->image->instances->x -= BITS ;
		game->maps->player->x-- ;
	}
}

void	move_north(t_game *game, int player_y, int player_x)
{
	if (game->maps->map[player_y - 1][player_x] != '1'
		&& game->maps->map[player_y - 1][player_x] != 'E')
	{
		game->maps->map[player_y - 1][player_x] = 'P' ;
		game->maps->map[player_y][player_x] = '0' ;
		game->maps->player->image->instances->y -= BITS ;
		game->maps->player->y-- ;
	}
}
