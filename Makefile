# #-----------------------Flags_and_Name---------------------
# NAME    =    cub3D
# CC        =    cc
# CFLAGS    =    -Wall -Wextra -Werror -Iinclude -g
# CREAD    =    -lreadline -lncursesw
# LIB            =    lib
# LIBFT        =    $(LIB)/libft.a
# MLX            =    MLX42
# LIBMLX     =    $(MLX)/build/libmlx42.a

# #------------------------Source-----------------------------

# # Sources and objects
# FILES = main \

# SRCS = $(addprefix src/, $(addsuffix .c, $(FILES)))
# OBJS = $(addprefix obj/, $(addsuffix .o, $(FILES)))

# #------------------------Colors-----------------------------

# define generate_random_color
# python3 -c "import random; \
# print(''.join(['\033[38;5;' + str(random.randint(16, 255)) + 'm' + c + '\033[0m' for c in '$(1)']))"
# endef

# #------------------------Rules------------------------------
# #VALGRIND_SUPP = valgrind.supp

# all: $(LIBFT) $(LIBMLX) $(NAME)

# obj:
#     mkdir -p obj

# $(LIBFT):
#     @$(MAKE) --quiet -C $(LIB)
#     @echo "Libft compilée."

# $(LIBMLX):
#     @if [ ! -d "$(MLX)" ]; then \
#         echo "Clonage de MLX42 library..."; \
#         git clone https://github.com/codam-coding-college/MLX42.git $(MLX); \
#     fi
#     @echo "Compilation de MLX42 library..."
#     @cmake -S $(MLX) -B $(MLX)/build
#     @cmake --build $(MLX)/build

# .c.o:
#     $(CC) $(CFLAGS) -c $< -o $<:.c=.o) $(CREAD) $(LIBS)

# $(NAME): obj ${OBJS}
#     @$(call generate_random_color, $(CC) $(CFLAGS) -o $@ $(OBJS))
#     @$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(CREAD) $(LIBS)


# clean:
#     @$(MAKE) --quiet -C $(LIB) clean
#     rm -f ${OBJS}

# fclean: clean
#     @$(MAKE) --quiet -C $(LIB) fclean
#     rm -f ${NAME}
#     rm -rf obj
#     rm -rf $(MLX)/build





# COLORS

define generate_random_color
python3 -c "import random; \
print(''.join(['\033[38;5;' + str(random.randint(16, 255)) + 'm' + c + '\033[0m' for c in '$(1)']))"
endef

PINK			=	\x1b[0m\x1b[38;2;247;115;171m
LIGHT_PINK		=	\x1b[0m\x1b[38;2;249;157;196m
DARK_PINK		=	\x1b[1m\x1b[38;2;198;92;137m

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
					-Iinc -Ilibft -Ilibft/printf -Ilibft/gnl -IMLX42/include	\

LFLAGS			=	-ldl -lglfw -lm												\

# FILES

FILES			=	so_long														\
\
\
					pars/pars													\
\
\
					map/map														\
					map/map_pars												\
					map/flood_fill												\
					map/map_extend												\
\
\
					init/init													\
\
\
					game/game													\
\
					game/display/display										\
\
					game/display/entities/tiles_entities						\
					game/display/entities/tiles_player							\
					game/display/entities/tiles_enemy							\
\
					game/display/background/tiles_background					\
\
					game/display/panel/display_panel							\
					game/display/panel/tiles_panel								\
					game/display/panel/tiles_sign								\
					game/display/panel/tiles_boxes								\
\
					game/entities/move											\
					game/entities/check											\
\
					game/entities/player/player									\
					game/entities/player/status									\
\
					game/entities/enemy/lst_enemies								\
					game/entities/enemy/enemy									\
\
					game/hooks/hooks											\
\
\
					exit/exit													\
					exit/free													\
					exit/error													\
\
\
\
\
					game/entities/enemy/attack/check_range						\
					game/entities/enemy/attack/check_enemy_kill					\
					game/entities/player/attack/player_attack					\
\
					game/entities/player/attack/check_player_kill				\
\
					game/display/attack/tiles_attack_display					\
					game/display/attack/tiles_attack_get						\
					game/display/attack/tiles_attack_update						\
\

SRC				=	$(addprefix src/, $(addsuffix .c, $(FILES)))
OBJ				=	$(addprefix src/, $(addsuffix .o, $(FILES)))

# RULES

all				:	$(LIBFT_PATH) $(LIBMLX) $(NAME)

$(LIBFT_PATH)	:
					$(MAKE) -C $(LIBFT_DIR) $(LIBFT) -j $$(nproc)

$(LIBMLX)		:
					if [ ! -d "$(MLX)" ]; then	\
						git clone https://github.com/codam-coding-college/MLX42.git $(MLX);	\
						cd $(MLX);	\
						git reset --hard 7f95e70415705dcc723f94a2696aba84ed3756ad;	\
						cd ..;	\
					fi
					echo -e 'Compilation de MLX42 library...'
					cmake -S $(MLX) -B $(MLX)/build
					cmake --build $(MLX)/build

$(NAME)			:	$(OBJ)
					$(CC) $(CFLAGS) $(LFLAGS) $^ $(LIBFT_PATH) $(LIBMLX) -o $@
					echo -e '$(LIGHT_PINK) \tCompiled$(DARK_PINK) $@'

clean			:
					$(RM) $(OBJ)
					$(MAKE) -C $(LIBFT_DIR) f$@
					echo -e '$(LIGHT_PINK) \tCleaned$(PINK) $(OBJ)'

fclean			:	clean
					$(RM) $(NAME)
					$(RM) -r $(MLX)/build
					echo -e '$(LIGHT_PINK) \tCleaned$(DARK_PINK) $(NAME)'

re				:	fclean all

.PHONY			=	all clean fclean re
