/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles_panel_inside.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:43:52 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/12 16:33:08 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	display_boxes(t_game *game)
{
	mlx_image_t	*img ;
	char		sprite_file[100];

	ft_strlcpy(sprite_file, BOX, ft_strlen(BOX) + 1);
	ft_strlcat(sprite_file, "1", ft_strlen(sprite_file) + 2);
	ft_strlcat(sprite_file, PNG, ft_strlen(sprite_file) + ft_strlen(PNG) + 1);
	img = get_mlx_img(game, sprite_file);
	IMG_WIN(game->mlx, img, 16, (game->maps->height * BITS) + 16);
	mlx_set_instance_depth(img->instances, 4);
	sprite_file[ft_strlen(sprite_file) - ft_strlen(PNG) - 1] = '2' ;
	img = get_mlx_img(game, sprite_file);
	IMG_WIN(game->mlx, img, 56, (game->maps->height * BITS) + 16);
	mlx_set_instance_depth(img->instances, 4);
	sprite_file[ft_strlen(sprite_file) - ft_strlen(PNG) - 1] = '3' ;
	img = get_mlx_img(game, sprite_file);
	IMG_WIN(game->mlx, img, 96, (game->maps->height * BITS) + 16);
	mlx_set_instance_depth(img->instances, 4);
}

static void	display_sign(t_game *game)
{
	mlx_image_t	*img ;
	char		sprite_file[100];

	ft_strlcpy(sprite_file, SIGN, ft_strlen(SIGN) + 1);
	ft_strlcat(sprite_file, PNG, ft_strlen(sprite_file) + ft_strlen(PNG) + 1);
	img = get_mlx_img(game, sprite_file);
	IMG_WIN(game->mlx, img,
		(game->maps->width * BITS) - 80, (game->maps->height * BITS));
	mlx_set_instance_depth(img->instances, 4);
}

static void	init_step_count(t_game *game)
{
	char		*str_step_count ;

	str_step_count = ft_itoa(game->maps->player->step_count);
	game->maps->step_count_img = mlx_put_string(game->mlx,
			str_step_count,
			(game->maps->width * BITS) - 55, (game->maps->height * BITS) + 18);
	free(str_step_count);
}

void	update_step_count(t_game *game)
{
	mlx_image_t	*new_img ;
	char		*str_step_count ;

	game->maps->player->step_count++ ;
	str_step_count = ft_itoa(game->maps->player->step_count);
	new_img = mlx_put_string(game->mlx,
			str_step_count,
			game->maps->step_count_img->instances->x,
			game->maps->step_count_img->instances->y);
	free(str_step_count);
	new_img->instances = game->maps->step_count_img->instances ;
	game->maps->step_count_img->instances = NULL ;
	mlx_delete_image(game->mlx, game->maps->step_count_img);
	game->maps->step_count_img = new_img ;
	if (ft_intlen(game->maps->player->step_count)
		> ft_intlen(game->maps->player->step_count - 1))
		new_img->instances->x -= 5 ;
}

void	display_inside_panel(t_game *game)
{
	display_boxes(game);
	display_sign(game);
	init_step_count(game);
}
