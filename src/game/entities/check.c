/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 05:33:43 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/10 06:07:15 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_tile(t_game *game, int y, int x)
{
	if (game->maps->map[y][x] == 'E' && game->maps->enemy_number == 0)
	{
		printf("GG !\n");
		close_game(game);
	}
	else if (game->maps->map[y][x] == 'C' || game->maps->map[y][x] == 'D')
	{
		printf("Game Over !\n");
		close_game(game);
	}
}
