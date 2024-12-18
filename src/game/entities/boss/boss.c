/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boss.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:45:06 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/18 16:24:54 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	after_boss_move(t_game *game, t_boss *boss, t_orient input_dir)
{
	if (game->maps->player->attack != NULL
		&& boss->x + 1 == game->maps->player->attack->x
		&& boss->y == game->maps->player->attack->y)
		del_boss(game, &game->maps->bosses, boss->y, boss->x);
	else if (boss->orient != input_dir &&
		(input_dir == EAST || input_dir == WEST))
	{
		boss->orient = input_dir ;
		update_boss_sprite(game, boss);
	}
}

static void	move_boss(t_game *game, t_boss *boss, t_orient input_dir)
{
	if (input_dir == EAST)
	{
		check_enemy_mov(game, boss->y, boss->x + 1);
		move_east(game, NULL, NULL, boss);
	}
	else if (input_dir == SOUTH)
	{
		check_enemy_mov(game, boss->y + 1, boss->x);
		move_south(game, NULL, NULL, boss);
	}
	else if (input_dir == WEST)
	{
		check_enemy_mov(game, boss->y, boss->x - 1);
		move_west(game, NULL, NULL, boss);
	}
	else if (input_dir == NORTH)
	{
		check_enemy_mov(game, boss->y - 1, boss->x);
		move_north(game, NULL, NULL, boss);
	}
	after_boss_move(game, boss, input_dir);
}

void	boss_turn(t_game *game, t_boss *boss)
{
	if (boss == NULL)
		return ;
	// if (boss->attack != NULL)
	// 	update_boss_attack(game, boss);
	// else if (player_in_range(game->maps, boss))
	// {
	// 	boss->attack = attack_init(boss->type,
	// 			boss->x, boss->y, boss->orient);
	// 	display_attack(game, boss->attack);
	// 	check_boss_attack(game, boss);
	// }
	// else if ((rand_uchar() % 6) == 0)
	// 	move_boss(game, boss, (rand_uchar() % 4));
	if ((rand_uchar() % 6) == 0)
		move_boss(game, boss, (rand_uchar() % 4));
	boss_turn(game, boss->next);
}