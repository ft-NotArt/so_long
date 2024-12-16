/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:45:25 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/16 18:19:11 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	keyboard_hook(mlx_key_data_t key_data, void *param)
{
	t_game	*game ;

	game = (t_game *) param ;
	if (key_data.action == MLX_PRESS || key_data.action == MLX_REPEAT)
	{
		if (key_data.key == MLX_KEY_W || key_data.key == MLX_KEY_UP
			|| key_data.key == MLX_KEY_A || key_data.key == MLX_KEY_LEFT
			|| key_data.key == MLX_KEY_S || key_data.key == MLX_KEY_DOWN
			|| key_data.key == MLX_KEY_D || key_data.key == MLX_KEY_RIGHT)
			get_input_dir(key_data.key, game);
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
			ft_printf("POYO!\n"); // TODO: Maybe get a space in the window to print it
		if (key_data.key == MLX_KEY_ESCAPE)
			close_success(game);

		// TODO: RM this dev mode
		if (key_data.key == MLX_KEY_F)
		{
			game->player_attack_set[1] = 1 ;
			game->player_attack_set_img[1]->enabled = true ;
			game->player_attack_set[2] = 1 ;
			game->player_attack_set_img[2]->enabled = true ;
		}
		if (key_data.key == MLX_KEY_C)
			game->maps->enemy_number = 0 ;
		if (key_data.key == MLX_KEY_4)
			move_west(game, NULL, game->maps->enemies) ;
		if (key_data.key == MLX_KEY_C)
			enemy_del(game, &game->maps->enemies, game->maps->enemies->y, game->maps->enemies->x);
		if (key_data.key == MLX_KEY_V)
			enemy_del(game, &game->maps->enemies->next, game->maps->enemies->next->y, game->maps->enemies->next->x);
	}
}

void	frame_hook(void *param)
{
	t_game	*game ;

	game = (t_game *) param ;
	double time = mlx_get_time();
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
