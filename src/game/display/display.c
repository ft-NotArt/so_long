/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:55:57 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/16 18:18:56 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*get_mlx_img(t_game *game, char *sprite_file)
{
	mlx_texture_t	*texture ;
	mlx_image_t		*img ;

	texture = mlx_load_png(sprite_file);
	if (!texture)
	{
		error_mlx();
		close_failure(game);
	}
	img = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	return (img);
}

void	display_tile(t_game *game, int x, int y)
{
	display_water(game, x, y);
	if (game->maps->map[y][x] != '1')
		display_ground(game, x, y);
	if (game->maps->map[y][x] == 'P')
		display_player(game, x, y);
	else if (is_enemy(game->maps->map[y][x]) && game->maps->map[y][x] != 'B')
		display_enemy(game, x, y);
	else if (game->maps->map[y][x] == 'E')
		display_star(game, x, y);
}

void	display_full_map(t_game *game)
{
	int	x ;
	int	y ;

	y = -1 ;
	while (game->maps->map[++y])
	{
		x = -1 ;
		while (game->maps->map[y][++x])
		{
			display_tile(game, x, y);
		}
	}
	display_panel(game);
}
