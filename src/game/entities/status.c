/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:02:16 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/09 23:15:41 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	update_pose(int current_pose)
{
	if (current_pose == STANDING || current_pose == WALKING2)
		return (WALKING1);
	else
		return (WALKING2);
}
