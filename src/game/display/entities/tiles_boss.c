/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles_boss.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:24:48 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/19 04:35:11 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	boss_add_status(t_pos status, char *sprite_file)
{
	if (status == STANDING)
		ft_strlcat(sprite_file, P_STANDING,
			ft_strlen(sprite_file) + ft_strlen(P_STANDING) + 1);
	else if (status == LOADING1)
		ft_strlcat(sprite_file, P_LOADING_1,
			ft_strlen(sprite_file) + ft_strlen(P_LOADING_1) + 1);
	else if (status == LOADING2)
		ft_strlcat(sprite_file, P_LOADING_2,
			ft_strlen(sprite_file) + ft_strlen(P_LOADING_2) + 1);
	else if (status == LOADING3)
		ft_strlcat(sprite_file, P_LOADING_3,
			ft_strlen(sprite_file) + ft_strlen(P_LOADING_3) + 1);
	else if (status == LOADING4)
		ft_strlcat(sprite_file, P_LOADING_4,
			ft_strlen(sprite_file) + ft_strlen(P_LOADING_4) + 1);
	else if (status == LOADING5)
		ft_strlcat(sprite_file, P_LOADING_5,
			ft_strlen(sprite_file) + ft_strlen(P_LOADING_5) + 1);
	else if (status == ATTACKING)
		ft_strlcat(sprite_file, P_LAUNCHING,
			ft_strlen(sprite_file) + ft_strlen(P_LAUNCHING) + 1);
}

static mlx_image_t	*get_mlx_boss(t_game *game, t_boss *boss)
{
	char	sprite_file[100];

	ft_strlcpy(sprite_file, CELL, ft_strlen(CELL) + 1);
	boss_add_status(boss->status, sprite_file);
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
