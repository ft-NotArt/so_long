/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:19:35 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/10 05:58:26 by anoteris         ###   ########.fr       */
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

		current_map = current_map->next ;
	}

	game_loop(maps);

	// * pars
	// * game
	// * exit

	// free_maps(maps);
}
