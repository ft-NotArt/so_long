/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_kill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 05:50:50 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/16 06:29:12 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_doo_attack_east(t_game *game, t_attack *attack)
{
	if (attack->frame == FRAME1
		&& game->maps->player->x == attack->x
		&& game->maps->player->y == attack->y - 1)
		(ft_putstr_fd("Game Over !\n", STDOUT_FILENO), close_game(game));
	else if (attack->frame == FRAME2
		&& game->maps->player->x == attack->x + 1
		&& game->maps->player->y == attack->y)
		(ft_putstr_fd("Game Over !\n", STDOUT_FILENO), close_game(game));
	else if (attack->frame == FRAME3
		&& game->maps->player->x == attack->x
		&& game->maps->player->y == attack->y + 1)
			(ft_putstr_fd("Game Over !\n", STDOUT_FILENO), close_game(game));
}

static void	check_doo_attack_south(t_game *game, t_attack *attack)
{
	if (attack->frame == FRAME1
		&& game->maps->player->x == attack->x + 1
		&& game->maps->player->y == attack->y)
		(ft_putstr_fd("Game Over !\n", STDOUT_FILENO), close_game(game));
	else if (attack->frame == FRAME2
		&& game->maps->player->x == attack->x
		&& game->maps->player->y == attack->y + 1)
		(ft_putstr_fd("Game Over !\n", STDOUT_FILENO), close_game(game));
	else if (attack->frame == FRAME3
		&& game->maps->player->x == attack->x - 1
		&& game->maps->player->y == attack->y)
			(ft_putstr_fd("Game Over !\n", STDOUT_FILENO), close_game(game));
}

static void	check_doo_attack_west(t_game *game, t_attack *attack)
{
	if (attack->frame == FRAME1
		&& game->maps->player->x == attack->x
		&& game->maps->player->y == attack->y + 1)
		(ft_putstr_fd("Game Over !\n", STDOUT_FILENO), close_game(game));
	else if (attack->frame == FRAME2
		&& game->maps->player->x == attack->x - 1
		&& game->maps->player->y == attack->y)
		(ft_putstr_fd("Game Over !\n", STDOUT_FILENO), close_game(game));
	else if (attack->frame == FRAME3
		&& game->maps->player->x == attack->x
		&& game->maps->player->y == attack->y - 1)
			(ft_putstr_fd("Game Over !\n", STDOUT_FILENO), close_game(game));
}

static void	check_doo_attack_north(t_game *game, t_attack *attack)
{
	if (attack->frame == FRAME1
		&& game->maps->player->x == attack->x - 1
		&& game->maps->player->y == attack->y)
		(ft_putstr_fd("Game Over !\n", STDOUT_FILENO), close_game(game));
	else if (attack->frame == FRAME2
		&& game->maps->player->x == attack->x
		&& game->maps->player->y == attack->y - 1)
		(ft_putstr_fd("Game Over !\n", STDOUT_FILENO), close_game(game));
	else if (attack->frame == FRAME3
		&& game->maps->player->x == attack->x + 1
		&& game->maps->player->y == attack->y)
			(ft_putstr_fd("Game Over !\n", STDOUT_FILENO), close_game(game));
}

void	check_attack(t_game *game, t_attack *attack)
{
	if (attack->type == DEE)
	{
		if (attack->x == game->maps->player->x
			&& attack->y == game->maps->player->y)
			(ft_putstr_fd("Game Over !\n", STDOUT_FILENO), close_game(game));
	}
	else
	{
		if (attack->x == game->maps->player->x
			&& attack->y == game->maps->player->y)
		{
			(ft_putstr_fd("Game Over !\n", STDOUT_FILENO), close_game(game));
		}
		if (attack->orient == EAST)
			check_doo_attack_east(game, attack);
		if (attack->orient == SOUTH)
			check_doo_attack_south(game, attack);
		if (attack->orient == WEST)
			check_doo_attack_west(game, attack);
		if (attack->orient == NORTH)
			check_doo_attack_north(game, attack);
	}
}
