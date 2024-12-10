/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_enemies.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 05:46:22 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/10 08:48:52 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_enemy	*enemy_last(t_enemy *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	enemy_add_back(t_enemy **lst, t_enemy *new)
{
	if (!lst)
		return ;
	if (!*lst)
		*lst = new ;
	else
		enemy_last(*lst)->next = new ;
}

void	enemy_del_coord(t_game *game, t_enemy **enemy, int y, int x)
{
	t_enemy	*current ;
	t_enemy	*next ;

	current = *enemy ;
	if (current->y == y && current->x == x)
	{
		*enemy = current->next ;
		game->maps->map[y][x] = '0' ;
		game->maps->enemy_number-- ;
		return (mlx_delete_image(game->mlx, current->image), free(current));
	}
	next = current->next ;
	while (current)
	{
		if (next->y == y && next->x == x)
		{
			current->next = next->next ;
			game->maps->map[y][x] = '0' ;
			game->maps->enemy_number-- ;
			return (mlx_delete_image(game->mlx, next->image), free(next));
		}
		current = next ;
		next = current->next ;
	}
}
