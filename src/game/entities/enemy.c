/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:00:20 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/10 16:59:24 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_enemy(t_game *game, t_enemy *enemy, int input_dir)
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
	int				fd ;
	unsigned char	c[1];

	if (enemy == NULL)
		return ;
	fd = open("/dev/random", O_RDONLY);
	if (fd == -1)
		c[0] = 1 ;
	else
		read(fd, c, 1);
	if ((c[0] % 6) == 0)
	{
		read(fd, c, 1);
		close(fd);
		move_enemy(game, enemy, (c[0] % 4));
	}
	else
		close(fd);
	enemy_turn(game, enemy->next);
}
