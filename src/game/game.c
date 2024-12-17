/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 06:14:48 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/17 02:08:27 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_transition(t_game *game)
{
	if (game->maps->next == NULL)
		(ft_putstr_fd("GG !\n", STDOUT_FILENO), close_success(game));
	display_transition(game);
	game->time_from_transition = mlx_get_time();
}

void	end_transition(t_game *game)
{
	t_game	*next_game ;
	t_map	*next_map ;
	bool	tmp_player_attack_set[3];

	next_map = game->maps->next ;
	ft_memcpy(tmp_player_attack_set,
		game->player_attack_set, 3 * sizeof(bool));
	mlx_close_window(game->mlx);
	mlx_terminate(game->mlx);
	free_map(game->maps);
	free(game);
	next_game = game_init(next_map);
	if (!next_game->mlx)
	{
		free_game(next_game);
		error_mlx();
		exit(EXIT_FAILURE);
	}
	ft_memcpy(next_game->player_attack_set,
		tmp_player_attack_set, 3 * sizeof(bool));
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
