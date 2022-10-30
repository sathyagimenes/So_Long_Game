NAME	= so_long
INCLUDES_PATH	= ./includes
LIBFT_PATH = ./libft
MINILIBX_PATH = ./minilibx
CC	= gcc
CFLAGS	= -Wall -Werror -Wextra -g3
LINK_EXTERNAL_LIBS = -lm -lmlx -lXext -lX11
LINK_INTERNAL_LIBS = -lft
LIB = libft/libft.a
MLX = minilibx/libmlx.a
BONUS_NAME	= so_long_bonus
BONUS_INCLUDES_PATH	= ./bonus/includes

SRCS	= ./sources/main.c				\
			./sources/load_data.c		\
			./sources/initialize.c		\
			./sources/arg_validation.c	\
			./sources/end_game.c		\
			./sources/hooks.c			\
			./sources/error_messages.c	\
			./sources/read_map.c		\
			./sources/get_next_line.c	\
			./sources/entity_validation.c	\
			./sources/draw_map.c		\
			./sources/move_player.c		\
			./sources/path_validation.c

BONUS_SRCS = ./sources/main.c				\
			./bonus/sources/load_data_bonus.c		\
			./sources/initialize.c		\
			./sources/arg_validation.c	\
			./bonus/sources/end_game_bonus.c		\
			./sources/hooks.c			\
			./bonus/sources/error_messages_bonus.c	\
			./sources/read_map.c		\
			./sources/get_next_line.c	\
			./bonus/sources/entity_validation_bonus.c	\
			./bonus/sources/draw_map_bonus.c		\
			./bonus/sources/move_player_bonus.c		\
			./bonus/sources/path_validation_bonus.c

OBJS	= $(SRCS:%.c=%.o)

BONUS_OBJS	= $(BONUS_SRCS:%.c=%.o)

all:	$(NAME) ${LIB} ${MLX}

$(NAME):	${LIB} ${MLX} $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $@ -L $(LIBFT_PATH) -L $(MINILIBX_PATH) -I $(MINILIBX_PATH) -I $(INCLUDES_PATH) -I $(LIBFT_PATH) $(LINK_EXTERNAL_LIBS) $(LINK_INTERNAL_LIBS)

%.o:		%.c
			$(CC) $(CFLAGS) -I $(INCLUDES_PATH) -I $(BONUS_INCLUDES_PATH) -I $(LIBFT_PATH) -I $(MINILIBX_PATH) $(LINK_EXTERNAL_LIBS) -o $@ -c $<

${LIB}:
	make -C libft

${MLX}:
	make -C minilibx

bonus:	$(BONUS_NAME) ${LIB} ${MLX}

$(BONUS_NAME):	${LIB} ${MLX} $(BONUS_OBJS)
				$(CC) $(CFLAGS) $(BONUS_OBJS) -o $@ -L $(LIBFT_PATH) -L $(MINILIBX_PATH) -I $(MINILIBX_PATH) -I $(BONUS_INCLUDES_PATH) -I $(LIBFT_PATH) $(LINK_EXTERNAL_LIBS) $(LINK_INTERNAL_LIBS)

clean:
			$(MAKE) clean -C $(LIBFT_PATH)
			rm -f $(OBJS) $(BONUS_OBJS)

fclean:		clean
			$(MAKE) fclean -C $(LIBFT_PATH)
			rm -f $(NAME) $(BONUS_NAME)

re:			fclean all

.PHONY:		all clean fclean re
