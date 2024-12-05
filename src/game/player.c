/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:08:24 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/05 16:13:33 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	update_pose(int current_pose)
{
	if (current_pose == STANDING || current_pose == WALKING2)
		return (WALKING1);
	else
		return (WALKING2);
}

void	move_player(t_game *game, int input_dir, int player_y, int player_x)
{
	if (input_dir == EAST && (game->maps->map[player_y][player_x + 1]) != '1')
	{
		game->maps->map[player_y][player_x + 1] = 'P' ;
		game->maps->map[player_y][player_x] = '0' ;
		(display_tile(game, player_x, player_y), game->maps->player->x++);
	}
	if (input_dir == SOUTH && (game->maps->map[player_y + 1][player_x]) != '1')
	{
		game->maps->map[player_y + 1][player_x] = 'P' ;
		game->maps->map[player_y][player_x] = '0' ;
		(display_tile(game, player_x, player_y), game->maps->player->y++);
	}
	if (input_dir == WEST && (game->maps->map[player_y][player_x - 1]) != '1')
	{
		game->maps->map[player_y][player_x - 1] = 'P' ;
		game->maps->map[player_y][player_x] = '0' ;
		(display_tile(game, player_x, player_y), game->maps->player->x--);
	}
	if (input_dir == NORTH && (game->maps->map[player_y - 1][player_x]) != '1')
	{
		game->maps->map[player_y - 1][player_x] = 'P' ;
		game->maps->map[player_y][player_x] = '0' ;
		(display_tile(game, player_x, player_y), game->maps->player->y--);
	}
	game->maps->player->pose = update_pose(game->maps->player->pose);
}

void	align_and_move_player(t_game *game, int input_dir)
{
	if (game->maps->player->orient != input_dir)
		game->maps->player->orient = input_dir ;
	else
		move_player(game, input_dir, game->maps->player->y, game->maps->player->x);
	display_tile(game, game->maps->player->x, game->maps->player->y);
}

void	get_input_dir(keys_t key_press, t_game *game)
{
	if (key_press == MLX_KEY_D || key_press == MLX_KEY_RIGHT)
		align_and_move_player(game, EAST);
	else if (key_press == MLX_KEY_S || key_press == MLX_KEY_DOWN)
		align_and_move_player(game, SOUTH);
	else if (key_press == MLX_KEY_A || key_press == MLX_KEY_LEFT)
		align_and_move_player(game, WEST);
	else if (key_press == MLX_KEY_W || key_press == MLX_KEY_UP)
		align_and_move_player(game, NORTH);
}
