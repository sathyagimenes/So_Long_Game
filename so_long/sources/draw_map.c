/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:00:09 by sde-cama          #+#    #+#             */
/*   Updated: 2022/10/18 12:46:28 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void draw_map(t_program *program)
{
    void *img;
    int x;
    int y;

    img = mlx_xpm_file_to_image(program->mlx, "./images/player_down.xpm", &x, &y);
    if (img)
        mlx_put_image_to_window(program->mlx, program->mlx_win, img, 0, 0);
}
