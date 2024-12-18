/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:46:43 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/18 10:27:37 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_attack	*attack_init(t_ype type, int x, int y, t_orient orient)
{
	t_attack	*attack ;

	attack = malloc(sizeof(t_attack));
	attack->frame = FRAME1 ;
	attack->type = type ;
	attack->orient = orient ;
	set_attack_coord(attack, x, y);
	attack->image = NULL ;
	return (attack);
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

t_map	*map_init(char *map_file)
{
	t_map	*map ;

	map = malloc(sizeof(t_map));
	map->map = read_map(map_file);
	map->width = 0 ;
	map->height = 0 ;
	map->enemy_number = 0 ;
	map->player = player_init();
	map->step_count_img = NULL ;
	map->enemies = NULL ;
	map->next = NULL ;
	return (map);
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

t_game	*game_init(t_map *maps)
{
	t_game		*game ;
	static char	level = '0' ;
	char		win_name[50];

	game = malloc(sizeof(t_game));
	game->maps = maps ;
	level++ ;
	ft_strlcpy(win_name, LEVEL, ft_strlen(LEVEL) + 1);
	ft_strlcat(win_name, &level, ft_strlen(LEVEL) + 2);
	game->mlx = mlx_init(game->maps->width * BITS,
			(game->maps->height + 2) * BITS, win_name, false);
	ft_bzero(game->player_attack_set, 3 * sizeof(bool));
	game->player_attack_set_img[0] = NULL ;
	game->player_attack_set_img[1] = NULL ;
	game->player_attack_set_img[2] = NULL ;
	game->time_from_transition = 0 ;
	return (game);
}
