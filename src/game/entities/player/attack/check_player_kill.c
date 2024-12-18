/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player_kill.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:00:40 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/18 06:06:22 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_doo_attack_east(t_game *game, t_player *player)
{
	if (player->attack->frame == FRAME1
		&& is_enemy(game->maps->map[player->attack->y - 1][player->attack->x]))
		del_enemy(game, &game->maps->enemies,
			player->attack->y - 1, player->attack->x);
	else if (player->attack->frame == FRAME2
		&& is_enemy(game->maps->map[player->attack->y][player->attack->x + 1]))
		del_enemy(game, &game->maps->enemies,
			player->attack->y, player->attack->x + 1);
	else if (player->attack->frame == FRAME3
		&& is_enemy(game->maps->map[player->attack->y + 1][player->attack->x]))
		del_enemy(game, &game->maps->enemies,
			player->attack->y + 1, player->attack->x);
}

static void	check_doo_attack_south(t_game *game, t_player *player)
{
	if (player->attack->frame == FRAME1
		&& is_enemy(game->maps->map[player->attack->y][player->attack->x + 1]))
		del_enemy(game, &game->maps->enemies,
			player->attack->y, player->attack->x + 1);
	else if (player->attack->frame == FRAME2
		&& (size_t) player->attack->y + 1 < game->maps->height
		&& is_enemy(game->maps->map[player->attack->y + 1][player->attack->x]))
		del_enemy(game, &game->maps->enemies,
			player->attack->y + 1, player->attack->x);
	else if (player->attack->frame == FRAME3
		&& is_enemy(game->maps->map[player->attack->y][player->attack->x - 1]))
		del_enemy(game, &game->maps->enemies,
			player->attack->y, player->attack->x - 1);
}

static void	check_doo_attack_west(t_game *game, t_player *player)
{
	if (player->attack->frame == FRAME1
		&& is_enemy(game->maps->map[player->attack->y + 1][player->attack->x]))
		del_enemy(game, &game->maps->enemies,
			player->attack->y + 1, player->attack->x);
	else if (player->attack->frame == FRAME2
		&& is_enemy(game->maps->map[player->attack->y][player->attack->x - 1]))
		del_enemy(game, &game->maps->enemies,
			player->attack->y, player->attack->x - 1);
	else if (player->attack->frame == FRAME3
		&& is_enemy(game->maps->map[player->attack->y - 1][player->attack->x]))
		del_enemy(game, &game->maps->enemies,
			player->attack->y - 1, player->attack->x);
}

static void	check_doo_attack_north(t_game *game, t_player *player)
{
	if (player->attack->frame == FRAME1
		&& is_enemy(game->maps->map[player->attack->y][player->attack->x - 1]))
		del_enemy(game, &game->maps->enemies,
			player->attack->y, player->attack->x - 1);
	else if (player->attack->frame == FRAME2
		&& is_enemy(game->maps->map[player->attack->y - 1][player->attack->x]))
		del_enemy(game, &game->maps->enemies,
			player->attack->y - 1, player->attack->x);
	else if (player->attack->frame == FRAME3
		&& is_enemy(game->maps->map[player->attack->y][player->attack->x + 1]))
		del_enemy(game, &game->maps->enemies,
			player->attack->y, player->attack->x + 1);
}

void	check_player_attack(t_game *game, t_player *player)
{
	if (player->attack->x <= 0 || player->attack->y <= 0
		|| (size_t) player->attack->x >= game->maps->width
		|| (size_t) player->attack->y >= game->maps->height)
		return ;
	if (player->attack->type == DEE)
	{
		if (is_enemy(game->maps->map[player->attack->y][player->attack->x]))
			del_enemy(game, &game->maps->enemies,
				player->attack->y, player->attack->x);
	}
	else
	{
		if (is_enemy(game->maps->map[player->attack->y][player->attack->x]))
			del_enemy(game, &game->maps->enemies,
				player->attack->y, player->attack->x);
		if (player->attack->orient == EAST)
			check_doo_attack_east(game, player);
		if (player->attack->orient == SOUTH)
			check_doo_attack_south(game, player);
		if (player->attack->orient == WEST)
			check_doo_attack_west(game, player);
		if (player->attack->orient == NORTH)
			check_doo_attack_north(game, player);
	}
}
