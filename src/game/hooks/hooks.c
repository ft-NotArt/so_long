/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:45:25 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/10 02:40:41 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_game(void *param)
{
	t_game	*game ;

	game = (t_game *) param ;
	mlx_close_window(game->mlx);
	mlx_terminate(game->mlx);
	free_game(game);
	exit(EXIT_SUCCESS);
}

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
		if (key_data.key == MLX_KEY_P)
			printf("POYO!\n"); // TODO: Maybe get a space in the window to print it
		if (key_data.key == MLX_KEY_ESCAPE)
			close_game(game);
	}
}

void	frame_hook(void *param)
{
	t_game	*game ;

	game = (t_game *) param ;
	double time = mlx_get_time();
	if (game->maps->player->pose != STANDING
		&& game->maps->player->last_action_time + 0.35 < time)
	{
		game->maps->player->pose = STANDING ;
		update_player_sprite(game, game->maps->player);
	}
}
