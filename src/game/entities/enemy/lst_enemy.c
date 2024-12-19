/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_enemy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 05:46:22 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/19 06:45:36 by anoteris         ###   ########.fr       */
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

t_enemy	*get_enemy(t_enemy *enemy, int y, int x)
{
	while (enemy)
	{
		if (enemy->y == y && enemy->x == x)
			return (enemy);
		enemy = enemy->next ;
	}
	return (NULL);
}

static void	del_enemy_ext(t_game *game, t_enemy *to_delete, int y, int x)
{
	game->maps->map[y][x] = '0' ;
	game->maps->enemy_number-- ;
	mlx_delete_image(game->mlx, to_delete->image);
	free_enemy(to_delete);
}

void	del_enemy(t_game *game, t_enemy **enemy, int y, int x)
{
	t_enemy	*cur ;
	t_enemy	*nxt ;

	if (!(*enemy))
		return ;
	cur = *enemy ;
	if (cur->y == y && cur->x == x)
	{
		*enemy = cur->next ;
		return (del_enemy_ext(game, cur, y, x));
	}
	nxt = cur->next ;
	while (nxt)
	{
		if (nxt->y == y && nxt->x == x)
		{
			cur->next = nxt->next ;
			return (del_enemy_ext(game, nxt, y, x));
		}
		cur = nxt ;
		nxt = cur->next ;
	}
}
