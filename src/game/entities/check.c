/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 05:33:43 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/16 18:19:04 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_player_tile(t_game *game, int y, int x)
{
	t_enemy	*current ;

	if (game->maps->map[y][x] == 'E' && game->maps->enemy_number == 0)
		(ft_putstr_fd("GG !\n", STDOUT_FILENO), close_success(game));
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

void	check_enemy_tile(t_game *game, int y, int x)
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
