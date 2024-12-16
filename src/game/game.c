/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 06:14:48 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/16 20:55:29 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	level_transition(t_game *game)
{
	t_game	*next_game ;
	t_map	*next_map ;
	bool	tmp_player_attack_set[3];

	next_map = game->maps->next ;
	if (next_map == NULL)
		(ft_putstr_fd("GG !\n", STDOUT_FILENO), close_success(game));

	// mlx_set_window_size(game->mlx, 735, 452);
	// mlx_set_window_title(game->mlx, "⭐ WrapStar ⭐");

	// printf("\n\n\nTRANSITION\n\n\n");

	tmp_player_attack_set[0] = game->player_attack_set[0];
	tmp_player_attack_set[1] = game->player_attack_set[1];
	tmp_player_attack_set[2] = game->player_attack_set[2];

	mlx_close_window(game->mlx);
	mlx_terminate(game->mlx);
	free_game(game);


	next_game = game_init(next_map) ;
	if (!game->mlx)
	{
		free_game(next_game);
		error_mlx();
		exit(EXIT_FAILURE);
	}
	next_game->player_attack_set[0] = tmp_player_attack_set[0];
	next_game->player_attack_set[1] = tmp_player_attack_set[1];
	next_game->player_attack_set[2] = tmp_player_attack_set[2];


	game_loop(next_game);
}

void	game_loop(t_game *game)
{
	display_full_map(game);


	mlx_loop_hook(game->mlx, frame_hook, game);
	mlx_key_hook(game->mlx, keyboard_hook, game);
	mlx_close_hook(game->mlx, close_success, game);
	mlx_loop(game->mlx);
}
