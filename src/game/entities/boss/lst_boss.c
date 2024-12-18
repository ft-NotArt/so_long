/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_boss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 05:46:22 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/18 15:08:16 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_boss	*boss_last(t_boss *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	boss_add_back(t_boss **lst, t_boss *new)
{
	if (!lst)
		return ;
	if (!*lst)
		*lst = new ;
	else
		boss_last(*lst)->next = new ;
}

t_boss	*get_boss(t_boss *boss, int y, int x)
{
	while (boss)
	{
		if (boss->y == y && boss->x == x)
			return (boss);
		boss = boss->next ;
	}
	return (NULL);
}

void	del_boss(t_game *game, t_boss **boss, int y, int x)
{
	t_boss	*cur ;
	t_boss	*nxt ;

	cur = *boss ;
	if (cur->y == y && cur->x == x)
	{
		*boss = cur->next ;
		game->maps->map[y][x] = '0' ;
		game->maps->enemy_number-- ;
		return (mlx_delete_image(game->mlx, cur->image), free_enemy(cur));
	}
	nxt = cur->next ;
	while (cur)
	{
		if (nxt->y == y && nxt->x == x)
		{
			cur->next = nxt->next ;
			game->maps->map[y][x] = '0' ;
			game->maps->enemy_number-- ;
			return (mlx_delete_image(game->mlx, nxt->image), free_boss(nxt));
		}
		cur = nxt ;
		nxt = cur->next ;
	}
}
