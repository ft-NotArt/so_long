/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles_attack_update.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 04:30:19 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/19 05:52:00 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_dee_attack_sprite(t_attack *attack)
{
	if (attack->orient == EAST)
	{
		attack->x++ ;
		attack->image->instances->x += BITS ;
	}
	if (attack->orient == SOUTH)
	{
		attack->y++ ;
		attack->image->instances->y += BITS ;
	}
	if (attack->orient == WEST)
	{
		attack->x-- ;
		attack->image->instances->x -= BITS ;
	}
	if (attack->orient == NORTH)
	{
		attack->y-- ;
		attack->image->instances->y -= BITS ;
	}
}

static void	update_doo_attack_sprite(t_game *game, t_attack *attack)
{
	mlx_image_t	*tmp_img ;

	tmp_img = get_mlx_attack(game, attack);
	free(attack->image->pixels);
	attack->image->pixels = tmp_img->pixels ;
	tmp_img->pixels = NULL ;
	mlx_delete_image(game->mlx, tmp_img);
}

static void	update_boss_attack_sprite(t_game *game, t_attack *attack)
{
	mlx_image_t	*tmp_img ;

	if (attack->frame == FRAME3)
		attack->frame = FRAME1 ;
	tmp_img = get_mlx_attack(game, attack);
	free(attack->image->pixels);
	attack->image->pixels = tmp_img->pixels ;
	tmp_img->pixels = NULL ;
	mlx_delete_image(game->mlx, tmp_img);
}

void	update_attack_sprite(t_game *game, t_attack *attack)
{
	attack->frame++ ;
	if (attack->frame == 4)
		mlx_delete_image(game->mlx, attack->image);
	else
	{
		if (attack->type == DEE)
			update_dee_attack_sprite(attack);
		else if (attack->type == DOO)
			update_doo_attack_sprite(game, attack);
		else if (attack->type == BOSS)
			update_boss_attack_sprite(game, attack);
	}
}
