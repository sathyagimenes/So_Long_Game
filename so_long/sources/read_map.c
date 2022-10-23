/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 23:20:58 by sde-cama          #+#    #+#             */
/*   Updated: 2022/10/23 11:51:17 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int set_map_length(char *argv_1, t_program *program);
static int valid_read(char *argv_1);
static int save_map(char *argv_1, t_program *program);

int read_map(char *argv_1, t_program *program)
{
	if (!valid_read(argv_1))
		return (print_map_error(INVALID_MAP));
	if (!set_map_length(argv_1, program))
		return (print_map_error(INVALID_SHAPE));
	if (!save_map(argv_1, program))
	{
		free_grid(program);
		return (print_map_error(INVALID_SAVE));
	}
	return (SUCCESS);
}

static int valid_read(char *argv_1)
{
	int fd;
	char *line;
	int gnl;

	fd = open(argv_1, O_RDONLY);
	gnl = 1;
	while (gnl)
	{
		gnl = get_next_line(fd, &line);
		if (gnl < 0)
			return (FAIL);
		if (gnl >= 0)
			free(line);
	}
	close(fd);
	return (SUCCESS);
}

static int set_map_length(char *argv_1, t_program *program)
{
	int fd;
	int gnl;
	int nrows;
	int ncolumns;
	char *line;

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
		if (ft_strlen(line) == 0)
			nrows--;
		if (gnl >= 0)
			free(line);
	}
	close(fd);
	if (nrows == ncolumns)
		return (FAIL);
	program->row_qnty = nrows;
	program->column_qnty = ncolumns;
	return (SUCCESS);
}

static int save_map(char *argv_1, t_program *program)
{
	int fd;
	int i;
	int gnl;
	int nrows;
	size_t row_len;

	i = 0;
	gnl = 1;
	row_len = 0;
	nrows = program->row_qnty;
	fd = open(argv_1, O_RDONLY);
	program->map_grid = (char **)ft_calloc(sizeof(char *), nrows + 1);
	while (gnl)
	{
		gnl = get_next_line(fd, &program->map_grid[i]);
		if (row_len == 0)
			row_len = ft_strlen(program->map_grid[i]);
		else if (ft_strlen(program->map_grid[i]) != row_len)
			return (FAIL);
		i++;
	}
	close(fd);
	return (SUCCESS);
}
