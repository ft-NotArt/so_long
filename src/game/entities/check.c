/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 05:33:43 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/10 16:48:19 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_player_tile(t_game *game, int y, int x)
{
	if (game->maps->map[y][x] == 'E' && game->maps->enemy_number == 0)
	{
		printf("GG !\n");
		close_game(game);
	}
	else if (is_enemy(game->maps->map[y][x]))
	{
		printf("Game Over !\n");
		close_game(game);
	}
}

void	check_enemy_tile(t_game *game, int y, int x)
{
	if (game->maps->map[y][x] == 'P')
	{
		printf("Game Over !\n");
		close_game(game);
	}
}

bool	is_enemy(char c)
{
	return (c == 'C' || c == 'D' || c == 'B');
}
