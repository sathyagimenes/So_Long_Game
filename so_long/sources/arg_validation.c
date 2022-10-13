/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:06:11 by sde-cama          #+#    #+#             */
/*   Updated: 2022/10/07 20:32:53 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_argument(int argc, char *argv)
{
	char	*find_ber;
	char	*wrong_berr;

	if (argc == 2)
	{
		find_ber = ft_strnstr((const char *)argv, ".ber", ft_strlen(argv) + 1);
		if (!find_ber)
			return (print_error_message(INVALID_TYPE_BER));
		wrong_berr = ft_strnstr(
				(const char *)argv,
				".berr",
				ft_strlen(argv) + 1);
		if (wrong_berr)
			return (print_error_message(INVALID_TYPE_BER));
		return (SUCCESS);
	}
	return (print_error_message(INVALID_ARGUMENT));
}
