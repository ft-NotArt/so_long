/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:00:20 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/16 09:25:39 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_enemy(t_game *game, t_enemy *enemy, orient input_dir)
{
	if (input_dir == EAST)
	{
		check_enemy_tile(game, enemy->y, enemy->x + 1);
		move_east(game, ENEMY);
	}
	if (input_dir == SOUTH)
	{
		check_enemy_tile(game, enemy->y + 1, enemy->x);
		move_south(game, ENEMY);
	}
	if (input_dir == WEST)
	{
		check_enemy_tile(game, enemy->y, enemy->x - 1);
		move_west(game, ENEMY);
	}
	if (input_dir == NORTH)
	{
		check_enemy_tile(game, enemy->y - 1, enemy->x);
		move_north(game, ENEMY);
	}
	if (enemy->orient != input_dir)
	{
		enemy->orient = input_dir ;
		update_enemy_sprite(game, enemy);
	}
}

void	enemy_turn(t_game *game, t_enemy *enemy)
{
	if (enemy == NULL)
		return ;
	if (enemy->attack != NULL)
	{
		update_attack_sprite(game, enemy->attack);
		if (enemy->attack->frame == 4)
			(free(enemy->attack), enemy->attack = NULL);
		else
			check_attack(game, enemy);
			// printf("Enemy attacking, frame %d \n", enemy->attack->frame);
	}
	else if (player_in_range(game->maps, enemy))
	{
		enemy_attack(game, enemy);
		check_attack(game, enemy);
		printf("ATTACK !!\n");
	}
	else if ((rand_uchar() % 6) == 0)
		move_enemy(game, enemy, (rand_uchar() % 4));
	enemy_turn(game, enemy->next);
}
