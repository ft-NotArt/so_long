/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_transition.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:41:19 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/17 02:46:00 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	display_transition_image(t_game *game)
{
	mlx_image_t	*transition ;
	char		sprite_file[100];

	ft_strlcpy(sprite_file, TRANSITION, ft_strlen(TRANSITION) + 1);
	ft_strlcat(sprite_file, PNG, ft_strlen(sprite_file) + ft_strlen(PNG) + 1);
	transition = get_mlx_img(game, sprite_file);
	mlx_image_to_window(game->mlx, transition, 0, 0);
	mlx_set_instance_depth(transition->instances, 20);
}

void	display_transition(t_game *game)
{
	mlx_set_window_size(game->mlx, 735, 452);
	display_transition_image(game);
	mlx_set_window_title(game->mlx, "⭐ WarpStar ⭐");
}
