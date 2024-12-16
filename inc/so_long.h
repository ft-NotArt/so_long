/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:19:52 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/16 09:26:48 by anoteris         ###   ########.fr       */
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

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

# define BITS 32

# define MIN_WIDTH 7

# define WATER			"textures/ground/water.png"

# define STAR			"textures/ground/star.png"

# define GRASS			"textures/ground/grass/"

# define GROUND			"ground"

# define DECO			"deco/deco_"

# define PANEL			"textures/panel/panel_"

# define CORNER			"corner_"
# define BORDER			"border_"

# define BOX			"textures/panel/box_power_"

# define SIGN			"textures/panel/sign"

# define KIRBY			"textures/kirby/"

# define K_STANDING		"standing/kirby_standing_"
# define K_WALKING_1	"walking/kirby_walking_1_"
# define K_WALKING_2	"walking/kirby_walking_2_"
# define K_SWALLOWING	"swallowing/kirby_swallowing_"

# define WADDLE_DOO		"textures/enemies/waddle_doo/waddle_doo_"

# define WADDLE_DEE		"textures/enemies/waddle_dee/waddle_dee_"

# define ATTACKS		"textures/attacks/"

# define KNIFE			"knife_"
# define MAGIC_BEAM		"magic_beam_"

# define RIGHT			"right"
# define FRONT			"front"
# define LEFT			"left"
# define BACK			"back"

# define TOP			"top"
# define BOT			"bot"

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
	SWALLOWING,
	ATTACKING
}			pos ;

typedef enum attack_frame
{
	FRAME1 = 1,
	FRAME2 = 2,
	FRAME3 = 3
}			att_frame ;

typedef enum enemy_type
{
	DEE = 'C',
	DOO = 'D'
}			type ;

typedef struct s_game
{
	mlx_t			*mlx ;
	struct s_map	*maps ;
	bool			player_attack_set[3];
}			t_game ;

typedef struct s_map
{
	char			**map ;
	size_t			width ;
	size_t			height ;
	int				enemy_number ;
	struct s_player	*player ;
	mlx_image_t		*step_count_img ;
	struct s_enemy	*enemies ;
	struct s_map	*next ;
}			t_map ;

typedef struct s_player
{
	mlx_image_t		*image ;
	int 			x ;
	int 			y ;
	orient			orient ;
	pos				status ;
	int				step_count ;
	struct s_attack	*attack ;
	double			last_action_time ;
}			t_player ;

typedef struct s_enemy
{
	mlx_image_t		*image ;
	type			type ;
	int 			x ;
	int 			y ;
	orient			orient ;
	bool			attack_set[3];
	struct s_attack	*attack ;
	struct s_enemy	*next ;
}			t_enemy ;

typedef struct s_attack
{
	mlx_image_t	*image ;
	att_frame	frame ;
	type		type ;
	int			x ;
	int			y ;
	orient		orient ;
}			t_attack ;

void	error_arguments();
void	error_map();
void	error_mlx();

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

mlx_image_t	*get_mlx_img(t_game *game, char *sprite_file);
mlx_image_t	*get_mlx_panel(t_game *game, size_t x, size_t y);

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

t_enemy	*enemy_last(t_enemy *lst);
void	enemy_add_back(t_enemy **lst, t_enemy *new);
void	enemy_del_coord(t_game *game, t_enemy **enemy, int y, int x);

void	check_player_tile(t_game *game, int y, int x);
void	check_enemy_tile(t_game *game, int y, int x);
bool	is_enemy(char c);

void	player_attack(t_game *game, t_player *player);

void	enemy_turn(t_game *game, t_enemy *enemy);

void	display_panel(t_game *game);

void	display_water(t_game *game, int x, int y);
void	display_star(t_game *game, int x, int y);

void	map_extend(t_map *map);

void	display_inside_panel(t_game *game);

void	update_step_count(t_game *game);

void	display_enemy(t_game *game, int x, int y);
void	display_player(t_game *game, int x, int y);
void	display_ground(t_game *game, int x, int y);
void	init_step_count(t_game *game);
void	display_boxes(t_game *game);
void	display_sign(t_game *game);

void	add_orient(orient orient, char *sprite_file);

bool	player_in_range(t_map *map, t_enemy *enemy);

mlx_image_t	*get_mlx_attack(t_game *game, t_attack *attack);
void	display_attack(t_game *game, t_attack *attack);
void	update_attack_sprite(t_game *game, t_attack *attack);

t_attack	*attack_init(type type, int x, int y, orient orient);
void	enemy_attack(t_game *game, t_enemy *enemy);
void	check_attack(t_game *game, t_enemy *enemy);

void	free_enemy(t_enemy *enemy);

void	game_over(t_game *game, t_enemy *enemy);

#endif