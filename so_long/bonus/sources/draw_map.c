/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:00:09 by sde-cama          #+#    #+#             */
/*   Updated: 2022/10/28 11:13:45 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void draw_image(char grid_pos, t_program *program);
static void draw_text(t_program *program);

int render(t_program *program)
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
    if (program->player.steps != 0)
        draw_text(program);
    destroy_sprites(program);
    return (SUCCESS);
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
    else if (grid_pos == ENEMY)
        mlx_put_image_to_window(program->mlx, program->mlx_win,
                                program->obj.enemy.image, program->pos.y, program->pos.x);
    else if (grid_pos == PLAYER_POSITION)
        mlx_put_image_to_window(program->mlx, program->mlx_win,
                                program->player.image, program->player.point.y * IMG_SIZE, program->player.point.x * IMG_SIZE);
}

static void draw_text(t_program *program)
{
    char	*count;
    char	*steps;

	count = ft_itoa(program->player.steps);
	steps = ft_strjoin("Steps: ", count);
    free(count);
	printf("%s\n", steps);
    mlx_string_put(program->mlx, program->mlx_win, 10, 10, 0x00FFFFFF, steps);
    free(steps);
}
