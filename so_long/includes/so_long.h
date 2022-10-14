/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:30:06 by sde-cama          #+#    #+#             */
/*   Updated: 2022/10/13 21:56:02 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <libft.h>
# include <fcntl.h>

# include <stdbool.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/resource.h>
# include <sys/stat.h>

//Macros
# define WINDOW_HEIGHT 360
# define WINDOW_WIDTH 640
# define EMPTY_SPACE '0'
# define WALL '1'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER_POSITION 'P'
# define IMG_SIZE 32

# define RED "\x1b[38;5;1m"
# define RESET "\x1b[0m"

# define FAIL 0
# define SUCCESS 1

// Enums
typedef enum s_error {
	INVALID_ARGUMENT,
	INVALID_TYPE_BER,
	INVALID_SIZE,
	INVALID_MAP
}	t_error;

// Structs
typedef struct s_program {
	void	*mlx;
	void	*mlx_win;
	int		row_qnty;
	int		column_qnty;
	char	**map_grid;
}	t_program;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

// Functions declarations
void	load_data(t_program *program);
int		initialize_game(t_program *program);
int		validate_argument(int argc, char *argv);
int		keypress_hook(int keycode, t_program *program);
int		end_game(t_program *program);
int		print_error_message(t_error error_type);
int		print_map_error(t_error error_type);
int		read_map(char *argv_1, t_program *program);
int		get_next_line(int fd, char **line);
void	free_grid(t_program *program);

#endif