/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:46:53 by sde-cama          #+#    #+#             */
/*   Updated: 2022/10/12 22:33:48 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	end_game(t_program *program)
{
	free_grid(program);
	mlx_destroy_window(program->mlx, program->mlx_win);
	mlx_destroy_display(program->mlx);
	free(program->mlx);
	exit(SUCCESS);
	return (SUCCESS);
}

void	free_grid(t_program *program)
{
	int	i;

	i = 0;
	while (program->map_grid[i] != NULL)
	{
		free(program->map_grid[i]);
		i++;
	}
	free(program->map_grid);
}
