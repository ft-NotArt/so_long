/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 06:14:48 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/12 04:20:34 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_loop(t_map *maps)
{
	t_game	*game ;

	game = game_init(maps);
	if (!game->mlx)
	{
		free(game);
		return ; //TODO: appropriate error function
	}

	
	display_full_map(game);


	mlx_loop_hook(game->mlx, frame_hook, game);
	mlx_key_hook(game->mlx, keyboard_hook, game);
	mlx_close_hook(game->mlx, close_game, game);
	mlx_loop(game->mlx);
}
