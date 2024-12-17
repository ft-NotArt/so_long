/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_range.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 01:33:39 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/17 02:05:53 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	in_range_east(t_player *player, t_enemy *enemy)
{
	if (enemy->type == DEE)
	{
		if (enemy->y == player->y
			&& (enemy->x + 1 == player->x
				|| enemy->x + 2 == player->x
				|| enemy->x + 3 == player->x))
			return (true);
	}
	if (enemy->type == DOO)
	{
		if ((enemy->y == player->y
				&& (enemy->x + 1 == player->x
					|| enemy->x + 2 == player->x))
			|| (enemy->x + 1 == player->x
				&& (enemy->y - 1 == player->y
					|| enemy->y + 1 == player->y)))
			return (true);
	}
	return (false);
}

static bool	in_range_south(t_player *player, t_enemy *enemy)
{
	if (enemy->type == DEE)
	{
		if (enemy->x == player->x
			&& (enemy->y + 1 == player->y
				|| enemy->y + 2 == player->y
				|| enemy->y + 3 == player->y))
			return (true);
	}
	if (enemy->type == DOO)
	{
		if ((enemy->x == player->x
				&& (enemy->y + 1 == player->y
					|| enemy->y + 2 == player->y))
			|| (enemy->y + 1 == player->y
				&& (enemy->x - 1 == player->x
					|| enemy->x + 1 == player->x)))
			return (true);
	}
	return (false);
}

static bool	in_range_west(t_player *player, t_enemy *enemy)
{
	if (enemy->type == DEE)
	{
		if (enemy->y == player->y
			&& (enemy->x - 1 == player->x
				|| enemy->x - 2 == player->x
				|| enemy->x - 3 == player->x))
			return (true);
	}
	if (enemy->type == DOO)
	{
		if ((enemy->y == player->y
				&& (enemy->x - 1 == player->x
					|| enemy->x - 2 == player->x))
			|| (enemy->x - 1 == player->x
				&& (enemy->y - 1 == player->y
					|| enemy->y + 1 == player->y)))
			return (true);
	}
	return (false);
}

static bool	in_range_north(t_player *player, t_enemy *enemy)
{
	if (enemy->type == DEE)
	{
		if (enemy->x == player->x
			&& (enemy->y - 1 == player->y
				|| enemy->y - 2 == player->y
				|| enemy->y - 3 == player->y))
			return (true);
	}
	if (enemy->type == DOO)
	{
		if ((enemy->x == player->x
				&& (enemy->y - 1 == player->y
					|| enemy->y - 2 == player->y))
			|| (enemy->y - 1 == player->y
				&& (enemy->x - 1 == player->x
					|| enemy->x + 1 == player->x)))
			return (true);
	}
	return (false);
}

bool	player_in_range(t_map *map, t_enemy *enemy)
{
	if (enemy->orient == EAST)
		return (in_range_east(map->player, enemy));
	else if (enemy->orient == SOUTH)
		return (in_range_south(map->player, enemy));
	else if (enemy->orient == WEST)
		return (in_range_west(map->player, enemy));
	else if (enemy->orient == NORTH)
		return (in_range_north(map->player, enemy));
	return (false);
}
