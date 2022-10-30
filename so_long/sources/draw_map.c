/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:00:09 by sde-cama          #+#    #+#             */
/*   Updated: 2022/10/30 01:59:42 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_image(char grid_pos, t_program *program);
static void	draw_text(t_program *program);

int	render(t_program *program)
{
	int	x;
	int	y;

	load_sprites(program);
	mlx_clear_window(program->mlx, program->mlx_win);
	x = 0;
	while (x < program->row_qnty)
	{
		y = 0;
		while (y < program->column_qnty)
		{
			program->pos.x = x * IMG_SIZE;
			program->pos.y = y * IMG_SIZE;
			mlx_put_image_to_window(program->mlx, program->mlx_win,
				program->obj.floor.image, program->pos.y, program->pos.x);
			draw_image(program->map_grid[x][y], program);
			y++;
		}
		x++;
	}
	if (program->player.steps != 0)
		draw_text(program);
	destroy_sprites(program);
	return (SUCCESS);
}

static void	draw_image(char grid_pos, t_program *program)
{
	int	player_pos_x;
	int	player_pos_y;

	player_pos_x = program->player.point.x * IMG_SIZE;
	player_pos_y = program->player.point.y * IMG_SIZE;
	if (grid_pos == WALL)
		mlx_put_image_to_window(program->mlx, program->mlx_win,
			program->obj.wall.image, program->pos.y, program->pos.x);
	else if (grid_pos == EXIT)
		mlx_put_image_to_window(program->mlx, program->mlx_win,
			program->obj.exit.image, program->pos.y, program->pos.x);
	else if (grid_pos == COLLECTIBLE)
		mlx_put_image_to_window(program->mlx, program->mlx_win,
			program->obj.collectible.image, program->pos.y, program->pos.x);
	else if (grid_pos == PLAYER_POSITION)
		mlx_put_image_to_window(program->mlx, program->mlx_win,
			program->player.image, player_pos_y, player_pos_x);
}

static void	draw_text(t_program *program)
{
	printf("steps: %d\n", program->player.steps);
}
