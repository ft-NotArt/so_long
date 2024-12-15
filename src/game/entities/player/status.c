/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:02:16 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/10 02:04:11 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	alternate_walking(int current_pose)
{
	if (current_pose == STANDING || current_pose == WALKING2)
		return (WALKING1);
	else
		return (WALKING2);
}
