/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:19:35 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/10 04:47:55 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_map	*maps ;

	if (argc < 2 || !check_ber(argc, argv))
		return (error_arguments(), EXIT_FAILURE);
	maps = maps_init(argc, argv);
	if (!maps)
		return (error_map(), EXIT_FAILURE);

	t_map	*current_map = maps;
	while (current_map)
	{
		for (size_t i = 0; current_map->map && current_map->map[i]; i++)
		{
			ft_printf("%s\n", current_map->map[i]);
		}
		ft_printf("\n");

		t_list	*current_enemy = current_map->enemies;
		while (current_enemy)
		{
			t_enemy	*enemy = current_enemy->content ;
			ft_printf("\n--Enemy--\n\tx=%d y=%d\n\torient=%d\n", enemy->x, enemy->y, enemy->orient);
			current_enemy = current_enemy->next ;
		}
		

		current_map = current_map->next ;
	}

	game_loop(maps);
	// * pars
	// * game
	// * exit

	// free_maps(maps);
}
