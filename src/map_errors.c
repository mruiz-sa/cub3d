/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:37:24 by mruiz-sa          #+#    #+#             */
/*   Updated: 2023/01/13 12:58:29 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"
#include"free_error.h"
#include<stdio.h>

static int	map_len(char **only_map)
{
	int	i;

	i = 0;
	while (only_map[i])
		i++;
	return (i);
}

static int	check_walls(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != ' ' && str[i] != '\n'
			&& str[i] != '\t' && str[i] != '\0')
			return (0);
		i++;
	}
	return (1);
}

int	map_errors(t_state *state)
{
	if (!check_walls(state->only_map[0])
		|| !check_walls(state->only_map[map_len(state->only_map) - 1]))
		exit_with_error(state, "ERROR: WRONG MAP FORMAT");
	return (1);
}
