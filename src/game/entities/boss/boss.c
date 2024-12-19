/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boss.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:45:06 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/19 04:17:59 by anoteris         ###   ########.fr       */
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

static void	update_boss_attack(t_game *game, t_boss *boss)
{
	update_attack_sprite(game, boss->attack);
	if (boss->attack->frame == 4)
		(free(boss->attack), boss->attack = NULL, boss->status = STANDING);
	else
		check_boss_attack(game, boss);
}

void	boss_turn(t_game *game, t_boss *boss)
{
	if (boss == NULL)
		return ;

	if (boss->status == STANDING)
	{
		if (player_in_range_boss(game->maps->player, boss))
		{
			boss->status = LOADING1 ;
			update_boss_sprite(game, boss);
		}
		else if ((rand_uchar() % 6) == 0)
			move_boss(game, boss, (rand_uchar() % 4));
	}
	else if (boss->status == LOADING1 || boss->status == LOADING2
			|| boss->status == LOADING3 || boss->status == LOADING4)
	{
		boss->status++ ;
		update_boss_sprite(game, boss);
	}
	else if (boss->status == LOADING5)
	{
		boss->status = ATTACKING ;
		boss->attack = attack_init(BOSS, boss->x, boss->y, boss->orient);
		display_attack(game, boss->attack);
		// printf("\n Boss - x=%d y=%d \n \t - attack - x=%d y=%d \n", boss->x, boss->y, boss->attack->x, boss->attack->y);
		check_boss_attack(game, boss);
	}
	else if (boss->status == ATTACKING)
	{
		update_boss_attack(game, boss);
	}

	// printf("in range : %d\n", player_in_range_boss(game->maps->player, boss));
	// if (boss->attack != NULL)
	// 	update_boss_attack(game, boss);
	// else if (player_in_range_boss(game->maps->player, boss))
	// {
	// 	boss->attack = attack_init(BOSS, boss->x, boss->y, boss->orient);
	// 	display_attack(game, boss->attack);
	// 	printf("\n Boss - x=%d y=%d \n \t - attack - x=%d y=%d \n", boss->x, boss->y, boss->attack->x, boss->attack->y);
	// 	check_boss_attack(game, boss);
	// }
	
	boss_turn(game, boss->next);
}