NAME	= so_long
INCLUDES_PATH	= ./includes
LIBFT_PATH = ./libft
MINILIBX_PATH = ./minilibx
MINILIBX_PATH = ./minilibx
COMPILE	= gcc
CFLAGS	= -Wall -Werror -Wextra -g3
LINK_EXTERNAL_LIBS = -lm -lmlx -lXext -lX11
LINK_INTERNAL_LIBS = -lft

SRCS	= ./sources/main.c				\
			./sources/load_data.c		\
			./sources/initialize.c		\
			./sources/arg_validation.c	\
			./sources/end_game.c		\
			./sources/hooks.c			\
			./sources/error_messages.c	\
			./sources/read_map.c		\
			./sources/get_next_line.c	\
			./sources/entity_validation.c

OBJS	= $(SRCS:%.c=%.o)

all:	$(NAME)

$(NAME):	build_libft build_minilibx $(OBJS)
			$(COMPILE) $(CFLAGS) $(OBJS) -o $@ -L $(LIBFT_PATH) -L $(MINILIBX_PATH) -I $(MINILIBX_PATH) -I $(INCLUDES_PATH) -I $(LIBFT_PATH) $(LINK_EXTERNAL_LIBS) $(LINK_INTERNAL_LIBS)

%.o:		%.c
			$(COMPILE) $(CFLAGS) -I $(INCLUDES_PATH) -I $(LIBFT_PATH) -I $(MINILIBX_PATH) $(LINK_EXTERNAL_LIBS) -o $@ -c $<

build_libft:
			$(MAKE) -C $(LIBFT_PATH)

build_minilibx:
			$(MAKE) -C $(MINILIBX_PATH)

clean:
			$(MAKE) clean -C $(LIBFT_PATH)
			rm -f $(OBJS)

fclean:		clean
			$(MAKE) fclean -C $(LIBFT_PATH)
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
