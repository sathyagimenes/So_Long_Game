/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:30:38 by sde-cama          #+#    #+#             */
/*   Updated: 2022/10/18 08:46:55 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int find_player(t_program *program);

int load_data(t_program *program)
{
	if (!find_player(program))
		return print_entity_error(INVALID_PLAYER);
	return (SUCCESS);
}

static int find_player(t_program *program)
{
	// coloca a posição do player
	// coloca configs do player
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
				return (SUCCESS);
			}
			column++;
		}
		row++;
	}
	return (FAIL);
}
