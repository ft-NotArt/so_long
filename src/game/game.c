/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 06:14:48 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/05 10:04:36 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_game(void *param)
{
	t_game	*game ;

	game = (t_game *) param ;
	mlx_close_window(game->mlx);
	mlx_terminate(game->mlx);
	free_maps(game->maps);
	free(game);
	exit(EXIT_SUCCESS);
}

char	*get_around_ground(char **map, int x, int y)
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
	mlx_texture_t	*texture ;
	mlx_image_t		*img ;
	char			*sprite_file ;
	char			*around;

	sprite_file = ft_calloc(ft_strlen(GRASS) + 13, sizeof(char));
	ft_strlcpy(sprite_file, GRASS, ft_strlen(GRASS) + 1) ;
	around = get_around_ground(game->maps->map, x, y);
	ft_strlcat(sprite_file, around, ft_strlen(GRASS) + 9);
	free(around);
	ft_strlcat(sprite_file, PNG, ft_strlen(sprite_file) + 5);
	texture = mlx_load_png(sprite_file);
	free(sprite_file);
	img = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	return (img);
}

mlx_image_t	*get_mlx_img(t_game *game, char *sprite_file)
{
	mlx_texture_t	*texture ;
	mlx_image_t		*img ;

	texture = mlx_load_png(sprite_file);
	img = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	return (img);
}

void	display_spites(t_game *game)
{
	int x ;
	int y ;

	y = -1 ;
	while (game->maps->map[++y])
	{
		x = -1 ;
		while (game->maps->map[y][++x])
		{
			IMG_WIN(game->mlx, get_mlx_img(game, WATER), 32 * x, 32 * y);
			if (game->maps->map[y][x] != '1')
				IMG_WIN(game->mlx, get_mlx_ground(game, x, y), 32 * x, 32 * y);
			if (game->maps->map[y][x] == 'P')
				IMG_WIN(game->mlx, get_mlx_img(game, KIRBY), 32 * x, 32 * y);
		}
	}
}

void	game_init(t_map *maps)
{
	t_game	*game ;

	game = malloc(sizeof(t_game));
	game->mlx = mlx_init(1100, 1500, "TEST", true);
	game->maps = maps ;
	

	display_spites(game);

	mlx_close_hook(game->mlx, close_game, game);
	mlx_loop(game->mlx);
}
