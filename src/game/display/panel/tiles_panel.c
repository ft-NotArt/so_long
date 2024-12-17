/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles_panel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:59:48 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/17 02:49:42 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	panel_add_type(t_game *game, size_t x, char *sprite_file)
{
	if (x == 0 || x == game->maps->width - 1)
	{
		ft_strlcat(sprite_file, CORNER,
			ft_strlen(sprite_file) + ft_strlen(CORNER) + 1);
	}
	else
	{
		ft_strlcat(sprite_file, BORDER,
			ft_strlen(sprite_file) + ft_strlen(BORDER) + 1);
	}
}

static void	panel_add_vertical(size_t y, char *sprite_file)
{
	if (y == 0)
	{
		ft_strlcat(sprite_file, TOP,
			ft_strlen(sprite_file) + ft_strlen(TOP) + 1);
	}
	else
	{
		ft_strlcat(sprite_file, BOT,
			ft_strlen(sprite_file) + ft_strlen(BOT) + 1);
	}
}

static void	panel_add_side(t_game *game, size_t x, char *sprite_file)
{
	if (x == 0)
	{
		ft_strlcat(sprite_file, LEFT,
			ft_strlen(sprite_file) + ft_strlen(LEFT) + 1);
	}
	else if (x == game->maps->width - 1)
	{
		ft_strlcat(sprite_file, RIGHT,
			ft_strlen(sprite_file) + ft_strlen(RIGHT) + 1);
	}
}

mlx_image_t	*get_mlx_panel(t_game *game, size_t x, size_t y)
{
	char	sprite_file[100];

	ft_strlcpy(sprite_file, PANEL, ft_strlen(PANEL) + 1);
	panel_add_type(game, x, sprite_file);
	panel_add_vertical(y, sprite_file);
	if (x == 0 || x == game->maps->width - 1)
		ft_strlcat(sprite_file, "_", ft_strlen(sprite_file) + 2);
	panel_add_side(game, x, sprite_file);
	ft_strlcat(sprite_file, PNG, ft_strlen(sprite_file) + ft_strlen(PNG) + 1);
	return (get_mlx_img(game, sprite_file));
}
