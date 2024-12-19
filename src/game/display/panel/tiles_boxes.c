/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles_boxes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:10:21 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/19 07:49:15 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_boxes(t_game *game)
{
	mlx_image_t	*img ;
	char		sprite_file[100];

	ft_strlcpy(sprite_file, BOX, ft_strlen(BOX) + 1);
	ft_strlcat(sprite_file, "1", ft_strlen(sprite_file) + 2);
	ft_strlcat(sprite_file, PNG, ft_strlen(sprite_file) + ft_strlen(PNG) + 1);
	img = get_mlx_img(game, sprite_file);
	mlx_image_to_window(game->mlx, img, 16, (game->maps->height * BITS) + 16);
	mlx_set_instance_depth(img->instances, 1400);
	sprite_file[ft_strlen(sprite_file) - ft_strlen(PNG) - 1] = '2' ;
	img = get_mlx_img(game, sprite_file);
	mlx_image_to_window(game->mlx, img, 56, (game->maps->height * BITS) + 16);
	mlx_set_instance_depth(img->instances, 1400);
	sprite_file[ft_strlen(sprite_file) - ft_strlen(PNG) - 1] = '3' ;
	img = get_mlx_img(game, sprite_file);
	mlx_image_to_window(game->mlx, img, 96, (game->maps->height * BITS) + 16);
	mlx_set_instance_depth(img->instances, 1400);
}

static void	display_power_swallow(t_game *game)
{
	char		sprite_file[100];

	ft_strlcpy(sprite_file, POWER, ft_strlen(POWER) + 1);
	ft_strlcat(sprite_file, SWALLOW,
		ft_strlen(sprite_file) + ft_strlen(SWALLOW) + 1);
	ft_strlcat(sprite_file, PNG, ft_strlen(sprite_file) + ft_strlen(PNG) + 1);
	game->player_attack_set_img[0] = get_mlx_img(game, sprite_file);
	mlx_image_to_window(game->mlx, game->player_attack_set_img[0],
		16, (game->maps->height * BITS) + 16);
	mlx_set_instance_depth(game->player_attack_set_img[0]->instances, 1600);
}

static void	display_power_knife(t_game *game)
{
	char		sprite_file[100];

	ft_strlcpy(sprite_file, POWER, ft_strlen(POWER) + 1);
	ft_strlcat(sprite_file, KNIFE,
		ft_strlen(sprite_file) + ft_strlen(KNIFE) + 1);
	ft_strlcat(sprite_file, PNG, ft_strlen(sprite_file) + ft_strlen(PNG) + 1);
	game->player_attack_set_img[1] = get_mlx_img(game, sprite_file);
	mlx_image_to_window(game->mlx, game->player_attack_set_img[1],
		56, (game->maps->height * BITS) + 16);
	mlx_set_instance_depth(game->player_attack_set_img[1]->instances, 1600);
	game->player_attack_set_img[1]->enabled = game->player_attack_set[1];
}

static void	display_power_magic_beam(t_game *game)
{
	char		sprite_file[100];

	ft_strlcpy(sprite_file, POWER, ft_strlen(POWER) + 1);
	ft_strlcat(sprite_file, MAGIC_BEAM,
		ft_strlen(sprite_file) + ft_strlen(MAGIC_BEAM) + 1);
	ft_strlcat(sprite_file, PNG, ft_strlen(sprite_file) + ft_strlen(PNG) + 1);
	game->player_attack_set_img[2] = get_mlx_img(game, sprite_file);
	mlx_image_to_window(game->mlx, game->player_attack_set_img[2],
		96, (game->maps->height * BITS) + 16);
	mlx_set_instance_depth(game->player_attack_set_img[2]->instances, 1600);
	game->player_attack_set_img[2]->enabled = game->player_attack_set[2];
}

void	display_powers(t_game *game)
{
	display_power_swallow(game);
	display_power_knife(game);
	display_power_magic_beam(game);
}
