/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:40:27 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/19 07:48:58 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	player_add_status(t_pos status, char *sprite_file)
{
	if (status == STANDING)
		ft_strlcat(sprite_file, P_STANDING,
			ft_strlen(sprite_file) + ft_strlen(P_STANDING) + 1);
	else if (status == WALKING1)
		ft_strlcat(sprite_file, P_WALKING_1,
			ft_strlen(sprite_file) + ft_strlen(P_WALKING_1) + 1);
	else if (status == WALKING2)
		ft_strlcat(sprite_file, P_WALKING_2,
			ft_strlen(sprite_file) + ft_strlen(P_WALKING_2) + 1);
	else if (status == SWALLOWING)
		ft_strlcat(sprite_file, P_SWALLOWING,
			ft_strlen(sprite_file) + ft_strlen(P_SWALLOWING) + 1);
}

static mlx_image_t	*get_mlx_player(t_game *game)
{
	char	sprite_file[100];

	ft_strlcpy(sprite_file, PLAYER, ft_strlen(PLAYER) + 1);
	ft_strlcat(sprite_file, PLAYER_TYPE,
		ft_strlen(sprite_file) + ft_strlen(PLAYER_TYPE) + 1);
	player_add_status(game->maps->player->status, sprite_file);
	add_orient(game->maps->player->orient, sprite_file);
	ft_strlcat(sprite_file, PNG, ft_strlen(sprite_file) + ft_strlen(PNG) + 1);
	return (get_mlx_img(game, sprite_file));
}

void	display_player(t_game *game, int x, int y)
{
	game->maps->player->image = get_mlx_player(game);
	mlx_image_to_window(game->mlx, game->maps->player->image,
		BITS * x, (BITS * y) - 8);
	mlx_set_instance_depth(game->maps->player->image->instances, 600);
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
