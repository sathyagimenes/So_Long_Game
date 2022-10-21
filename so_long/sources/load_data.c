/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:30:38 by sde-cama          #+#    #+#             */
/*   Updated: 2022/10/21 12:52:51 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void save_player_position(t_program *program);
static void initial_configuration(t_program *program);
static int	load_sprites_path(t_program *program);

void load_data(t_program *program)
{
	save_player_position(program);
	initial_configuration(program);
	load_sprites_path(program);
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

static int	load_sprites_path(t_program *program)
{
	program->player.sprite[P_UP].path = "./images/player_up.xpm";
	program->player.sprite[P_DOWN].path = "./images/player_down.xpm";
	program->player.sprite[P_LEFT].path = "./images/player_left.xpm";
	program->player.sprite[P_RIGHT].path = "./images/player_right.xpm";
	program->obj.collectible.path = "./images/collectible.xpm";
	program->obj.exit.path = "./images/exit.xpm";
	program->obj.floor.path = "./images/floor.xpm";
	program->obj.wall.path = "./images/wall.xpm";
	program->obj.enemy.path = "./images/enemy.xpm";
	return (SUCCESS);
}

int	load_sprites(t_program *program)
{
	program->player.image = mlx_xpm_file_to_image(program->mlx,
			program->player.sprite[program->player.face].path,
			&program->player.width,
			&program->player.height);
	program->obj.collectible.image = mlx_xpm_file_to_image(program->mlx,
			program->obj.collectible.path,
			&program->obj.collectible.width,
			&program->obj.collectible.height);
	program->obj.exit.image = mlx_xpm_file_to_image(program->mlx,
			program->obj.exit.path,
			&program->obj.exit.width,
			&program->obj.exit.height);
	program->obj.floor.image = mlx_xpm_file_to_image(program->mlx,
			program->obj.floor.path,
			&program->obj.floor.width,
			&program->obj.floor.height);
	program->obj.collectible.image = mlx_xpm_file_to_image(program->mlx,
			program->obj.collectible.path, 
			&program->obj.collectible.width, 
			&program->obj.collectible.height);
	program->obj.exit.image = mlx_xpm_file_to_image(program->mlx,
			program->obj.exit.path,
			&program->obj.exit.width,
			&program->obj.exit.height);
	program->obj.floor.image = mlx_xpm_file_to_image(program->mlx,
			program->obj.floor.path,
			&program->obj.floor.width,
			&program->obj.floor.height);
	program->obj.wall.image = mlx_xpm_file_to_image(program->mlx,
			program->obj.wall.path,
			&program->obj.wall.width,
			&program->obj.floor.height);
	program->obj.enemy.image = mlx_xpm_file_to_image(program->mlx,
			program->obj.enemy.path,
			&program->obj.enemy.width,
			&program->obj.enemy.height);
	return (SUCCESS);
}
