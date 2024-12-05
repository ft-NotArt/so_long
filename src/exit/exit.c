/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 02:10:19 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/05 12:54:37 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_maps(t_map *maps)
{
	t_map	*next ;

	while (maps)
	{
		free_str_array(maps->map);
		free(maps->player);
		next = maps->next ;
		free(maps);
		maps = next ;
	}
}
