/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 02:10:19 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/16 12:24:46 by anoteris         ###   ########.fr       */
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

void	game_over(t_game *game, t_enemy *enemy)
{
	ft_putstr_fd("Game Over !\n", STDOUT_FILENO);
	enemy_del(game, &game->maps->enemies, enemy->y, enemy->x);
	close_game(game);
}
