/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:03:42 by mruiz-sa          #+#    #+#             */
/*   Updated: 2023/01/03 11:04:12 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"
#include <stdlib.h>

int	init_state(t_state *state)
{
	ft_memset(state, 0, sizeof(t_state));
	state->map = ft_calloc(1, sizeof(t_map));
	return (1);
}

int	free_state(t_state *state)
{
	if (!state)
		return (0);
	if (state->map->fd != -1)
		close(state->map->fd);
	free(state->map);
	ft_memset(state, 0, sizeof(t_state));
	return (1);
}
