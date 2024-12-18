/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:19:35 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/18 07:13:40 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game	*game ;
	t_map	*maps ;

	if (argc < 2 || argc > 6 || !check_ber(argc, argv))
		return (error_arguments(), EXIT_FAILURE);
	maps = maps_init(argc, argv);
	if (!maps)
		return (error_map(), EXIT_FAILURE);
	game = game_init(maps);
	if (!game->mlx)
	{
		free_game(game);
		return (error_mlx(), EXIT_FAILURE);
	}
	game_loop(game);
}
