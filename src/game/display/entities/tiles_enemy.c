/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 04:20:54 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/17 02:50:47 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static mlx_image_t	*get_mlx_enemy(t_game *game, t_enemy *enemy)
{
	char	sprite_file[100];

	if (enemy->type == DEE)
		ft_strlcpy(sprite_file, WADDLE_DEE, ft_strlen(WADDLE_DEE) + 1);
	else
		ft_strlcpy(sprite_file, WADDLE_DOO, ft_strlen(WADDLE_DOO) + 1);
	add_orient(enemy->orient, sprite_file);
	ft_strlcat(sprite_file, PNG, ft_strlen(sprite_file) + ft_strlen(PNG) + 1);
	return (get_mlx_img(game, sprite_file));
}

void	display_enemy(t_game *game, int x, int y)
{
	t_enemy		*enemy ;
	mlx_image_t	*img ;

	enemy = enemy_init(game->maps, x, y);
	enemy_add_back(&(game->maps->enemies), enemy);
	img = get_mlx_enemy(game, enemy);
	enemy->image = img ;
	mlx_image_to_window(game->mlx, img, BITS * x, (BITS * y) - 8);
	mlx_set_instance_depth(img->instances, 8);
}

void	update_enemy_sprite(t_game *game, t_enemy *enemy)
{
	mlx_image_t	*tmp_img ;

	tmp_img = get_mlx_enemy(game, enemy);
	free(enemy->image->pixels);
	enemy->image->pixels = tmp_img->pixels ;
	tmp_img->pixels = NULL ;
	mlx_delete_image(game->mlx, tmp_img);
}
