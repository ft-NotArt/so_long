# COLORS

PINK			=	\x1b[0m\x1b[38;2;247;115;171m
LIGHT_PINK		=	\x1b[0m\x1b[38;2;249;157;196m
DARK_PINK		=	\x1b[1m\x1b[38;2;198;92;137m
WHITE			=	\x1b[0m\x1b[38;2;255;255;255m

# TARGET

NAME			=	so_long

LIBFT			=	libft.a
LIBFT_DIR		=	libft
LIBFT_PATH		=	$(LIBFT_DIR)/$(LIBFT)

MLX				=	MLX42
LIBMLX 			=	$(MLX)/build/libmlx42.a

# FLAGS

MAKEFLAGS		+=	-s
CFLAGS			=	-Wall -Werror -Wextra -g -pthread							\
					-Iinc -Ilibft -Ilibft/gnl -IMLX42/include					\

LFLAGS			=	-ldl -lglfw -lm												\

# FILES

FILES			=	so_long														\
\
\
					pars/pars													\
\
\
					map/map map/map_pars map/map_extend map/flood_fill			\
\
\
					init/init init/init_entities init/init_setter				\
\
\
					game/game													\
\
					game/hooks/hooks											\
\
					game/entities/move											\
					game/entities/check											\
\
					game/entities/player/player									\
					game/entities/player/status									\
					game/entities/player/attack/player_kill						\
					game/entities/player/attack/player_attack					\
					game/entities/player/attack/check_player_attack				\
\
					game/entities/enemy/enemy									\
					game/entities/enemy/lst_enemy								\
					game/entities/enemy/attack/check_enemy_range				\
					game/entities/enemy/attack/check_enemy_attack				\
\
					game/entities/boss/boss										\
					game/entities/boss/lst_boss									\
					game/entities/boss/attack/check_boss_attack					\
\
					game/display/display										\
\
					game/display/transition/display_transition					\
\
					game/display/panel/display_panel							\
					game/display/panel/tiles_panel								\
					game/display/panel/tiles_boxes								\
					game/display/panel/tiles_sign								\
\
					game/display/entities/tiles_player							\
					game/display/entities/tiles_enemy							\
					game/display/entities/tiles_boss							\
					game/display/entities/tiles_entities						\
\
					game/display/background/tiles_background					\
\
					game/display/attack/tiles_attack_display					\
					game/display/attack/tiles_attack_get						\
					game/display/attack/tiles_attack_update						\
\
\
					exit/exit exit/free_game exit/free_entities exit/error		\
\

SRC				=	$(addprefix src/, $(addsuffix .c, $(FILES)))
OBJ				=	$(addprefix src/, $(addsuffix .o, $(FILES)))

# RULES

all				:	$(NAME)

$(LIBFT_PATH)	:
					$(MAKE) -C $(LIBFT_DIR) $(LIBFT) -j $$(nproc)

$(LIBMLX)		:
					if [ ! -d "$(MLX)" ]; then	\
						echo "\nClone of MLX42 library...";	\
						git clone https://github.com/codam-coding-college/MLX42.git $(MLX);	\
					fi
					echo "\nCompilation of MLX42 library..."
					cmake -S $(MLX) -B $(MLX)/build
					cmake --build $(MLX)/build

$(NAME)			:	$(LIBMLX) $(LIBFT_PATH) $(OBJ)
					$(CC) $(LFLAGS) $(OBJ) $(LIBFT_PATH) $(LIBMLX) -o $@
					echo -e '$(LIGHT_PINK) \tCompiled$(DARK_PINK) $@$(WHITE)'

hard			:	CFLAGS += -D PLAYER_TYPE='"yoshi/yoshi_"'
hard			:	$(NAME)

clean			:
					$(RM) $(OBJ)
					$(MAKE) -C $(LIBFT_DIR) f$@
					echo -e '$(LIGHT_PINK) \tCleaned$(PINK) $(OBJ)$(WHITE)'

fclean			:	clean
					$(RM) $(NAME)
					$(RM) -r $(MLX)/build
					echo -e '$(LIGHT_PINK) \tCleaned$(DARK_PINK) $(NAME)$(WHITE)'

re				:	fclean all

.PHONY			=	all hard clean fclean re
