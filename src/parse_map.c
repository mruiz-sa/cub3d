/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 09:59:49 by mruiz-sa          #+#    #+#             */
/*   Updated: 2023/01/13 09:38:54 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "free_error.h"
#include<stdio.h>
#include<stdlib.h>

static void	get_map_end(t_file *file, char **my_map)
{
	int		i;
	char	*tmp;

	i = file->size - 1;
	file->map_end = -1;
	while (i > file->map_start)
	{
		if (my_map[i] == NULL)
			i--;
		tmp = ft_strtrim(my_map[i], " ");
		if (tmp[0] == '1' && file->map_end == -1)
			file->map_end = i;
		i--;
		free(tmp);
	}
}

static int	copy_just_map(t_map *map, t_file *file, char **my_map)
{
	int	i;
	int	j;

	i = file->map_start;
	j = 0;
	while (i <= file->map_end && my_map[i])
	{
		map->only_map[j] = my_map[i];
		printf("%s", map->only_map[j]);
		i++;
		j++;
	}
	return (1);
}

int	parse_map(t_state *state, t_file *file, char **my_map)
{
	t_map	map;

	(void)state;
	get_map_end(file, my_map);
	map.only_map = (char **)ft_calloc((file->map_end - file->map_start)
			+ 2, sizeof(char *));
	copy_just_map(&map, file, my_map);
	return (1);
}
