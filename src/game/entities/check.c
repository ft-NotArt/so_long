/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 05:33:43 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/16 23:53:01 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_player_mov(t_game *game, int y, int x)
{
	t_enemy	*current ;

	if (game->maps->map[y][x] == 'E' && game->maps->enemy_number == 0)
		start_transition(game);
	if (is_enemy(game->maps->map[y][x]))
		game_over(game);
	current = game->maps->enemies ;
	while (current)
	{
		if (current->attack != NULL)
		{
			if (current->attack->x == x && current->attack->y == y)
			{
				game_over(game);
			}
		}
		current = current->next ;
	}
}

void	check_enemy_mov(t_game *game, int y, int x)
{
	if (game->maps->map[y][x] == 'P')
	{
		game_over(game);
	}
}

bool	is_enemy(char c)
{
	return (c == 'C' || c == 'D' || c == 'B');
}
