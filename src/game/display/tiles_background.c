/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles_background.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:46:51 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/12 16:34:20 by anoteris         ###   ########.fr       */
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
