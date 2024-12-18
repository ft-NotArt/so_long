/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_entities.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:07:33 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/18 15:21:49 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_boss(t_boss *boss)
{
	if (boss->attack != NULL)
	{
		if (boss->attack->image != NULL)
			boss->attack->image->enabled = false ;
		free(boss->attack);
	}
	free(boss);
}

void	free_bosses(t_boss **bosses)
{
	t_boss	*next ;

	while (*bosses)
	{
		next = (*bosses)->next ;
		free_boss(*bosses);
		(*bosses) = next ;
	}
	(*bosses) = NULL ;
}

void	free_enemy(t_enemy *enemy)
{
	if (enemy->attack != NULL)
	{
		if (enemy->attack->image != NULL)
			enemy->attack->image->enabled = false ;
		free(enemy->attack);
	}
	free(enemy);
}

void	free_enemies(t_enemy **enemies)
{
	t_enemy	*next ;

	while (*enemies)
	{
		next = (*enemies)->next ;
		free_enemy(*enemies);
		(*enemies) = next ;
	}
	(*enemies) = NULL ;
}
