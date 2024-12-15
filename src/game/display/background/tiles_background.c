/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles_background.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:46:51 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/16 00:00:48 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*get_around_ground(char **map, int x, int y)
{
	char	*around;

	around = ft_calloc(9, sizeof(char));
	around[0] = '0' + ('1' != map[y - 1][x]);
	around[1] = '0' + ('1' != map[y - 1][x + 1]
			&& '1' != map[y - 1][x] && '1' != map[y][x + 1]);
	around[2] = '0' + ('1' != map[y][x + 1]);
	around[3] = '0' + ('1' != map[y + 1][x + 1]
			&& '1' != map[y][x + 1] && '1' != map[y + 1][x]);
	around[4] = '0' + ('1' != map[y + 1][x]);
	around[5] = '0' + ('1' != map[y + 1][x - 1]
			&& '1' != map[y + 1][x] && '1' != map[y][x - 1]);
	around[6] = '0' + ('1' != map[y][x - 1]);
	around[7] = '0' + ('1' != map[y - 1][x - 1]
			&& '1' != map[y][x - 1] && '1' != map[y - 1][x]);
	return (around);
}

static mlx_image_t	*get_mlx_ground(t_game *game, int x, int y)
{
	mlx_image_t		*img ;
	char			sprite_file[100];
	char			*around;
	char			*str_rand_uchar ;

	ft_strlcpy(sprite_file, GRASS, ft_strlen(GRASS) + 1);
	around = get_around_ground(game->maps->map, x, y);
	if (!ft_strcmp(around, "11111111") && (rand_uchar() % 3) == 0)
	{
		ft_strlcat(sprite_file, DECO,
			ft_strlen(sprite_file) + ft_strlen(DECO) + 1);
		str_rand_uchar = ft_itoa(rand_uchar() % 12);
		ft_strlcat(sprite_file, str_rand_uchar, ft_strlen(sprite_file) + 3);
		free(str_rand_uchar);
	}
	else
	{
		ft_strlcat(sprite_file, GROUND,
			ft_strlen(sprite_file) + ft_strlen(GROUND) + 1);
		ft_strlcat(sprite_file, around, ft_strlen(sprite_file) + 9);
	}
	free(around);
	ft_strlcat(sprite_file, PNG, ft_strlen(sprite_file) + ft_strlen(PNG) + 1);
	img = get_mlx_img(game, sprite_file);
	return (img);
}

void	display_ground(t_game *game, int x, int y)
{
	mlx_image_t	*ground ;

	ground = get_mlx_ground(game, x, y);
	IMG_WIN(game->mlx, ground, BITS * x, BITS * y);
	mlx_set_instance_depth(ground->instances, 2);
}

void	display_water(t_game *game, int x, int y)
{
	mlx_image_t	*water ;

	water = get_mlx_img(game, WATER);
	IMG_WIN(game->mlx, water, BITS * x, BITS * y);
	mlx_set_instance_depth(water->instances, 0);
}

void	display_star(t_game *game, int x, int y)
{
	mlx_image_t	*star ;

	star = get_mlx_img(game, STAR);
	IMG_WIN(game->mlx, star, BITS * x, BITS * y);
	mlx_set_instance_depth(star->instances, 4);
}
