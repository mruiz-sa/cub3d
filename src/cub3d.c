/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:14:18 by mruiz-sa          #+#    #+#             */
/*   Updated: 2023/01/03 10:20:13 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

int	main(int ac, char **av)
{
	t_state	state;

	if (!init_state(&state))
		return (exit_with_error(&state, "Error initializing"));
	if (arg_checker(ac, av))
		return (1);
	parse_map(av[1], &state);
}
