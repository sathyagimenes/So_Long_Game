/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 09:48:59 by sde-cama          #+#    #+#             */
/*   Updated: 2022/10/17 10:46:44 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void count_entities(t_program *program);

int entity_validation(t_program *program)
{
    count_entities(program);
    if (program->player.qty != 1)
        return (print_entity_error(INVALID_PLAYER));
    if (program->obj.collectible.qty < 1)
        return (print_entity_error(INVALID_COLLECTIBLE));
    if (program->obj.exit.qty != 1)
        return (print_entity_error(INVALID_EXIT));
    return (SUCCESS);
}

void count_entities(t_program *program)
{
    int x;
    int y;

    program->player.qty = 0;
    program->obj.collectible.qty = 0;
    program->obj.exit.qty = 0;
    x = 1;
    while (x < program->row_qnty - 1)
    {
        y = 1;
        while (y < program->column_qnty - 1)
        {
            if (program->map_grid[x][y] == PLAYER_POSITION)
                program->player.qty += 1;
            if (program->map_grid[x][y] == EXIT)
                program->obj.exit.qty += 1;
            if (program->map_grid[x][y] == COLLECTIBLE)
                program->obj.collectible.qty += 1;
            y++;
        }
        x++;
    }
}
