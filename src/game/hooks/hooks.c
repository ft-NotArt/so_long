/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:45:25 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/17 03:03:07 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	is_movement_key(keys_t key)
{
	return (key == MLX_KEY_W || key == MLX_KEY_UP
		|| key == MLX_KEY_A || key == MLX_KEY_LEFT
		|| key == MLX_KEY_S || key == MLX_KEY_DOWN
		|| key == MLX_KEY_D || key == MLX_KEY_RIGHT);
}

void	keyboard_hook(mlx_key_data_t key_data, void *param)
{
	t_game	*game ;

	game = (t_game *) param ;
	if (key_data.action == MLX_PRESS || key_data.action == MLX_REPEAT)
	{
		if (is_movement_key(key_data.key)
			&& game->maps->player->status != ATTACKING)
			get_input_dir(key_data.key, game); // TODO: shouldn't move when magic beam
		if ((key_data.key == MLX_KEY_1 || key_data.key == MLX_KEY_KP_1)
			&& game->maps->player->attack == NULL)
			player_swallow(game, game->maps, game->maps->map,
				game->maps->player);
		if ((key_data.key == MLX_KEY_2 || key_data.key == MLX_KEY_KP_2)
			&& game->player_attack_set[1] && game->maps->player->attack == NULL)
			player_knife(game, game->maps->player);
		if ((key_data.key == MLX_KEY_3 || key_data.key == MLX_KEY_KP_3)
			&& game->player_attack_set[2] && game->maps->player->attack == NULL)
			player_magic_beam(game, game->maps->player);
		if (key_data.key == MLX_KEY_P)
			mlx_put_string(game->mlx, "POYO!",
				game->maps->player->x * BITS, game->maps->player->y * BITS);
		if (key_data.key == MLX_KEY_ESCAPE)
			close_success(game);
	}
}

void	frame_hook(void *param)
{
	t_game	*game ;
	double	time ;

	game = (t_game *) param ;
	time = mlx_get_time();
	if (game->time_from_transition != 0
		&& game->time_from_transition + 2 < mlx_get_time())
		end_transition(game);
	if ((game->maps->player->status == SWALLOWING
			&& game->maps->player->last_action_time + 0.5 < time)
		|| ((game->maps->player->status == WALKING1
				|| game->maps->player->status == WALKING2)
			&& game->maps->player->last_action_time + 0.35 < time))
	{
		game->maps->player->status = STANDING ;
		update_player_sprite(game, game->maps->player);
	}
	if (fmod(time, 0.50) <= 0.02)
	{
		enemy_turn(game, game->maps->enemies);
		if (game->maps->player->attack != NULL)
			update_player_attack(game, game->maps->player);
	}
}
