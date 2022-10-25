/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:41:28 by sde-cama          #+#    #+#             */
/*   Updated: 2022/10/25 12:40:51 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	initialize_game(t_program *program)
{
	program->mlx = mlx_init();
	program->mlx_win = mlx_new_window(
			program->mlx,
			program->column_qnty * IMG_SIZE,
			program->row_qnty * IMG_SIZE,
			"so_long");
	mlx_key_hook(program->mlx_win, keypress_hook, program);
	mlx_hook(program->mlx_win, ClientMessage, ButtonPressMask, end_game, program);
	mlx_expose_hook(program->mlx_win, &render, program);
	mlx_loop(program->mlx);
	return (SUCCESS);
}
