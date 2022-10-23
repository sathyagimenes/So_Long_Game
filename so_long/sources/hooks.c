/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:29:03 by sde-cama          #+#    #+#             */
/*   Updated: 2022/10/23 15:32:54 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keypress_hook(int keycode, t_program *program)
{
	if (keycode == XK_Escape)
	{
		end_game(program);
	}
	if (keycode == XK_Up)
	{
		move_player_up(program);
	}
	if (keycode == XK_Down)
	{
		move_player_down(program);
	}
	if (keycode == XK_Right)
	{
		move_player_right(program);
	}
	if (keycode == XK_Left)
	{
		move_player_left(program);
	}
	render(program);
	return (SUCCESS);
}
