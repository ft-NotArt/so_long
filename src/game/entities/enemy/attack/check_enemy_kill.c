/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_enemy_kill.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 05:50:50 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/18 07:04:53 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_doo_att_east_enemy(t_game *game, t_enemy *enemy)
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

static void	check_doo_att_south_enemy(t_game *game, t_enemy *enemy)
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

static void	check_doo_att_west_enemy(t_game *game, t_enemy *enemy)
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

static void	check_doo_att_north_enemy(t_game *game, t_enemy *enemy)
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

//TODO: same anti segfault as player version
void	check_enemy_attack(t_game *game, t_enemy *enemy)
{
	if (enemy->attack->x <= 0 || enemy->attack->y <= 0
		|| (size_t) enemy->attack->x >= game->maps->width - 1
		|| (size_t) enemy->attack->y >= game->maps->height - 1)
		return ;
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
			game_over(game);
		if (enemy->attack->orient == EAST)
			check_doo_att_east_enemy(game, enemy);
		if (enemy->attack->orient == SOUTH)
			check_doo_att_south_enemy(game, enemy);
		if (enemy->attack->orient == WEST)
			check_doo_att_west_enemy(game, enemy);
		if (enemy->attack->orient == NORTH)
			check_doo_att_north_enemy(game, enemy);
	}
}
