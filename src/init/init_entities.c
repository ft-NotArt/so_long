/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_entities.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:00:18 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/19 03:53:20 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_boss	*boss_init(int x, int y)
{
	t_boss	*boss ;

	boss = malloc(sizeof(t_boss));
	boss->image = NULL ;
	boss->x = x ;
	boss->y = y ;
	boss->orient = WEST ;
	boss->attack = NULL ;
	boss->next = NULL ;
	return (boss);
}

t_enemy	*enemy_init(t_map *map, int x, int y)
{
	t_enemy		*enemy ;
	static int	orient = 0 ;

	enemy = malloc(sizeof(t_enemy));
	enemy->image = NULL ;
	enemy->type = map->map[y][x];
	enemy->x = x ;
	enemy->y = y ;
	enemy->orient = (orient % 4);
	orient++ ;
	enemy_set_attacks(enemy);
	enemy->attack = NULL ;
	enemy->next = NULL ;
	return (enemy);
}

t_player	*player_init(void)
{
	t_player	*player ;

	player = malloc(sizeof(t_player));
	player->image = NULL ;
	player->x = 0 ;
	player->y = 0 ;
	player->orient = EAST ;
	player->status = STANDING ;
	player->step_count = 0 ;
	player->attack = NULL ;
	player->last_action_time = 0 ;
	return (player);
}
