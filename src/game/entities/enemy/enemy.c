/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:00:20 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/18 06:57:31 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	after_enemy_move(t_game *game, t_enemy *enemy, t_orient input_dir)
{
	if (game->maps->player->attack != NULL
		&& enemy->x + 1 == game->maps->player->attack->x
		&& enemy->y == game->maps->player->attack->y)
		del_enemy(game, &game->maps->enemies, enemy->y, enemy->x);
	else if (enemy->orient != input_dir)
	{
		enemy->orient = input_dir ;
		update_enemy_sprite(game, enemy);
	}
}

void	move_enemy(t_game *game, t_enemy *enemy, t_orient input_dir)
{
	if (input_dir == EAST)
	{
		check_enemy_mov(game, enemy->y, enemy->x + 1);
		move_east(game, NULL, enemy);
	}
	else if (input_dir == SOUTH)
	{
		check_enemy_mov(game, enemy->y + 1, enemy->x);
		move_south(game, NULL, enemy);
	}
	else if (input_dir == WEST)
	{
		check_enemy_mov(game, enemy->y, enemy->x - 1);
		move_west(game, NULL, enemy);
	}
	else if (input_dir == NORTH)
	{
		check_enemy_mov(game, enemy->y - 1, enemy->x);
		move_north(game, NULL, enemy);
	}
	after_enemy_move(game, enemy, input_dir);
}

static void	update_enemy_attack(t_game *game, t_enemy *enemy)
{
	update_attack_sprite(game, enemy->attack);
	if (enemy->attack->frame == 4)
		(free(enemy->attack), enemy->attack = NULL);
	else
		check_enemy_attack(game, enemy);
}

void	enemy_turn(t_game *game, t_enemy *enemy)
{
	if (enemy == NULL)
		return ;
	if (enemy->attack != NULL)
		update_enemy_attack(game, enemy);
	else if (player_in_range(game->maps, enemy))
	{
		enemy->attack = attack_init(enemy->type,
				enemy->x, enemy->y, enemy->orient);
		display_attack(game, enemy->attack);
		check_enemy_attack(game, enemy);
	}
	else if ((rand_uchar() % 6) == 0)
		move_enemy(game, enemy, (rand_uchar() % 4));
	enemy_turn(game, enemy->next);
}
