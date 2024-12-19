/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles_attack_display.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 03:24:38 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/19 09:32:56 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_attack_img_x(t_attack *attack)
{
	if (attack->type == BOSS && attack->orient == WEST)
		return ((attack->x - 8) * BITS);
	else if (attack->type == DOO)
	{
		if (attack->orient == SOUTH)
			return ((attack->x * BITS) - BITS / 2);
		else if (attack->orient == WEST)
			return ((attack->x - 1) * BITS);
		else if (attack->orient == NORTH)
			return ((attack->x * BITS) - BITS / 2);
	}
	return (attack->x * BITS);
}

static int	get_attack_img_y(t_attack *attack)
{
	if (attack->type == BOSS)
		return (((attack->y - 1) * BITS) - 24);
	else if (attack->type == DOO)
	{
		if (attack->orient == EAST)
			return ((attack->y * BITS) - BITS / 2);
		else if (attack->orient == WEST)
			return ((attack->y * BITS) - BITS / 2);
		else if (attack->orient == NORTH)
			return ((attack->y - 1) * BITS);
	}
	return (attack->y * BITS);
}

void	display_attack(t_game *game, t_attack *attack)
{
	static int	count = 0 ;

	attack->image = get_mlx_attack(game, attack);
	mlx_image_to_window(game->mlx, attack->image,
		get_attack_img_x(attack), get_attack_img_y(attack));
	mlx_set_instance_depth(attack->image->instances, 30 + count);
	count = (count + 1) % 25 ;
}
