/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_attack_kill.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 05:50:50 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/18 17:00:14 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_doo_att_east_enemy(t_game *game, t_attack *attack)
{
	if (attack->frame == FRAME1
		&& game->maps->player->x == attack->x
		&& game->maps->player->y == attack->y - 1)
		game_over(game);
	else if (attack->frame == FRAME2
		&& game->maps->player->x == attack->x + 1
		&& game->maps->player->y == attack->y)
		game_over(game);
	else if (attack->frame == FRAME3
		&& game->maps->player->x == attack->x
		&& game->maps->player->y == attack->y + 1)
		game_over(game);
}

static void	check_doo_att_south_enemy(t_game *game, t_attack *attack)
{
	if (attack->frame == FRAME1
		&& game->maps->player->x == attack->x + 1
		&& game->maps->player->y == attack->y)
		game_over(game);
	else if (attack->frame == FRAME2
		&& game->maps->player->x == attack->x
		&& game->maps->player->y == attack->y + 1)
		game_over(game);
	else if (attack->frame == FRAME3
		&& game->maps->player->x == attack->x - 1
		&& game->maps->player->y == attack->y)
		game_over(game);
}

static void	check_doo_att_west_enemy(t_game *game, t_attack *attack)
{
	if (attack->frame == FRAME1
		&& game->maps->player->x == attack->x
		&& game->maps->player->y == attack->y + 1)
		game_over(game);
	else if (attack->frame == FRAME2
		&& game->maps->player->x == attack->x - 1
		&& game->maps->player->y == attack->y)
		game_over(game);
	else if (attack->frame == FRAME3
		&& game->maps->player->x == attack->x
		&& game->maps->player->y == attack->y - 1)
		game_over(game);
}

static void	check_doo_att_north_enemy(t_game *game, t_attack *attack)
{
	if (attack->frame == FRAME1
		&& game->maps->player->x == attack->x - 1
		&& game->maps->player->y == attack->y)
		game_over(game);
	else if (attack->frame == FRAME2
		&& game->maps->player->x == attack->x
		&& game->maps->player->y == attack->y - 1)
		game_over(game);
	else if (attack->frame == FRAME3
		&& game->maps->player->x == attack->x + 1
		&& game->maps->player->y == attack->y)
		game_over(game);
}

void	check_enemy_attack(t_game *game, t_attack *attack)
{
	if (attack->x <= 0 || attack->y <= 0
		|| (size_t) attack->x >= game->maps->width - 1
		|| (size_t) attack->y >= game->maps->height - 1)
		return ;
	if (attack->type == DEE)
	{
		if (attack->x == game->maps->player->x
			&& attack->y == game->maps->player->y)
			game_over(game);
	}
	else
	{
		if (attack->x == game->maps->player->x
			&& attack->y == game->maps->player->y)
			game_over(game);
		if (attack->orient == EAST)
			check_doo_att_east_enemy(game, attack);
		if (attack->orient == SOUTH)
			check_doo_att_south_enemy(game, attack);
		if (attack->orient == WEST)
			check_doo_att_west_enemy(game, attack);
		if (attack->orient == NORTH)
			check_doo_att_north_enemy(game, attack);
	}
}
