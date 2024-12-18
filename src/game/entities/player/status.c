/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:02:16 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/18 10:46:32 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	alternate_walking(t_player *player)
{
	if (player->status != WALKING1)
		player->status = WALKING1 ;
	else
		player->status = WALKING2 ;
}
