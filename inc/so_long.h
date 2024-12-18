/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:19:52 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/18 06:10:44 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <MLX42/MLX42.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include <stdbool.h>

# include "libft.h"
# include "get_next_line.h"

# define BITS 32

# define MIN_WIDTH 7

# define LEVEL			"Level "

# define WATER			"textures/ground/water.png"
# define STAR			"textures/ground/star.png"

# define GRASS			"textures/ground/grass/"
# define GROUND			"ground"
# define DECO			"deco/deco_"

# define PANEL			"textures/panel/panel_"
# define CORNER			"corner_"
# define BORDER			"border_"

# define BOX			"textures/panel/box_power_"
# define POWER			"textures/panel/power_"
# define SIGN			"textures/panel/sign"

# define PLAYER			"textures/player/"

# ifndef PLAYER_TYPE
#  define PLAYER_TYPE	"kirby/kirby_"
# endif

# define P_STANDING		"standing_"
# define P_WALKING_1	"walking_1_"
# define P_WALKING_2	"walking_2_"
# define P_SWALLOWING	"swallowing_"

# define WADDLE_DOO		"textures/enemies/waddle_doo/waddle_doo_"
# define WADDLE_DEE		"textures/enemies/waddle_dee/waddle_dee_"

# define ATTACKS		"textures/attacks/"

# define SWALLOW		"swallowing"
# define KNIFE			"knife"
# define MAGIC_BEAM		"magic_beam"

# define RIGHT			"right"
# define FRONT			"front"
# define LEFT			"left"
# define BACK			"back"

# define TOP			"top"
# define BOT			"bot"

# define TRANSITION		"textures/transition/kirby_on_warpstar"

# define PNG			".png"

typedef enum orientation
{
	EAST,
	SOUTH,
	WEST,
	NORTH
}			t_orient;

typedef enum position
{
	STANDING,
	WALKING1,
	WALKING2,
	SWALLOWING,
	ATTACKING
}			t_pos;

typedef enum attack_frame
{
	FRAME1 = 1,
	FRAME2 = 2,
	FRAME3 = 3
}			t_att_frame;

typedef enum enemy_type
{
	DEE = 'C',
	DOO = 'D'
}			t_ype;

typedef struct s_game
{
	mlx_t			*mlx ;
	struct s_map	*maps ;
	bool			player_attack_set[3];
	mlx_image_t		*player_attack_set_img[3];
	double			time_from_transition ;
}			t_game;

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
}			t_map;

typedef struct s_player
{
	mlx_image_t		*image ;
	int				x ;
	int				y ;
	t_orient		orient ;
	t_pos			status ;
	int				step_count ;
	struct s_attack	*attack ;
	double			last_action_time ;
}			t_player;

typedef struct s_enemy
{
	mlx_image_t		*image ;
	t_ype			type ;
	int				x ;
	int				y ;
	t_orient		orient ;
	bool			attack_set[3];
	struct s_attack	*attack ;
	struct s_enemy	*next ;
}			t_enemy;

typedef struct s_attack
{
	mlx_image_t	*image ;
	t_att_frame	frame ;
	t_ype		type ;
	int			x ;
	int			y ;
	t_orient	orient ;
}			t_attack;

//	('') Pars ('')

bool		check_ber(int argc, char *argv[]);
bool		pars_map(t_map *map);
bool		check_flood_fill(t_map *map);

//	('') Init ('')

t_map		*maps_init(int argc, char *argv[]);
t_map		*map_init(char *map_file);
void		map_extend(t_map *map);
char		**read_map(char *map_file);
t_game		*game_init(t_map *maps);
t_enemy		*enemy_init(t_map *map, int x, int y);
void		enemy_set_attacks(t_enemy *enemy, t_map *map, int x, int y);
t_attack	*attack_init(t_ype type, int x, int y, t_orient orient);
void		set_attack_coord(t_attack *attack, int x, int y);

//	('') Game ('')

void		game_loop(t_game *game);
void		frame_hook(void *param);
void		keyboard_hook(mlx_key_data_t key_data, void *param);
void		game_over(t_game *game);
void		start_transition(t_game *game);
void		end_transition(t_game *game);

//	('') Player & Enemy ('')

void		get_input_dir(keys_t key_press, t_game *game);
int			alternate_walking(int current_pose);
void		player_swallow(t_game *game, t_map *maps,
				char **map, t_player *player);
void		player_knife(t_game *game, t_player *player);
void		player_magic_beam(t_game *game, t_player *player);
void		update_player_attack(t_game *game, t_player *player);
void		check_player_attack(t_game *game, t_player *player);

void		enemy_turn(t_game *game, t_enemy *enemy);
bool		player_in_range(t_map *map, t_enemy *enemy);
void		check_enemy_attack(t_game *game, t_enemy *enemy);
t_enemy		*enemy_last(t_enemy *lst);
void		enemy_add_back(t_enemy **lst, t_enemy *new);
t_enemy		*get_enemy(t_enemy *enemy, int y, int x);
void		del_enemy(t_game *game, t_enemy **enemy, int y, int x);

void		check_player_mov(t_game *game, int y, int x);
void		check_enemy_mov(t_game *game, int y, int x);
bool		is_enemy(char c);
void		move_east(t_game *game, t_player *player, t_enemy *enemy);
void		move_south(t_game *game, t_player *player, t_enemy *enemy);
void		move_west(t_game *game, t_player *player, t_enemy *enemy);
void		move_north(t_game *game, t_player *player, t_enemy *enemy);

//	('') Display ('')

mlx_image_t	*get_mlx_img(t_game *game, char *sprite_file);

void		display_full_map(t_game *game);
void		display_tile(t_game *game, int x, int y);
void		display_water(t_game *game, int x, int y);
void		display_ground(t_game *game, int x, int y);
void		display_star(t_game *game, int x, int y);

void		display_player(t_game *game, int x, int y);
void		update_player_sprite(t_game *game, t_player *player);
void		display_enemy(t_game *game, int x, int y);
void		update_enemy_sprite(t_game *game, t_enemy *enemy);
void		add_orient(t_orient orient, char *sprite_file);

void		display_attack(t_game *game, t_attack *attack);
mlx_image_t	*get_mlx_attack(t_game *game, t_attack *attack);
void		update_attack_sprite(t_game *game, t_attack *attack);

void		display_panel(t_game *game);
mlx_image_t	*get_mlx_panel(t_game *game, size_t x, size_t y);
void		display_inside_panel(t_game *game);
void		display_boxes(t_game *game);
void		display_powers(t_game *game);
void		display_sign(t_game *game);
void		init_step_count(t_game *game);
void		update_step_count(t_game *game);

void		display_transition(t_game *game);

//	('') Free ('')

void		free_game(t_game *game);
void		free_maps(t_map *maps);
void		free_map(t_map *map);
void		free_enemies(t_enemy **enemies);
void		free_enemy(t_enemy *enemy);

//	('') Error ('')

void		error_arguments(void);
void		error_map(void);
void		error_mlx(void);

//	('') Close ('')

void		close_game(t_game *game);
void		close_success(void *param);
void		close_failure(void *param);

#endif