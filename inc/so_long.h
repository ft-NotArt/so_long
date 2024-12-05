/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:19:52 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/05 08:16:22 by anoteris         ###   ########.fr       */
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

# define WATER		"textures/ground/water.png"
# define KIRBY		"textures/kirby/standing/kirby_standing_right.png"
# define GRASS		"textures/ground/grass/ground"
# define GRASS_BASE	"textures/ground/grass/ground00000000.png"
# define PNG		".png"

# define IMG_WIN mlx_image_to_window

// typedef enum orientation
// {
// 	EAS,
// 	SOU,
// 	WES,
// 	NOR
// } ;

typedef struct s_game
{
	mlx_t	*mlx ;
	struct s_map	*maps ;
}			t_game ;

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

bool	check_flood_fill(t_map *map);

bool	pars_map(t_map *map);

bool	check_ber(int argc, char *argv[]);

t_map	*maps_init(int argc, char *argv[]);

void	game_init(t_map *maps);

#endif