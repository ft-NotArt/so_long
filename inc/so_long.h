/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:19:52 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/05 03:58:31 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <MLX42/MLX42.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <stdbool.h>

# include "ft_printf.h"
# include "get_next_line.h"

typedef struct s_map
{
	char			**map ;
	int				P ;
	int				C ;
	int				E ;
	struct s_map	*next ;
}			t_map ;

void	error_arguments();
void	error_map();

void	free_maps(t_map *maps);

bool	pars_map(t_map *map);
bool	map_has_empty_line(char *map_in_line);

bool	check_ber(int argc, char *argv[]);

t_map	*maps_init(int argc, char *argv[]);

#endif