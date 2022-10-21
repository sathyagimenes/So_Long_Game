/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:00:09 by sde-cama          #+#    #+#             */
/*   Updated: 2022/10/21 11:10:51 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void draw_image(char grid_pos, t_program *program);

// int draw_map(t_program *program)
// {
//     load_sprites(program);
//     if (program->obj.collectible.image)
//         mlx_put_image_to_window(program->mlx, program->mlx_win, program->obj.exit.image, 0, 0);
//     return (SUCCESS);
// }

void render(t_program *program)
{
    int x;
    int y;

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
    //draw_text(game);
}

static void draw_image(char grid_pos, t_program *program)
{
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
    		program->player.image, program->pos.y, program->pos.x);
    else if (grid_pos == ENEMY)
    	mlx_put_image_to_window(program->mlx, program->mlx_win,
    		program->obj.enemy.image, program->pos.y, program->pos.x);
}
