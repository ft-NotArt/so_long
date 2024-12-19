/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_panel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 23:35:22 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/19 07:49:03 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_panel(t_game *game)
{
	mlx_image_t	*panel ;
	size_t		x ;
	size_t		y ;

	y = 0 ;
	while (y < 2)
	{
		x = 0 ;
		while (x < game->maps->width)
		{
			display_water(game, x, (game->maps->height + y));
			panel = get_mlx_panel(game, x, y);
			mlx_image_to_window(game->mlx, panel,
				x * BITS, (game->maps->height + y) * BITS);
			mlx_set_instance_depth(panel->instances, 1200);
			x++ ;
		}
		y++ ;
	}
	display_inside_panel(game);
}

void	display_inside_panel(t_game *game)
{
	display_boxes(game);
	display_powers(game);
	display_sign(game);
	init_step_count(game);
}
