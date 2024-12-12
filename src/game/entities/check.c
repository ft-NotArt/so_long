/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 05:33:43 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/12 08:19:57 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_player_tile(t_game *game, int y, int x)
{
	if (game->maps->map[y][x] == 'E' && game->maps->enemy_number == 0)
	{
		ft_printf("GG !\n");
		close_game(game);
	}
	else if (is_enemy(game->maps->map[y][x]))
	{
		ft_printf("Game Over !\n");
		close_game(game);
	}
}

void	check_enemy_tile(t_game *game, int y, int x)
{
	if (game->maps->map[y][x] == 'P')
	{
		ft_printf("Game Over !\n");
		close_game(game);
	}
}

bool	is_enemy(char c)
{
	return (c == 'C' || c == 'D' || c == 'B');
}
