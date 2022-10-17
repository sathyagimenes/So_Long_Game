/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:29:41 by sde-cama          #+#    #+#             */
/*   Updated: 2022/10/17 10:43:54 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_program	program;

	if (!validate_argument(argc, argv[1]))
		return (FAIL);
	if (!read_map(argv[1], &program))
		return (FAIL);
	if (!entity_validation(&program))
		return (FAIL);
	// if (!load_data(&program))
	// 	return (FAIL);
	if (!initialize_game(&program))
		return (FAIL);
	return (SUCCESS);
}
