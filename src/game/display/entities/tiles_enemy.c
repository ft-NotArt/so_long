/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 04:20:54 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/15 23:27:07 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	enemy_add_orient(int orient, char *sprite_file)
{
	if (orient == EAST)
		ft_strlcat(sprite_file, RIGHT,
			ft_strlen(sprite_file) + ft_strlen(RIGHT) + 1);
	else if (orient == SOUTH)
		ft_strlcat(sprite_file, FRONT,
			ft_strlen(sprite_file) + ft_strlen(FRONT) + 1);
	else if (orient == WEST)
		ft_strlcat(sprite_file, LEFT,
			ft_strlen(sprite_file) + ft_strlen(LEFT) + 1);
	else if (orient == NORTH)
		ft_strlcat(sprite_file, BACK,
			ft_strlen(sprite_file) + ft_strlen(BACK) + 1);
}

static mlx_image_t	*get_mlx_enemy(t_game *game, t_enemy *enemy)
{
	mlx_image_t		*img ;
	char			sprite_file[100];

	if (enemy->type == DEE)
		ft_strlcpy(sprite_file, WADDLE_DEE, ft_strlen(WADDLE_DEE) + 1);
	else
		ft_strlcpy(sprite_file, WADDLE_DOO, ft_strlen(WADDLE_DOO) + 1);
	enemy_add_orient(enemy->orient, sprite_file);
	ft_strlcat(sprite_file, PNG, ft_strlen(sprite_file) + ft_strlen(PNG) + 1);
	img = get_mlx_img(game, sprite_file);
	return (img);
}

void	display_enemy(t_game *game, int x, int y)
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

void	update_enemy_sprite(t_game *game, t_enemy *enemy)
{
	mlx_image_t	*tmp_img ;

	tmp_img = get_mlx_enemy(game, enemy);
	free(enemy->image->pixels);
	enemy->image->pixels = tmp_img->pixels ;
	tmp_img->pixels = NULL ;
	mlx_delete_image(game->mlx, tmp_img);
}
