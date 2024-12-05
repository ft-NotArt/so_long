/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:46:51 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/05 16:01:20 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*get_mlx_img(t_game *game, char *sprite_file)
{
	mlx_texture_t	*texture ;
	mlx_image_t		*img ;

	texture = mlx_load_png(sprite_file);
	img = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	return (img);
}

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

mlx_image_t	*get_mlx_ground(t_game *game, int x, int y)
{
	mlx_image_t		*img ;
	char			*sprite_file ;
	char			*around;

	sprite_file = ft_calloc(ft_strlen(GRASS_EX) + 1, sizeof(char));
	ft_strlcpy(sprite_file, GRASS, ft_strlen(GRASS) + 1) ;
	around = get_around_ground(game->maps->map, x, y);
	ft_strlcat(sprite_file, around, ft_strlen(sprite_file) + 9);
	free(around);
	ft_strlcat(sprite_file, PNG, ft_strlen(sprite_file) + 5);
	img = get_mlx_img(game, sprite_file);
	free(sprite_file);
	return (img);
}

static void	mlx_player_add_pos(t_game *game, char *sprite_file)
{
	if (game->maps->player->pose == STANDING)
		ft_strlcat(sprite_file, K_STANDIN,
			ft_strlen(sprite_file) + ft_strlen(K_STANDIN) + 1);
	else if (game->maps->player->pose == WALKING1)
		ft_strlcat(sprite_file, K_WALKIN_1,
			ft_strlen(sprite_file) + ft_strlen(K_WALKIN_1) + 1);
	else if (game->maps->player->pose == WALKING2)
		ft_strlcat(sprite_file, K_WALKIN_2,
			ft_strlen(sprite_file) + ft_strlen(K_WALKIN_2) + 1);
}

static void	mlx_player_add_orient(t_game *game, char *sprite_file)
{
	if (game->maps->player->orient == EAST)
		ft_strlcat(sprite_file, RIGHT,
			ft_strlen(sprite_file) + ft_strlen(RIGHT) + 1);
	else if (game->maps->player->orient == SOUTH)
		ft_strlcat(sprite_file, FRONT,
			ft_strlen(sprite_file) + ft_strlen(FRONT) + 1);
	else if (game->maps->player->orient == WEST)
		ft_strlcat(sprite_file, LEFT,
			ft_strlen(sprite_file) + ft_strlen(LEFT) + 1);
	else if (game->maps->player->orient == NORTH)
		ft_strlcat(sprite_file, BACK,
			ft_strlen(sprite_file) + ft_strlen(BACK) + 1);
}

mlx_image_t	*get_mlx_player(t_game *game)
{
	mlx_image_t		*img ;
	char			*sprite_file ;

	sprite_file = ft_calloc(ft_strlen(KIRBY_EX) + 1, sizeof(char));
	ft_strlcpy(sprite_file, KIRBY, ft_strlen(KIRBY) + 1) ;
	mlx_player_add_pos(game, sprite_file);
	mlx_player_add_orient(game, sprite_file);
	ft_strlcat(sprite_file, PNG, ft_strlen(sprite_file) + ft_strlen(PNG) + 1);
	img = get_mlx_img(game, sprite_file);
	free(sprite_file);
	return (img);
}
