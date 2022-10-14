// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   read_map.c                                         :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/10/07 23:20:58 by sde-cama          #+#    #+#             */
// /*   Updated: 2022/10/14 15:49:57 by sde-cama         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "so_long.h"

// int	set_map_length(char *argv_1, t_program *program);
// int	valid_read(char *argv_1);
// int	save_map(char *argv_1, t_program *program);
// int	verify_walls(t_program *program);

// int	read_map(char *argv_1, t_program *program)
// {
// 	// int		fd;
// 	// char	*line;
// 	// char	*map_single_line;

// 	if (!valid_read(argv_1))
// 		return (print_map_error(INVALID_MAP));
// 	if (!set_map_length(argv_1, program))
// 		return (print_map_error(INVALID_SIZE));
// 	if (!save_map(argv_1, program))
// 	{
// 		free_grid(program);
// 		return (print_map_error(INVALID_MAP));
// 	}
// 	if (!verify_walls(program))
// 	{
// 		free_grid(program);
// 		return (print_map_error(INVALID_MAP));
// 	}
// 	// if (!verify_valid_entities_for(program))
// 	// {
// 	// 	free_grid(program);
// 	// 	return (print_so_long_error(ERR_INVALID_ENTITIES));
// 	// }
// 	return (SUCCESS);
// }

// int	set_map_length(char *argv_1, t_program *program)
// {
// 	int		fd;
// 	int		gnl;
// 	int		nrows;
// 	int		ncolumns;
// 	char	*line;

// 	gnl = 1;
// 	nrows = 0;
// 	ncolumns = 0;
// 	fd = open(argv_1, O_RDONLY);
// 	while (gnl)
// 	{
// 		gnl = get_next_line(fd, &line);
// 		nrows++;
// 		if (nrows == 1)
// 			ncolumns = ft_strlen(line);
// 		if (gnl == 1)
// 			free(line);
// 	}
// 	close(fd);
// 	if (nrows < 4 || ncolumns < 4)
// 		return (FAIL);
// 	program->row_qnty = nrows;
// 	program->column_qnty = ncolumns;
// 	return (SUCCESS);
// }

// int	save_map(char *argv_1, t_program *program)
// {
// 	int		fd;
// 	int		i;
// 	int		gnl;
// 	int		nrows;

// 	i = 0;
// 	gnl = 1;
// 	nrows = program->row_qnty;
// 	fd = open(argv_1, O_RDONLY);
// 	program->map_grid = (char **)ft_calloc(sizeof(char *), nrows + 1);
// 	while (gnl)
// 	{
// 		gnl = get_next_line(fd, &program->map_grid[i]);
// 		i++;
// 	}
// 	close(fd);
// 	return (SUCCESS);
// }

// int	valid_read(char *argv_1)
// {
// 	int		fd;
// 	char	*line;
// 	int		gnl;

// 	fd = open(argv_1, O_RDONLY);
// 	gnl = get_next_line(fd, &line);
// 	if (gnl < 0)
// 		return (FAIL);
// 	free(line);
// 	close(fd);
// 	return (SUCCESS);
// }

// int	verify_walls(t_program *program)
// {
// 	int	x;
// 	int	y;
// 	//char	**grid;

// 	x = 0;
// 	//grid = program->map_grid;
// 	while (x < program->row_qnty)
// 	{
// 		y = 0;
// 		while (y < program->column_qnty)
// 		{
// 			//ft_printf("%d,%d: %c ", x,y, grid[x][y]);
// 			ft_printf("%d:%d", program->column_qnty,program->row_qnty);
// 			y++;
// 		}
// 		x++;
// 	}
// 	return (SUCCESS);
// }



#include "so_long.h"

static int	read_map_nrows(char *argv_1)
{
	int		fd;
	int		counter;
	int		gnl;
	char	*line;

	counter = 0;
	gnl = 1;
	fd = open(argv_1, O_RDONLY);
	if (fd < 0)
		return (0);
	while (gnl)
	{
		gnl = get_next_line(fd, &line);
		if (gnl < 0)
		{
			return (FAIL);
		}
		counter++;
		//free(line);
	}
	close(fd);
	return (counter);
}

static int	parse_map_for(int nrows, char *argv_1, t_program *program)
{
	int		fd;
	int		i;
	int		gnl;

	i = 0;
	gnl = 1;
	program->map_grid = (char **)ft_calloc(sizeof(char *), nrows + 1);
	if (!program->map_grid)
		return (FAIL);
	fd = open(argv_1, O_RDONLY);
	while (gnl)
	{
		gnl = get_next_line(fd, &program->map_grid[i]);
		if (gnl < 0)
		{
			free_grid(program);
			return (FAIL);
		}
		ft_printf("%s\n", program->map_grid[i]);
		i++;
	}
	//ensure_no_gnl_leaks(program, &nrows);
	close(fd);
	program->row_qnty = nrows;
	program->column_qnty = ft_strlen(program->map_grid[0]);
	ft_printf("%d:%d\n", program->column_qnty,program->row_qnty); //aqui
	return (SUCCESS);
}

static int	verify_walls_for(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->column_qnty)
	{
		if (program->map_grid[0][i] != WALL
			|| program->map_grid[program->row_qnty - 1][i] != WALL)
			return (FAIL);
		i++;
	}
	i = 0;
	while (i < program->row_qnty - 1)
	{
		if (program->map_grid[i][0] != WALL
			|| program->map_grid[i][program->column_qnty - 1] != WALL
			|| ft_strlen(program->map_grid[i]) != ft_strlen(program->map_grid[i + 1]))
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}

static int	verify_valid_entities_for(t_program *program)
{
	int	row;
	int	col;

	row = 1;
	while (row <= program->row_qnty - 2)
	{
		col = 1;
		while (col <= program->column_qnty - 2)
		{
			if (program->map_grid[row][col] != COLLECTIBLE
				&& program->map_grid[row][col] != PLAYER_POSITION
				&& program->map_grid[row][col] != EXIT
				&& program->map_grid[row][col] != EMPTY_SPACE
				&& program->map_grid[row][col] != WALL)
			{
				free_grid(program);
				return (print_map_error(INVALID_MAP));
			}
			col++;
		}
		row++;
	}
	return (SUCCESS);
}

int	read_map(char *argv_1, t_program *program)
{
	int	nrows;

	nrows = read_map_nrows(argv_1);
	if (!nrows)
		return (print_map_error(INVALID_MAP));
	if (!parse_map_for(nrows, argv_1, program))
	{
		free_grid(program);
		return (print_map_error(INVALID_MAP));
	}
	if (!verify_walls_for(program))
	{
		free_grid(program);
		return (print_map_error(INVALID_MAP));
	}
	if (!verify_valid_entities_for(program))
	{
		free_grid(program);
		return (print_map_error(INVALID_MAP));
	}
	return (SUCCESS);
}