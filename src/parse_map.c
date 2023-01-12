/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 09:59:49 by mruiz-sa          #+#    #+#             */
/*   Updated: 2023/01/12 12:18:00 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include<stdio.h>
#include<stdlib.h>

static void	get_map_end(t_file *file, char **my_map)
{
	int		i;
	char	*tmp;

	i = file->size - 1;
	file->map_end = -1;
	while (my_map[i])
	{
		tmp = ft_strtrim(my_map[i], " ");
		if (tmp[0] == '1' && file->map_end == -1)
			file->map_end = i;
		i--;
	}
	free(tmp);
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
		i++;
		j++;
	}
	printf("map size: %d\n", file->size);
	printf("map start: %d\n", file->map_start);
	printf("map end: %d\n", file->map_end);

	return (1);
}

int	parse_map(t_state *state, t_file *file, char **my_map)
{
	t_map	map;

	/* int i = 0; */
	(void)state;
	get_map_end(file, my_map);
	/* map.only_map = (char **)ft_calloc((file->map_end - file->map_start)
			+ 2, sizeof(char *)); */
	copy_just_map(&map, file, my_map);
	/* while (map.only_map[i])
	{
		printf("%s", map.only_map[i]);
		i++;
	} */
	return (1);
}
