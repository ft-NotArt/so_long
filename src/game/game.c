/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 06:14:48 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/05 16:15:33 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_game(void *param)
{
	t_game	*game ;

	game = (t_game *) param ;
	mlx_close_window(game->mlx);
	mlx_terminate(game->mlx);
	free_maps(game->maps);
	free(game);
	exit(EXIT_SUCCESS);
}

void	keyboard_hook(mlx_key_data_t key_data, void *param)
{
	t_game	*game ;

	game = (t_game *) param ;

	if (key_data.action == MLX_PRESS) //  || key_data.action == MLX_REPEAT
	{
		if (key_data.key == MLX_KEY_W || key_data.key == MLX_KEY_UP
			|| key_data.key == MLX_KEY_A || key_data.key == MLX_KEY_LEFT
			|| key_data.key == MLX_KEY_S || key_data.key == MLX_KEY_DOWN
			|| key_data.key == MLX_KEY_D || key_data.key == MLX_KEY_RIGHT)
			get_input_dir(key_data.key, game);
		if (key_data.key == MLX_KEY_P)
			printf("POYO!\n");
		if (key_data.key == MLX_KEY_ESCAPE)
			close_game(game);
	}
}

t_game	*game_init(t_map *maps)
{
	t_game	*game ;

	game = malloc(sizeof(t_game));
	game->mlx = mlx_init(1100, 1500, "TEST", true);
	game->maps = maps ;
	
	return (game);
}

void	game_loop(t_map *maps)
{
	t_game	*game ;

	game = game_init(maps);

	
	display_full_map(game);

	// mlx_loop_hook(game->mlx, );

	mlx_key_hook(game->mlx, keyboard_hook, game);
	mlx_close_hook(game->mlx, close_game, game);
	mlx_loop(game->mlx);
}
