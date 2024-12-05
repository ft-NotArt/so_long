/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:19:35 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/05 06:54:06 by anoteris         ###   ########.fr       */
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
		return (EXIT_FAILURE);

	t_map	*current = maps;
	while (current)
	{
		for (size_t i = 0; current->map && current->map[i]; i++)
		{
			ft_printf("%s\n", current->map[i]);
		}
		ft_printf("\n");
		current = current->next ;
	}

	game_init(maps);
	// * pars
	// * game
	// * exit

	// free_maps(maps);
}
