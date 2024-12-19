/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_boss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 05:46:22 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/19 06:51:04 by anoteris         ###   ########.fr       */
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

static void	del_boss_ext(t_game *game, t_boss *to_delete, int y, int x)
{
	game->maps->map[y][x] = '0' ;
	game->maps->enemy_number-- ;
	mlx_delete_image(game->mlx, to_delete->image);
	free_boss(to_delete);
}

void	del_boss(t_game *game, t_boss **boss, int y, int x)
{
	t_boss	*cur ;
	t_boss	*nxt ;

	if (!(*boss))
		return ;
	cur = *boss ;
	if (cur->y == y && cur->x == x)
	{
		*boss = cur->next ;
		return (del_boss_ext(game, cur, y, x));
	}
	nxt = cur->next ;
	while (nxt)
	{
		if (nxt->y == y && nxt->x == x)
		{
			cur->next = nxt->next ;
			return (del_boss_ext(game, nxt, y, x));
		}
		cur = nxt ;
		nxt = cur->next ;
	}
}
