/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:46:53 by sde-cama          #+#    #+#             */
/*   Updated: 2022/10/23 16:42:48 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	end_game(t_program *program, t_end end_type)
{
	free_grid(program);
	mlx_destroy_window(program->mlx, program->mlx_win);
	mlx_destroy_display(program->mlx);
	free(program->mlx);
	if (end_type == ENEMY_KILL)
		ft_printf("You lose! The orcs found Frodo!\n");
	if (end_type == FOUND_EXIT)
		ft_printf("You win! Frodo destroyed the ring in Mount Doom!\n");
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
