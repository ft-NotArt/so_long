/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 00:57:39 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/16 05:51:03 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_attack(t_game *game, t_enemy *enemy)
{
	enemy->attack = attack_init(enemy->type,
		enemy->x, enemy->y, enemy->orient);
	display_attack(game, enemy->attack);
}
