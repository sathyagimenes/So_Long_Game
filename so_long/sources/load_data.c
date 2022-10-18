/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:30:38 by sde-cama          #+#    #+#             */
/*   Updated: 2022/10/18 10:32:43 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void save_player_position(t_program *program);
static void initial_configuration(t_program *program);

void load_data(t_program *program)
{
	save_player_position(program);
	initial_configuration(program);
}

static void save_player_position(t_program *program)
{
	int row;
	int column;

	row = 1;
	while (row < program->row_qnty - 1)
	{
		column = 1;
		while (column < program->column_qnty - 1)
		{
			if (program->map_grid[row][column] == PLAYER_POSITION)
			{
				program->player.point.x = row;
				program->player.point.y = column;
			}
			column++;
		}
		row++;
	}
}

static void initial_configuration(t_program *program)
{
	program->player.face = P_DOWN;
	program->player.steps = 0;
}
