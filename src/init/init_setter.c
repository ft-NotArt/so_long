/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_setter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 01:51:00 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/17 01:51:49 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_attack_coord(t_attack *attack, int x, int y)
{
	attack->x = x ;
	attack->y = y ;
	if (attack->orient == EAST)
		attack->x++ ;
	if (attack->orient == SOUTH)
		attack->y++ ;
	if (attack->orient == WEST)
		attack->x-- ;
	if (attack->orient == NORTH)
		attack->y-- ;
}

void	enemy_set_attacks(t_enemy *enemy, t_map *map, int x, int y)
{
	enemy->attack_set[0] = 0 ;
	enemy->attack_set[1] = 0 ;
	enemy->attack_set[2] = 0 ;
	if (map->map[y][x] == DEE)
		enemy->attack_set[1] = 1;
	else
		enemy->attack_set[2] = 1;
}
