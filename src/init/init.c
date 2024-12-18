/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:46:43 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/18 15:13:01 by anoteris         ###   ########.fr       */
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
	map->bosses = NULL ;
	map->next = NULL ;
	return (map);
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
