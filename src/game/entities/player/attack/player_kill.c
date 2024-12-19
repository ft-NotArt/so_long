/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_kill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 07:15:01 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/19 07:20:08 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_kill(t_game *game, int y, int x)
{
	del_enemy(game, &game->maps->enemies, y, x);
	del_boss(game, &game->maps->bosses, y, x);
}
