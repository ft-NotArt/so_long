/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:19:52 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/10 16:39:01 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <MLX42/MLX42.h>
# include <math.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <stdbool.h>

# include "ft_printf.h"
# include "get_next_line.h"

# define BITS 32

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

# define ENEMY_EX		"textures/enemies/waddle_doo/waddle_doo_rght.png"

# define WADDLE_DOO		"textures/enemies/waddle_doo/waddle_doo_"

# define WADDLE_DEE		"textures/enemies/waddle_dee/waddle_dee_"

# define RIGHT			"rght"
# define FRONT			"frnt"
# define LEFT			"left"
# define BACK			"back"

# define PNG			".png"

# define PLAYER			game->maps->player, NULL
# define ENEMY			NULL, enemy

// TODO: is it possible despite the norm to rm ?
# define IMG_WIN mlx_image_to_window

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
	WALKING2,
	SWALLOWING
}			pos ;

typedef enum type
{
	DEE = 'C',
	DOO = 'D'
}			type ;

typedef struct s_game
{
	mlx_t			*mlx ;
	struct s_map	*maps ;
}			t_game ;

typedef struct s_map
{
	char			**map ;
	size_t			width ;
	size_t			height ;
	int				enemy_number ;
	struct s_player	*player ;
	struct s_enemy	*enemies ;
	struct s_map	*next ;
}			t_map ;

typedef struct s_player
{
	mlx_image_t	*image ;
	int 		x ;
	int 		y ;
	int			orient ;
	int			pose ;
	double		last_action_time ;
}			t_player ;

typedef struct s_enemy
{
	mlx_image_t		*image ;
	char			type ;
	int 			x ;
	int 			y ;
	int				orient ;
	double			last_action_time ;
	struct s_enemy	*next ;
}			t_enemy ;

void	error_arguments();
void	error_map();

void	free_maps(t_map *maps);
void	free_game(t_game *game);

bool	check_flood_fill(t_map *map);

bool	pars_map(t_map *map);

bool	check_ber(int argc, char *argv[]);

t_map	*maps_init(int argc, char *argv[]);
char	**read_map(char *map_file);

t_game	*game_init(t_map *maps);
t_map	*map_init(char *map_file);

void	game_loop(t_map *maps);

void	display_full_map(t_game *game);
void	display_tile(t_game *game, int x, int y);

mlx_image_t	*get_mlx_ground(t_game *game, int x, int y);
mlx_image_t	*get_mlx_img(t_game *game, char *sprite_file);
mlx_image_t	*get_mlx_player(t_game *game);

void	get_input_dir(keys_t key_press, t_game *game);

void	update_player_sprite(t_game *game, t_player *player);
void	update_enemy_sprite(t_game *game, t_enemy *enemy);

void	keyboard_hook(mlx_key_data_t key_data, void *param);
void	close_game(void *param);

int		alternate_walking(int current_pose);

void	move_east(t_game *game, t_player *player, t_enemy *enemy);
void	move_south(t_game *game, t_player *player, t_enemy *enemy);
void	move_west(t_game *game, t_player *player, t_enemy *enemy);
void	move_north(t_game *game, t_player *player, t_enemy *enemy);

void	frame_hook(void *param);

t_enemy	*enemy_init(t_map *map, int x, int y);

mlx_image_t	*get_mlx_enemy(t_game *game, t_enemy *enemy);

t_enemy	*enemy_last(t_enemy *lst);
void	enemy_add_back(t_enemy **lst, t_enemy *new);
void	enemy_del_coord(t_game *game, t_enemy **enemy, int y, int x);

void	check_player_tile(t_game *game, int y, int x);
void	check_enemy_tile(t_game *game, int y, int x);
bool	is_enemy(char c);

void	player_attack(t_game *game, t_player *player);

void	enemy_turn(t_game *game, t_enemy *enemy);

#endif