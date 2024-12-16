/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles_attack_update.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 04:30:19 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/16 17:45:47 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_dee_attack(t_attack *attack)
{
	mlx_set_instance_depth(attack->image->instances, 10);
	printf("couteau | x=%d y=%d z=%d \n", attack->image->instances->x, attack->image->instances->y, attack->image->instances->z);
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

static void	update_doo_attack(t_game *game, t_attack *attack)
{
	mlx_image_t	*tmp_img ;

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
			update_dee_attack(attack);
		else
			update_doo_attack(game, attack);
	}
}
