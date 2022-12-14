/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 23:20:58 by sde-cama          #+#    #+#             */
/*   Updated: 2022/10/30 00:03:04 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	set_map_length(char *argv_1, t_program *program);
static int	valid_read(char *argv_1);
static int	save_map(char *argv_1, t_program *program);
int			valid_shape(t_program *program);

int	read_map(char *argv_1, t_program *program)
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
	if (!valid_shape(program))
	{
		free_grid(program);
		return (print_map_error(INVALID_SHAPE));
	}
	return (SUCCESS);
}

static int	valid_read(char *argv_1)
{
	int		fd;
	char	*line;
	int		gnl;
	int		check_for_empty_lines;

	check_for_empty_lines = 0;
	fd = open(argv_1, O_RDONLY);
	gnl = 1;
	while (gnl)
	{
		gnl = get_next_line(fd, &line);
		if (gnl < 0)
			return (FAIL);
		if (ft_strlen(line) == 0)
			check_for_empty_lines = 1;
		if (gnl >= 0)
			free(line);
	}
	close(fd);
	if (check_for_empty_lines)
		return (FAIL);
	return (SUCCESS);
}

static int	set_map_length(char *argv_1, t_program *program)
{
	int		fd;
	int		gnl;
	char	*line;

	gnl = 1;
	program->row_qnty = 0;
	program->column_qnty = 0;
	fd = open(argv_1, O_RDONLY);
	while (gnl)
	{
		gnl = get_next_line(fd, &line);
		program->row_qnty++;
		if (program->row_qnty == 1)
			program->column_qnty = ft_strlen(line);
		if (ft_strlen(line) == 0)
			program->row_qnty--;
		if (gnl >= 0)
			free(line);
	}
	close(fd);
	if (program->row_qnty == program->column_qnty)
		return (FAIL);
	return (SUCCESS);
}

static int	save_map(char *argv_1, t_program *program)
{
	int	fd;
	int	i;
	int	gnl;
	int	nrows;

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

int	valid_shape(t_program *program)
{
	int		x;
	size_t	len;

	x = 0;
	len = ft_strlen(program->map_grid[x]);
	while (x < program->row_qnty)
	{
		if (ft_strlen(program->map_grid[x++]) != len)
			return (FAIL);
		x++;
	}
	return (SUCCESS);
}
