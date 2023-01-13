/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:14:18 by mruiz-sa          #+#    #+#             */
/*   Updated: 2023/01/13 11:55:55 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "state.h"
#include "free_error.h"
#include "file.h"
#include<stdio.h>

int	main(int ac, char **av)
{
	t_state	state;

	if (!init_state(&state))
		return (exit_with_error(&state, "Error initializing"));
	if (arg_checker(ac, av))
		return (1);
	parse_file(av[1], &state);
	exit_without_error(&state);
}
