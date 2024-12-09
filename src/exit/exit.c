/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 02:10:19 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/09 23:30:48 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static void	free_player(t_player *player)
// {
// 	free(player->image);
// 	free(player);
// }

void	free_maps(t_map *maps)
{
	t_map	*next ;

	while (maps)
	{
		free_str_array(maps->map);
		// free_player(maps->player);
		free(maps->player);
		next = maps->next ;
		free(maps);
		maps = next ;
	}
}

void	free_game(t_game *game)
{
	free_maps(game->maps);
	free(game);
}
