/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:55:57 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/05 17:06:06 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_tile(t_game *game, int x, int y)
{
	IMG_WIN(game->mlx, get_mlx_img(game, WATER), 32 * x, 32 * y);
	if (game->maps->map[y][x] != '1')
		IMG_WIN(game->mlx, get_mlx_ground(game, x, y), 32 * x, 32 * y);
	if (game->maps->map[y][x] == 'P')
		IMG_WIN(game->mlx, get_mlx_player(game), 32 * x, 32 * y);
	else if (game->maps->map[y][x] == 'E')
		IMG_WIN(game->mlx, get_mlx_img(game, STAR), 32 * x, 32 * y);
}

void	display_full_map(t_game *game)
{
	int x ;
	int y ;

	y = -1 ;
	while (game->maps->map[++y])
	{
		x = -1 ;
		while (game->maps->map[y][++x])
		{
			display_tile(game, x, y);
		}
	}
}
