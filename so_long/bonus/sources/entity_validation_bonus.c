/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 09:48:59 by sde-cama          #+#    #+#             */
/*   Updated: 2022/10/28 11:13:51 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int verify_walls(t_program *program);
static int verify_entities(t_program *program);
static int quantity_validation(t_program *program);
static void count_entities(t_program *program);

int map_validation(t_program *program)
{
	if (!verify_walls(program))
	{
		free_grid(program);
		return (FAIL);
	}
	if (!verify_entities(program))
	{
		free_grid(program);
		return (FAIL);
	}
	if (!quantity_validation(program))
	{
		free_grid(program);
		return (FAIL);
	}
	save_player_position(program);
	if (!verify_path(program))
	{
		free_grid(program);
		return (FAIL);
	}
	return (SUCCESS);
}

static int verify_walls(t_program *program)
{
	int x;
	int y;
	char **grid;
	int ncolumn;
	int nrow;

	ncolumn = program->column_qnty;
	nrow = program->row_qnty;
	grid = program->map_grid;
	x = 0;
	while (x < nrow)
	{
		y = 0;
		while (y < ncolumn)
		{
			if (x == 0 || y == 0 || x == nrow - 1 || y == ncolumn - 1)
				if (grid[x][y] != WALL)
					return (print_entity_error(INVALID_WALL));
			y++;
		}
		x++;
	}
	return (SUCCESS);
}

static int verify_entities(t_program *program)
{
	int x;
	int y;
	char **grid;
	int ncolumn;
	int nrow;

	ncolumn = program->column_qnty;
	nrow = program->row_qnty;
	grid = program->map_grid;
	x = 1;
	while (x < nrow - 1)
	{
		y = 1;
		while (y < ncolumn - 1)
		{
			if (grid[x][y] != PLAYER_POSITION && grid[x][y] != EXIT && grid[x][y] != COLLECTIBLE && grid[x][y] != EMPTY_SPACE && grid[x][y] != WALL && grid[x][y] != ENEMY)
				return (print_entity_error(INVALID_ENTITIES));
			y++;
		}
		x++;
	}
	return (SUCCESS);
}

static int quantity_validation(t_program *program)
{
	count_entities(program);
	if (program->player.qty != 1)
		return (print_entity_error(INVALID_PLAYER));
	if (program->obj.collectible.qty < 1)
		return (print_entity_error(INVALID_COLLECTIBLE));
	if (program->obj.exit.qty != 1)
		return (print_entity_error(INVALID_EXIT));
	return (SUCCESS);
}

static void count_entities(t_program *program)
{
	int x;
	int y;

	program->player.qty = 0;
	program->obj.collectible.qty = 0;
	program->obj.exit.qty = 0;
	program->obj.enemy.qty = 0;
	x = 1;
	while (x < program->row_qnty - 1)
	{
		y = 1;
		while (y < program->column_qnty - 1)
		{
			if (program->map_grid[x][y] == PLAYER_POSITION)
				program->player.qty += 1;
			if (program->map_grid[x][y] == EXIT)
				program->obj.exit.qty += 1;
			if (program->map_grid[x][y] == COLLECTIBLE)
				program->obj.collectible.qty += 1;
			if (program->map_grid[x][y] == ENEMY)
				program->obj.enemy.qty += 1;
			y++;
		}
		x++;
	}
}
