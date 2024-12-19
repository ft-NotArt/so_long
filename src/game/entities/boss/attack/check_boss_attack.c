/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_boss_attack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:28:50 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/19 05:32:06 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	in_range_east_boss(t_player *player, t_boss *boss)
{
	int	i ;

	i = 0 ;
	while (++i <= 9)
	{
		if ((boss->y == player->y && boss->x + i == player->x)
			|| (boss->y - 1 == player->y && boss->x + i == player->x))
			return (true);
		if ((i <= 3 || i == 7 || i == 8)
			&& ((boss->y - 2 == player->y && boss->x + i == player->x)
				|| (boss->y + 1 == player->y && boss->x + i == player->x)))
			return (true);
	}
	return (false);
}

static bool	in_range_west_boss(t_player *player, t_boss *boss)
{
	int	i ;

	i = 0 ;
	while (++i <= 9)
	{
		if ((boss->y == player->y && boss->x - i == player->x)
			|| (boss->y - 1 == player->y && boss->x - i == player->x))
			return (true);
		if ((i <= 3 || i == 7 || i == 8)
			&& ((boss->y - 2 == player->y && boss->x - i == player->x)
				|| (boss->y + 1 == player->y && boss->x - i == player->x)))
			return (true);
	}
	return (false);
}

bool	player_in_range_boss(t_player *player, t_boss *boss)
{
	if (boss->orient == EAST)
		return (in_range_east_boss(player, boss));
	else if (boss->orient == WEST)
		return (in_range_west_boss(player, boss));
	return (false);
}

void	check_boss_attack(t_game *game, t_boss *boss)
{
	if (boss->attack->orient == EAST)
	{
		if (in_range_east_boss(game->maps->player, boss))
		{
			game_over(game);
		}
	}
	else if (boss->attack->orient == WEST)
	{
		if (in_range_west_boss(game->maps->player, boss))
		{
			game_over(game);
		}
	}
}
