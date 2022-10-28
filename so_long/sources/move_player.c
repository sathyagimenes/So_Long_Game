/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 12:32:08 by sde-cama          #+#    #+#             */
/*   Updated: 2022/10/28 13:01:09 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int check_movement(t_program *program, char next_position);

void move_player_up(t_program *program)
{
    int x;

    x = program->player.point.x - 1;
    program->player.face = P_UP;
    
    if (check_movement(program, program->map_grid[x][program->player.point.y]))
    {
        program->map_grid[x][program->player.point.y] = EMPTY_SPACE;
        program->player.point.x = x;
        program->map_grid[x][program->player.point.y] = PLAYER_POSITION;
        program->player.steps += 1;
    }
}

void move_player_down(t_program *program)
{
    int x;

    x = program->player.point.x + 1;
    program->player.face = P_DOWN;
    
    if (check_movement(program, program->map_grid[x][program->player.point.y]))
    {
        program->map_grid[x][program->player.point.y] = EMPTY_SPACE;
        program->player.point.x = x;
        program->map_grid[x][program->player.point.y] = PLAYER_POSITION;
        program->player.steps += 1;
    }
}

void move_player_right(t_program *program)
{
    int y;

    y = program->player.point.y + 1;
    program->player.face = P_RIGHT;

    if (check_movement(program, program->map_grid[program->player.point.x][y]))
    {
        program->map_grid[program->player.point.x][y] = EMPTY_SPACE;
        program->player.point.y = y;
        program->map_grid[program->player.point.x][y] = PLAYER_POSITION;
        program->player.steps += 1;
    }
}

void move_player_left(t_program *program)
{
    int y;

    y = program->player.point.y - 1;
    program->player.face = P_LEFT;
    
    if (check_movement(program, program->map_grid[program->player.point.x][y]))
    {
        program->map_grid[program->player.point.x][y] = EMPTY_SPACE;
        program->player.point.y = y;
        program->map_grid[program->player.point.x][y] = PLAYER_POSITION;
        program->player.steps += 1;
    }
}

static int check_movement(t_program *program, char next_position)
{
    if (next_position == WALL)
        return (FAIL);
    else if (next_position == COLLECTIBLE)
    {
        program->obj.collectible.qty -= 1;
        return (SUCCESS);
    }
    else if (next_position == EXIT)
    {
        if (program->obj.collectible.qty == 0)
            return (end_game(program, FOUND_EXIT));
        return (FAIL);
    }
    return (SUCCESS);
}
