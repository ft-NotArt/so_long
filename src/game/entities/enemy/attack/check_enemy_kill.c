/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_enemy_kill.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 05:50:50 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/16 18:14:33 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_doo_attack_east(t_game *game, t_enemy *enemy)
{
	if (enemy->attack->frame == FRAME1
		&& game->maps->player->x == enemy->attack->x
		&& game->maps->player->y == enemy->attack->y - 1)
		game_over(game);
	else if (enemy->attack->frame == FRAME2
		&& game->maps->player->x == enemy->attack->x + 1
		&& game->maps->player->y == enemy->attack->y)
		game_over(game);
	else if (enemy->attack->frame == FRAME3
		&& game->maps->player->x == enemy->attack->x
		&& game->maps->player->y == enemy->attack->y + 1)
			game_over(game);
}

static void	check_doo_attack_south(t_game *game, t_enemy *enemy)
{
	if (enemy->attack->frame == FRAME1
		&& game->maps->player->x == enemy->attack->x + 1
		&& game->maps->player->y == enemy->attack->y)
		game_over(game);
	else if (enemy->attack->frame == FRAME2
		&& game->maps->player->x == enemy->attack->x
		&& game->maps->player->y == enemy->attack->y + 1)
		game_over(game);
	else if (enemy->attack->frame == FRAME3
		&& game->maps->player->x == enemy->attack->x - 1
		&& game->maps->player->y == enemy->attack->y)
			game_over(game);
}

static void	check_doo_attack_west(t_game *game, t_enemy *enemy)
{
	if (enemy->attack->frame == FRAME1
		&& game->maps->player->x == enemy->attack->x
		&& game->maps->player->y == enemy->attack->y + 1)
		game_over(game);
	else if (enemy->attack->frame == FRAME2
		&& game->maps->player->x == enemy->attack->x - 1
		&& game->maps->player->y == enemy->attack->y)
		game_over(game);
	else if (enemy->attack->frame == FRAME3
		&& game->maps->player->x == enemy->attack->x
		&& game->maps->player->y == enemy->attack->y - 1)
			game_over(game);
}

static void	check_doo_attack_north(t_game *game, t_enemy *enemy)
{
	if (enemy->attack->frame == FRAME1
		&& game->maps->player->x == enemy->attack->x - 1
		&& game->maps->player->y == enemy->attack->y)
		game_over(game);
	else if (enemy->attack->frame == FRAME2
		&& game->maps->player->x == enemy->attack->x
		&& game->maps->player->y == enemy->attack->y - 1)
		game_over(game);
	else if (enemy->attack->frame == FRAME3
		&& game->maps->player->x == enemy->attack->x + 1
		&& game->maps->player->y == enemy->attack->y)
			game_over(game);
}

void	check_enemy_attack(t_game *game, t_enemy *enemy)
{
	if (enemy->attack->type == DEE)
	{
		if (enemy->attack->x == game->maps->player->x
			&& enemy->attack->y == game->maps->player->y)
			game_over(game);
	}
	else
	{
		if (enemy->attack->x == game->maps->player->x
			&& enemy->attack->y == game->maps->player->y)
		{
			game_over(game);
		}
		if (enemy->attack->orient == EAST)
			check_doo_attack_east(game, enemy);
		if (enemy->attack->orient == SOUTH)
			check_doo_attack_south(game, enemy);
		if (enemy->attack->orient == WEST)
			check_doo_attack_west(game, enemy);
		if (enemy->attack->orient == NORTH)
			check_doo_attack_north(game, enemy);
	}
}
