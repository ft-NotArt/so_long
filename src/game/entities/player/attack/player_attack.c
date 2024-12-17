/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_attack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:15:59 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/17 03:06:20 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	absorb_attack(t_game *game, t_enemy *enemy)
{
	int	i ;

	if (!enemy)
		return ;
	i = -1 ;
	while (++i < 3)
	{
		if (enemy->attack_set[i] == 1)
		{
			game->player_attack_set[i] = 1 ;
			game->player_attack_set_img[i]->enabled = true ;
		}
	}
}

void	player_swallow(t_game *game, t_map *maps, char **map, t_player *player)
{
	if (player->orient == EAST && is_enemy(map[player->y][player->x + 1]))
	{
		absorb_attack(game, get_enemy(maps->enemies, player->y, player->x + 1));
		enemy_del(game, &maps->enemies, player->y, player->x + 1);
	}
	if (player->orient == SOUTH && is_enemy(map[player->y + 1][player->x]))
	{
		absorb_attack(game, get_enemy(maps->enemies, player->y + 1, player->x));
		enemy_del(game, &maps->enemies, player->y + 1, player->x);
	}
	if (player->orient == WEST && is_enemy(map[player->y][player->x - 1]))
	{
		absorb_attack(game, get_enemy(maps->enemies, player->y, player->x - 1));
		enemy_del(game, &maps->enemies, player->y, player->x - 1);
	}
	if (player->orient == NORTH && is_enemy(map[player->y - 1][player->x]))
	{
		absorb_attack(game, get_enemy(maps->enemies, player->y - 1, player->x));
		enemy_del(game, &maps->enemies, player->y - 1, player->x);
	}
	player->status = SWALLOWING ;
	player->last_action_time = mlx_get_time();
	update_player_sprite(game, player);
}

void	player_knife(t_game *game, t_player *player)
{
	player->attack = attack_init(DEE, player->x, player->y, player->orient);
	display_attack(game, player->attack);
	check_player_attack(game, player);
}

void	player_magic_beam(t_game *game, t_player *player)
{
	player->status = STANDING ;
	update_player_sprite(game, player);
	player->status = ATTACKING ;
	player->attack = attack_init(DOO, player->x, player->y, player->orient);
	display_attack(game, player->attack);
	check_player_attack(game, player);
}

void	update_player_attack(t_game *game, t_player *player)
{
	update_attack_sprite(game, player->attack);
	if (player->attack->frame == 4)
	{
		(free(player->attack), player->attack = NULL);
		if (player->status == ATTACKING)
			player->status = STANDING ;
	}
	else
		check_player_attack(game, player);
}
