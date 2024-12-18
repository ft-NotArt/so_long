/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player_kill.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:00:40 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/18 12:45:28 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_doo_att_east_player(t_game *game, t_attack *attack)
{
	if (attack->frame == FRAME1
		&& is_enemy(game->maps->map[attack->y - 1][attack->x]))
		del_enemy(game, &game->maps->enemies, attack->y - 1, attack->x);
	else if (attack->frame == FRAME2
		&& is_enemy(game->maps->map[attack->y][attack->x + 1]))
		del_enemy(game, &game->maps->enemies, attack->y, attack->x + 1);
	else if (attack->frame == FRAME3
		&& is_enemy(game->maps->map[attack->y + 1][attack->x]))
		del_enemy(game, &game->maps->enemies, attack->y + 1, attack->x);
}

static void	check_doo_att_south_player(t_game *game, t_attack *attack)
{
	if (attack->frame == FRAME1
		&& is_enemy(game->maps->map[attack->y][attack->x + 1]))
		del_enemy(game, &game->maps->enemies, attack->y, attack->x + 1);
	else if (attack->frame == FRAME2
		&& is_enemy(game->maps->map[attack->y + 1][attack->x]))
		del_enemy(game, &game->maps->enemies, attack->y + 1, attack->x);
	else if (attack->frame == FRAME3
		&& is_enemy(game->maps->map[attack->y][attack->x - 1]))
		del_enemy(game, &game->maps->enemies, attack->y, attack->x - 1);
}

static void	check_doo_att_west_player(t_game *game, t_attack *attack)
{
	if (attack->frame == FRAME1
		&& is_enemy(game->maps->map[attack->y + 1][attack->x]))
		del_enemy(game, &game->maps->enemies, attack->y + 1, attack->x);
	else if (attack->frame == FRAME2
		&& is_enemy(game->maps->map[attack->y][attack->x - 1]))
		del_enemy(game, &game->maps->enemies, attack->y, attack->x - 1);
	else if (attack->frame == FRAME3
		&& is_enemy(game->maps->map[attack->y - 1][attack->x]))
		del_enemy(game, &game->maps->enemies, attack->y - 1, attack->x);
}

static void	check_doo_att_north_player(t_game *game, t_attack *attack)
{
	if (attack->frame == FRAME1
		&& is_enemy(game->maps->map[attack->y][attack->x - 1]))
		del_enemy(game, &game->maps->enemies, attack->y, attack->x - 1);
	else if (attack->frame == FRAME2
		&& is_enemy(game->maps->map[attack->y - 1][attack->x]))
		del_enemy(game, &game->maps->enemies, attack->y - 1, attack->x);
	else if (attack->frame == FRAME3
		&& is_enemy(game->maps->map[attack->y][attack->x + 1]))
		del_enemy(game, &game->maps->enemies, attack->y, attack->x + 1);
}

void	check_player_attack(t_game *game, t_attack *attack)
{
	if (attack->x <= 0 || attack->y <= 0
		|| (size_t) attack->x >= game->maps->width - 1
		|| (size_t) attack->y >= game->maps->height - 1)
		return ;
	if (attack->type == DEE)
	{
		if (is_enemy(game->maps->map[attack->y][attack->x]))
			del_enemy(game, &game->maps->enemies, attack->y, attack->x);
	}
	else
	{
		if (is_enemy(game->maps->map[attack->y][attack->x]))
			del_enemy(game, &game->maps->enemies, attack->y, attack->x);
		if (attack->orient == EAST)
			check_doo_att_east_player(game, attack);
		if (attack->orient == SOUTH)
			check_doo_att_south_player(game, attack);
		if (attack->orient == WEST)
			check_doo_att_west_player(game, attack);
		if (attack->orient == NORTH)
			check_doo_att_north_player(game, attack);
	}
}
