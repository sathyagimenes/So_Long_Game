/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:26:02 by sde-cama          #+#    #+#             */
/*   Updated: 2022/10/17 10:43:24 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int print_error_message(t_error error_type)
{
	char *message;
	char *valid_example;

	message = "No error";
	if (error_type == INVALID_ARGUMENT)
		message = "Invalid quantity of arguments.\n";
	else if (error_type == INVALID_TYPE_BER)
		message = "Invalid type of map file. Map file must be .ber\n";
	valid_example = "Valid example: ./so_long maps/map_small.ber\n";
	ft_printf(RED "Error: %s%s" RESET, message, valid_example);
	return (FAIL);
}

int print_map_error(t_error error_type)
{
	char *message;

	message = "Undefined";
	if (error_type == INVALID_SIZE)
		message = "Wrong map size and/or shape.\n";
	if (error_type == INVALID_MAP)
		message = "Could not read map.\n";
	if (error_type == INVALID_SAVE)
		message = "Could not save map. Check file and size of rows\n";
	if (error_type == INVALID_WALL)
		message = "Wrong wall. Map must be surrounded by walls(1).\n";
	if (error_type == INVALID_ENTITIES)
		message = "Wrong entitie. Accepted entities: 0,1,P,C,E.\n";
	ft_printf(RED "Error: %s" RESET, message);
	return (FAIL);
}

int print_entity_error(t_error error_type)
{
	char *message;

	message = "No error";
	if (error_type == INVALID_PLAYER)
		message = "Invalid quantity of players(P). Must have one single player.\n";
	else if (error_type == INVALID_COLLECTIBLE)
		message = "Invalid quantity of collectibles(C). Must have at least one.\n";
	else if (error_type == INVALID_EXIT)
		message = "Invalid quantity of exits(E). Must have one single exit.\n";
	ft_printf(RED "Error: %s" RESET, message);
	return (FAIL);
}