NAME	= so_long
INCLUDES_PATH	= ./includes
LIBFT_PATH = ./libft
MINILIBX_PATH = ./minilibx
COMPILE	= gcc
CFLAGS	= -Wall -Werror -Wextra
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

OBJS	= $(SRCS:%.c=%.o)

all:	$(NAME)

$(NAME):	build_libft minilibx_libft $(OBJS)
			$(COMPILE) $(CFLAGS) -g $(OBJS) -o $@ -L $(LIBFT_PATH) -L $(MINILIBX_PATH) -I $(INCLUDES_PATH) -I $(LIBFT_PATH) -I $(MINILIBX_PATH) $(LINK_EXTERNAL_LIBS) $(LINK_INTERNAL_LIBS)

%.o:		%.c
			$(COMPILE) $(CFLAGS) -g -I $(INCLUDES_PATH) -I $(LIBFT_PATH) -I $(MINILIBX_PATH) $(LINK_EXTERNAL_LIBS) -o $@ -c $<

build_libft:
			$(MAKE) -C $(LIBFT_PATH)

minilibx_libft:
			$(MAKE) -C $(MINILIBX_PATH)

clean:
			$(MAKE) clean -C $(LIBFT_PATH)
			rm -f $(OBJS)

fclean:		clean
			$(MAKE) fclean -C $(LIBFT_PATH)
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
