/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:19:52 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/05 17:05:10 by anoteris         ###   ########.fr       */
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

# define WATER			"textures/ground/water.png"

# define STAR			"textures/ground/star.png"

# define GRASS_EX		"textures/ground/grass/ground00000000.png"

# define GRASS			"textures/ground/grass/ground"

# define KIRBY_EX		"textures/kirby/standing/kirby_standing_rght.png"

# define KIRBY			"textures/kirby/"

# define K_STANDIN		"standing/kirby_standing_"
# define K_WALKIN_1		"walking/kirby_walking_1_"
# define K_WALKIN_2		"walking/kirby_walking_2_"
# define K_SWALLOWIN	"swallowin/kirby_swallow_"

# define RIGHT			"rght"
# define FRONT			"frnt"
# define LEFT			"left"
# define BACK			"back"

# define PNG			".png"

# define IMG_WIN mlx_image_to_window

typedef struct s_game
{
	mlx_t			*mlx ;
	struct s_map	*maps ;
}			t_game ;

typedef struct s_map
{
	char			**map ;
	struct s_player	*player ;
	int				C ;
	struct s_map	*next ;
}			t_map ;

typedef enum orientation
{
	EAST,
	SOUTH,
	WEST,
	NORTH
}			orient ;

typedef enum position
{
	STANDING,
	WALKING1,
	WALKING2
}			pos ;

typedef struct s_player
{
	int x ;
	int y ;
	int	orient ;
	int	pose ;
}			t_player ;

void	error_arguments();
void	error_map();

void	free_maps(t_map *maps);

bool	check_flood_fill(t_map *map);

bool	pars_map(t_map *map);

bool	check_ber(int argc, char *argv[]);

t_map	*maps_init(int argc, char *argv[]);

void	game_loop(t_map *maps);

void	display_full_map(t_game *game);
void	display_tile(t_game *game, int x, int y);

mlx_image_t	*get_mlx_ground(t_game *game, int x, int y);
mlx_image_t	*get_mlx_img(t_game *game, char *sprite_file);
mlx_image_t	*get_mlx_player(t_game *game);

void	get_input_dir(keys_t key_press, t_game *game);

#endif