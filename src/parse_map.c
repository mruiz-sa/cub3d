/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:23:08 by mruiz-sa          #+#    #+#             */
/*   Updated: 2023/01/03 11:19:14 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include <stdlib.h>
#include <fcntl.h>

int	parse_map(char *av, t_state *state)
{
	state->map->fd = -1;
	state->map->fd = open(av, O_RDONLY);
	if (state->map->fd == -1)
		file_error(av);
	exit_with_error(state, "PRUEBA");
	/* map.map = ft_split(); */
	return (1);
}
