/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles_boss.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:24:48 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/18 15:42:03 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static mlx_image_t	*get_mlx_boss(t_game *game, t_boss *boss)
{
	char	sprite_file[100];

	ft_strlcpy(sprite_file, CELL, ft_strlen(CELL) + 1);
	ft_strlcat(sprite_file, P_STANDING,
		ft_strlen(sprite_file) + ft_strlen(P_STANDING) + 1);
	add_orient(boss->orient, sprite_file);
	ft_strlcat(sprite_file, PNG, ft_strlen(sprite_file) + ft_strlen(PNG) + 1);
	return (get_mlx_img(game, sprite_file));
}

void	display_boss(t_game *game, int x, int y)
{
	t_boss		*boss ;
	mlx_image_t	*img ;

	boss = boss_init(x, y);
	boss_add_back(&(game->maps->bosses), boss);
	img = get_mlx_boss(game, boss);
	boss->image = img ;
	mlx_image_to_window(game->mlx, img, (BITS * x) - 16, (BITS * (y - 1)) - 8);
	mlx_set_instance_depth(img->instances, 9);
}

void	update_boss_sprite(t_game *game, t_boss *boss)
{
	mlx_image_t	*tmp_img ;

	tmp_img = get_mlx_boss(game, boss);
	free(boss->image->pixels);
	boss->image->pixels = tmp_img->pixels ;
	tmp_img->pixels = NULL ;
	mlx_delete_image(game->mlx, tmp_img);
}
