/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:29:41 by sde-cama          #+#    #+#             */
/*   Updated: 2022/10/10 22:01:01 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_program	program;

	if (!validate_argument(argc, argv[1]))
		return (FAIL);
	//load_data(&program);
	if (!read_map(argv[1], &program))
		return (FAIL);
	if (!initialize_game(&program))
		return (FAIL);
	return (SUCCESS);
}
