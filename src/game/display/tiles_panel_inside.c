/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles_panel_inside.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:43:52 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/12 15:39:22 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	display_boxes(t_game *game)
{
	mlx_image_t	*img ;
	char		sprite_file[100] ;

	ft_strlcpy(sprite_file, BOX, ft_strlen(BOX) + 1);
	ft_strlcat(sprite_file, "1", ft_strlen(sprite_file) + 2);
	ft_strlcat(sprite_file, PNG, ft_strlen(sprite_file) + ft_strlen(PNG) + 1);
	img = get_mlx_img(game, sprite_file);
	IMG_WIN(game->mlx, img, 16, (game->maps->height * BITS) + 16);
	mlx_set_instance_depth(img->instances, 4);
	sprite_file[ft_strlen(sprite_file) - ft_strlen(PNG) - 1] = '2' ;
	img = get_mlx_img(game, sprite_file);
	IMG_WIN(game->mlx, img, 56, (game->maps->height * BITS) + 16);
	mlx_set_instance_depth(img->instances, 4);
	sprite_file[ft_strlen(sprite_file) - ft_strlen(PNG) - 1] = '3' ;
	img = get_mlx_img(game, sprite_file);
	IMG_WIN(game->mlx, img, 96, (game->maps->height * BITS) + 16);
	mlx_set_instance_depth(img->instances, 4);
}

static void	display_sign(t_game *game)
{
	mlx_image_t	*img ;
	char		sprite_file[100] ;

	ft_strlcpy(sprite_file, SIGN, ft_strlen(SIGN) + 1);
	ft_strlcat(sprite_file, PNG, ft_strlen(sprite_file) + ft_strlen(PNG) + 1);
	img = get_mlx_img(game, sprite_file);
	IMG_WIN(game->mlx, img,
		(game->maps->width * BITS) - 80, (game->maps->height * BITS));
	mlx_set_instance_depth(img->instances, 4);
}

void	display_inside_panel(t_game *game)
{
	display_boxes(game);
	display_sign(game);
}
