/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:29:03 by sde-cama          #+#    #+#             */
/*   Updated: 2022/10/28 11:14:01 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	keypress_hook(int keycode, t_program *program)
{
	if (keycode == XK_Escape)
	{
		end_game(program, ESCAPE_KEY);
	}
	if (keycode == XK_Up || keycode == XK_W || keycode == XK_w)
	{
		move_player_up(program);
	}
	if (keycode == XK_Down || keycode == XK_S || keycode == XK_s)
	{
		move_player_down(program);
	}
	if (keycode == XK_Right || keycode == XK_D || keycode == XK_d)
	{
		move_player_right(program);
	}
	if (keycode == XK_Left || keycode == XK_A || keycode == XK_a)
	{
		move_player_left(program);
	}
	render(program);
	return (SUCCESS);
}
