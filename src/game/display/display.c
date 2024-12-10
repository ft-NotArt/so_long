/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:55:57 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/10 16:44:18 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	display_water(t_game *game, int x, int y)
{
	mlx_image_t	*water ;

	water = get_mlx_img(game, WATER);
	IMG_WIN(game->mlx, water, BITS * x, BITS * y);
	mlx_set_instance_depth(water->instances, 0);
}

static void	display_ground(t_game *game, int x, int y)
{
	mlx_image_t	*ground ;

	ground = get_mlx_ground(game, x, y);
	IMG_WIN(game->mlx, ground, BITS * x, BITS * y);
	mlx_set_instance_depth(ground->instances, 2);
}

static void	display_star(t_game *game, int x, int y)
{
	mlx_image_t	*star ;

	star = get_mlx_img(game, STAR);
	IMG_WIN(game->mlx, star, BITS * x, BITS * y);
	mlx_set_instance_depth(star->instances, 4);
}

static void	display_player(t_game *game, int x, int y)
{
	game->maps->player->image = get_mlx_player(game);
	IMG_WIN(game->mlx, game->maps->player->image, BITS * x, (BITS * y) - 8);
	mlx_set_instance_depth(game->maps->player->image->instances, 6);
}

static void	display_enemy(t_game *game, int x, int y)
{
	t_enemy		*enemy ;
	mlx_image_t	*img ;

	enemy = enemy_init(game->maps, x, y);
	enemy_add_back(&(game->maps->enemies), enemy);
	img = get_mlx_enemy(game, enemy);
	enemy->image = img ;
	IMG_WIN(game->mlx, img, BITS * x, (BITS * y) - 8);
	mlx_set_instance_depth(img->instances, 10);
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
}
