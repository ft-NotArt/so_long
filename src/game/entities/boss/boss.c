/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boss.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:45:06 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/19 07:06:49 by anoteris         ###   ########.fr       */
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

static void boss_toward_player(t_game *game, t_boss *boss)
{
	if (game->maps->player->x < boss->x)
		boss->orient = WEST ;
	else if (game->maps->player->x > boss->x)
		boss->orient = EAST ;
	if (game->maps->player->y < boss->y
		&& !is_wall(game->maps->map[boss->y - 1][boss->x]))
		move_boss(game, boss, NORTH);
	else if (game->maps->player->y > boss->y
		&& !is_wall(game->maps->map[boss->y + 1][boss->x]))
		move_boss(game, boss, SOUTH);
	else if (game->maps->player->x < boss->x)
		move_boss(game, boss, WEST);
	else if (game->maps->player->x > boss->x)
		move_boss(game, boss, EAST);
}

static void	update_boss_attack(t_game *game, t_boss *boss)
{
	update_attack_sprite(game, boss->attack);
	if (boss->start_of_kamehameha + 3 < mlx_get_time())
	{
		mlx_delete_image(game->mlx, boss->attack->image);
		free(boss->attack);
		boss->attack = NULL ;
		boss->status = STANDING ;
		update_boss_sprite(game, boss);
	}
	else
		check_boss_attack(game, boss);
}

void	boss_turn(t_game *game, t_boss *boss)
{
	if (boss == NULL)
		return ;
	if (boss->attack != NULL)
		update_boss_attack(game, boss);
	else if (boss->status == STANDING)
	{
		if (player_in_range_boss(game->maps->player, boss))
			boss->status = LOADING1 ;
		else
			boss_toward_player(game, boss);
		update_boss_sprite(game, boss);
	}
	else if (boss->status >= LOADING1 && boss->status <= LOADING5)
	{
		boss->status++ ;
		update_boss_sprite(game, boss);
	}
	if (boss->attack == NULL && boss->status == ATTACKING)
	{
		boss->attack = attack_init(BOSS, boss->x, boss->y, boss->orient);
		(display_attack(game, boss->attack), check_boss_attack(game, boss));
		boss->start_of_kamehameha = mlx_get_time();
	}
	boss_turn(game, boss->next);
}
