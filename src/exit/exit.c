/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 02:10:19 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/16 19:57:58 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_game(t_game *game)
{
	free_enemies(&game->maps->enemies);
	mlx_close_window(game->mlx);
	mlx_terminate(game->mlx);
	free_game(game);
}

void	close_success(void *param)
{
	t_game	*game ;

	game = (t_game *) param ;
	close_game(game);
	exit(EXIT_SUCCESS);
}

void	close_failure(void *param)
{
	t_game	*game ;

	game = (t_game *) param ;
	close_game(game);
	exit(EXIT_FAILURE);
}

void	game_over(t_game *game)
{
	ft_putstr_fd("Game Over !\n", STDOUT_FILENO);
	close_success(game);
}
