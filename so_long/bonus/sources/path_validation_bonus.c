/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:16:30 by sde-cama          #+#    #+#             */
/*   Updated: 2022/10/30 02:29:01 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int		make_copy(char **grid_copy, char **grid_orig, int ncolumns, int nrows);
void	flood_fill(t_path *path, int x, int y);
void	free_grid_copy(char **grid);

int	verify_path(t_program *program)
{
	t_path	path;
	int		nrows;

	path.collect = 0;
	path.exit = 0;
	path.point.x = program->player.point.x;
	path.point.y = program->player.point.y;
	nrows = program->row_qnty;
	path.grid = ft_calloc(sizeof(char *), nrows + 1);
	make_copy(path.grid, program->map_grid,
		program->column_qnty, program->row_qnty);
	flood_fill(&path, path.point.x, path.point.y);
	free_grid_copy(path.grid);
	if (path.collect != program->obj.collectible.qty || path.exit == 0)
		return (print_entity_error(INVALID_PATH));
	return (SUCCESS);
}

void	flood_fill(t_path *path, int x, int y)
{
	if (path->grid[x][y] == COLLECTIBLE)
		path->collect += 1;
	if (path->grid[x][y] == EXIT)
		path->exit += 1;
	if (path->grid[x][y] == WALL || path->grid[x][y] == ENEMY ||
	path->grid[x][y] == EXIT)
		return ;
	path->grid[x][y] = WALL;
	flood_fill(path, x + 1, y);
	flood_fill(path, x - 1, y);
	flood_fill(path, x, y + 1);
	flood_fill(path, x, y - 1);
}

int	make_copy(char **grid_copy, char **grid_orig, int ncolumns, int nrows)
{
	int	x;
	int	y;

	x = 0;
	while (x < nrows)
	{
		grid_copy[x] = ft_calloc(sizeof(char), ncolumns);
		if (!grid_copy[x])
			return (FAIL);
		y = 0;
		while (y < ncolumns)
		{
			grid_copy[x][y] = grid_orig[x][y];
			y++;
		}
		x++;
	}
	grid_copy[x] = NULL;
	return (SUCCESS);
}

void	free_grid_copy(char **grid)
{
	int	i;

	i = 0;
	while (grid[i] != NULL)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}
