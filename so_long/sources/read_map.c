/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 23:20:58 by sde-cama          #+#    #+#             */
/*   Updated: 2022/10/14 00:33:16 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	set_map_length(char *argv_1, t_program *program);
int	valid_read(char *argv_1);
int	save_map(char *argv_1, t_program *program);
int	verify_walls(t_program *program);

int	read_map(char *argv_1, t_program *program)
{
	// int		fd;
	// char	*line;
	// char	*map_single_line;

	if (!valid_read(argv_1))
		return (print_map_error(INVALID_MAP));
	if (!set_map_length(argv_1, program))
		return (print_map_error(INVALID_SIZE));
	if (!save_map(argv_1, program))
	{
		free_grid(program);
		return (print_map_error(INVALID_MAP));
	}
	if (!verify_walls(program))
	{
		free_grid(program);
		return (print_map_error(INVALID_MAP));
	}
	// if (!verify_valid_entities_for(program))
	// {
	// 	free_grid(program);
	// 	return (print_so_long_error(ERR_INVALID_ENTITIES));
	// }
	return (SUCCESS);
}

int	set_map_length(char *argv_1, t_program *program)
{
	int		fd;
	int		gnl;
	int		nrows;
	int		ncolumns;
	char	*line;

	gnl = 1;
	nrows = 0;
	ncolumns = 0;
	fd = open(argv_1, O_RDONLY);
	while (gnl)
	{
		gnl = get_next_line(fd, &line);
		nrows++;
		if (nrows == 1)
			ncolumns = ft_strlen(line);
		if (gnl == 1)
			free(line);
	}
	close(fd);
	if (nrows < 4 || ncolumns < 4)
		return (FAIL);
	program->row_qnty = nrows;
	program->column_qnty = ncolumns;
	return (SUCCESS);
}

int	save_map(char *argv_1, t_program *program)
{
	int		fd;
	int		i;
	int		gnl;
	int		nrows;

	i = 0;
	gnl = 1;
	nrows = program->row_qnty;
	fd = open(argv_1, O_RDONLY);
	program->map_grid = (char **)ft_calloc(sizeof(char *), nrows + 1);
	while (gnl)
	{
		gnl = get_next_line(fd, &program->map_grid[i]);
		i++;
	}
	close(fd);
	return (SUCCESS);
}

int	valid_read(char *argv_1)
{
	int		fd;
	char	*line;
	int		gnl;

	fd = open(argv_1, O_RDONLY);
	gnl = get_next_line(fd, &line);
	if (gnl < 0)
		return (FAIL);
	free(line);
	close(fd);
	return (SUCCESS);
}

int	verify_walls(t_program *program)
{
	int	i;
	int	j;
	int	ncolumn;
	int	nrow;
	ncolumn = program->column_qnty;
	nrow = program->row_qnty;

	i = 0;
	while (i < program->column_qnty)
	{
		j = 0;
		while (j < program->row_qnty)
		{
			if (i == 0 || j == 0
				|| i == ncolumn - 1 || j == nrow - 1)
			{
				if (program->map_grid[i][j] != '1')
			 		ft_printf("%c", program->map_grid[i][j]);
			}
			j++;
		}
		i++;
	}
	// int	i;
	// int	j;

	// i = 0;
	// while (i < program->column_qnty)
	// {
	// 	j = 0;
	// 	while (j < program->row_qnty)
	// 	{
	// 		ft_printf("%c", program->map_grid[i][j]);

	// 		// if (program->map_grid[0][j - 1] != WALL)
	// 		// 	ft_printf("%c", program->map_grid[0][j - 1]);
	// 		// if (program->map_grid[0][j] != WALL)
	// 		// 	return (FAIL);
	// 		// if (program->map_grid[i][0] != WALL || program->map_grid[i][program->column_qnty - 1] != WALL)
	// 		// 	return (FAIL);
	// 		// if (j == 0 && program->map_grid[i][j] != WALL)
	// 		// 	return (FAIL);
	// 		// if (j == (program->row_qnty - 1) && program->map_grid[i][j] != WALL)
	// 		// 	return (FAIL);
	// 		// if (ft_strlen(program->map_grid[i]) != ft_strlen(program->map_grid[i + 1]))
	// 		// 	return (FAIL);
	// 		j++;
	// 	}
	// 	i++;
	// }
	return (SUCCESS);
}
