/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:29:03 by sde-cama          #+#    #+#             */
/*   Updated: 2022/10/18 11:59:48 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keypress_hook(int keycode, t_program *program)
{
	if (keycode == XK_Escape)
	{
		end_game(program);
	}
	draw_map(program);
	return (SUCCESS);
}
