/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:40:27 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/15 23:28:26 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	player_add_pos(int pose, char *sprite_file)
{
	if (pose == STANDING)
		ft_strlcat(sprite_file, K_STANDING,
			ft_strlen(sprite_file) + ft_strlen(K_STANDING) + 1);
	else if (pose == WALKING1)
		ft_strlcat(sprite_file, K_WALKING_1,
			ft_strlen(sprite_file) + ft_strlen(K_WALKING_1) + 1);
	else if (pose == WALKING2)
		ft_strlcat(sprite_file, K_WALKING_2,
			ft_strlen(sprite_file) + ft_strlen(K_WALKING_2) + 1);
	else if (pose == SWALLOWING)
		ft_strlcat(sprite_file, K_SWALLOWING,
			ft_strlen(sprite_file) + ft_strlen(K_SWALLOWING) + 1);
}

static void	player_add_orient(int orient, char *sprite_file)
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

static mlx_image_t	*get_mlx_player(t_game *game)
{
	mlx_image_t		*img ;
	char			sprite_file[100];

	ft_strlcpy(sprite_file, KIRBY, ft_strlen(KIRBY) + 1);
	player_add_pos(game->maps->player->pose, sprite_file);
	player_add_orient(game->maps->player->orient, sprite_file);
	ft_strlcat(sprite_file, PNG, ft_strlen(sprite_file) + ft_strlen(PNG) + 1);
	img = get_mlx_img(game, sprite_file);
	return (img);
}

void	display_player(t_game *game, int x, int y)
{
	game->maps->player->image = get_mlx_player(game);
	IMG_WIN(game->mlx, game->maps->player->image, BITS * x, (BITS * y) - 8);
	mlx_set_instance_depth(game->maps->player->image->instances, 6);
}

void	update_player_sprite(t_game *game, t_player *player)
{
	mlx_image_t	*tmp_img ;

	tmp_img = get_mlx_player(game);
	free(player->image->pixels);
	player->image->pixels = tmp_img->pixels ;
	tmp_img->pixels = NULL ;
	mlx_delete_image(game->mlx, tmp_img);
}
