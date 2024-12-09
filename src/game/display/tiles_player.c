/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:40:27 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/09 23:43:58 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	ft_strlcpy(sprite_file, KIRBY, ft_strlen(KIRBY) + 1);
	mlx_player_add_pos(game, sprite_file);
	mlx_player_add_orient(game, sprite_file);
	ft_strlcat(sprite_file, PNG, ft_strlen(sprite_file) + ft_strlen(PNG) + 1);
	img = get_mlx_img(game, sprite_file);
	free(sprite_file);
	return (img);
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
