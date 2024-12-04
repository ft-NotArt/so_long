# COLORS

GREEN			=	\x1b[0m\x1b[38;2;73;190;37m
LIGHT_GREEN		=	\x1b[0m\x1b[38;2;182;229;168m
DARK_GREEN		=	\x1b[1m\x1b[38;2;51;133;26m

# TARGET

NAME			=	libft.a

# FLAGS

MAKEFLAGS		+=	-s
CFLAGS			=	-Wall -Wextra -Werror -I. -g
ARFLAGS			=	rcs

# FILES

FILES			=	is/ft_isalnum is/ft_isdigit is/ft_isalpha				\
					is/ft_isprint is/ft_isascii is/ft_isspace				\
\
					str/ft_strlen											\
					str/ft_strlcpy str/ft_strlcat							\
					str/ft_strchr str/ft_strrchr							\
					str/ft_strcmp str/ft_strncmp							\
					str/ft_strdup str/ft_substr								\
					str/ft_strnstr str/ft_strtrim							\
					str/ft_strjoin str/ft_split								\
					str/ft_strmapi str/ft_striteri							\
					str/ft_toupper str/ft_tolower							\
\
					mem/ft_memset mem/ft_bzero								\
					mem/ft_memcpy mem/ft_memmove							\
					mem/ft_memchr mem/ft_memcmp								\
					mem/ft_calloc											\
\
					fd/ft_putchar_fd fd/ft_putstr_fd fd/ft_putendl_fd		\
					fd/ft_putnbr_fd fd/ft_putunbr_fd						\
					fd/ft_putlongnbr_fd fd/ft_puthexnbr_fd					\
\
					math/ft_atoi math/ft_atol math/ft_itoa					\
					math/ft_intlen math/ft_uintlen math/ft_hexlen			\
					math/ft_abs												\
\
					list/ft_lstnew											\
					list/ft_lstsize											\
					list/ft_lstlast list/ft_lstsecond_to_last				\
					list/ft_lstadd_front list/ft_lstadd_back				\
					list/ft_lstdelone list/ft_lstclear						\
					list/ft_lstiter list/ft_lstmap							\
\
					printf/ft_printf										\
					printf/ft_printf_struct_init							\
					printf/ft_printf_str_utils								\
					printf/ft_printf_identifiers							\
					printf/ft_printf_identifier_str							\
					printf/ft_printf_identifier_nbr							\
					printf/ft_printf_identifier_address						\
					printf/ft_printf_field_str								\
					printf/ft_printf_field_nbr								\
					printf/ft_printf_field_address							\
					printf/ft_printf_write_flag								\
\
					gnl/get_next_line										\
\

SRC				=	$(addsuffix .c, $(FILES))
OBJ				=	$(addsuffix .o, $(FILES))

# TEST

FILES_TEST		=	test_main												\
\
					test_ft_isalnum test_ft_isdigit test_ft_isalpha			\
					test_ft_isprint test_ft_isascii							\
\
					test_ft_strlen											\
					test_ft_strlcpy test_ft_strlcat							\
					test_ft_strchr test_ft_strrchr							\
					test_ft_strncmp											\
					test_ft_strdup test_ft_substr							\
					test_ft_strnstr test_ft_strtrim							\
					test_ft_strjoin test_ft_split							\
					test_ft_strmapi test_ft_striteri						\
					test_ft_toupper test_ft_tolower							\
\
					test_ft_memset test_ft_bzero							\
					test_ft_memcpy test_ft_memmove							\
					test_ft_memchr test_ft_memcmp							\
					test_ft_calloc											\
\
					test_ft_putchar_fd test_ft_putstr_fd test_ft_putendl_fd	\
					test_ft_putnbr_fd										\
\
					test_ft_atoi test_ft_itoa								\
\

DIR_TEST		=	tests/
SRC_TEST		=	$(addprefix $(DIR_TEST), $(addsuffix .c, $(FILES_TEST)))
OBJ_TEST		=	$(addprefix $(DIR_TEST), $(addsuffix .o, $(FILES_TEST)))

FILES_TEST_B	=	test_main_bonus											\
\
					test_ft_isalnum test_ft_isdigit test_ft_isalpha			\
					test_ft_isprint test_ft_isascii							\
\
					test_ft_toupper test_ft_tolower							\
\
					test_ft_strlen test_ft_strncmp test_ft_strnstr			\
					test_ft_strchr test_ft_strrchr							\
					test_ft_strlcpy test_ft_strlcat							\
					test_ft_strdup											\
\
					test_ft_memset test_ft_bzero test_ft_memmove			\
					test_ft_memcpy test_ft_memchr test_ft_memcmp			\
					test_ft_calloc											\
\
					test_ft_atoi											\
\
					test_ft_substr test_ft_strjoin test_ft_strtrim			\
					test_ft_split											\
					test_ft_itoa											\
					test_ft_strmapi test_ft_striteri						\
					test_ft_putchar_fd test_ft_putstr_fd					\
					test_ft_putendl_fd test_ft_putnbr_fd					\
\
					test_ft_lstnew test_ft_lstsize test_ft_lstlast			\
					test_ft_lstadd_front test_ft_lstadd_back				\
					test_ft_lstdelone test_ft_lstclear						\
					test_ft_lstiter test_ft_lstmap							\
\

SRC_TEST_B	=	$(addprefix $(DIR_TEST), $(addsuffix .c, $(FILES_TEST_B)))
OBJ_TEST_B	=	$(addprefix $(DIR_TEST), $(addsuffix .o, $(FILES_TEST_B)))

# RULES

all:			$(NAME)

$(NAME):		$(OBJ)
				$(AR) $(ARFLAGS) $(NAME) $^
				echo -e '$(LIGHT_GREEN) \tCompiled$(DARK_GREEN) $(NAME)$(LIGHT_GREEN) that include$(GREEN) $(FILES)'

clean:
				rm -f $(OBJ) $(OBJ_BONUS) $(OBJ_TEST) $(OBJ_TEST_B)
				echo -e '$(LIGHT_GREEN) \tCleaned$(GREEN) $(OBJ) $(OBJ_BONUS)'

fclean:			clean
				rm -f $(NAME) test testb $(DIR_TEST)/txt/*
				echo -e '$(LIGHT_GREEN) \tCleaned$(DARK_GREEN) $(NAME)'

re:				fclean all

test:			$(OBJ) $(OBJ_TEST)
				$(CC) $(CFLAGS) $^ -o $@ -lbsd

testb:			$(OBJ) $(OBJ_BONUS) $(OBJ_TEST_B)
				$(CC) $(CFLAGS) $^ -o $@ -lbsd

.PHONY:			all bonus clean fclean re test testb
