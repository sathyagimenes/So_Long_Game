/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:29:41 by sde-cama          #+#    #+#             */
/*   Updated: 2022/10/28 11:14:10 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_program	program;

	if (!validate_argument(argc, argv[1]))
		return (FAIL);
	if (!read_map(argv[1], &program))
		return (FAIL);
	if (!map_validation(&program))
		return (FAIL);
	load_data(&program);
	if (!initialize_game(&program))
		return (FAIL);
	return (SUCCESS);
}
