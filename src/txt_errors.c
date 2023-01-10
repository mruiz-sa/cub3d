/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txt_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:58:11 by mruiz-sa          #+#    #+#             */
/*   Updated: 2023/01/10 14:18:55 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"
#include <fcntl.h>

static int	assign_route(t_txt *txt, char *line)
{
	if (line && !ft_strncmp(line, "NO", 2) && !txt->north)
		txt->north = ft_substr(line, skip(line, find_space(line)),
				ft_strlen(line) - skip(line, find_space(line)) - 1);
	else if (line && !ft_strncmp(line, "SO", 2) && !txt->south)
		txt->south = ft_substr(line, skip(line, find_space(line)),
				ft_strlen(line) - skip(line, find_space(line)) - 1);
	else if (line && !ft_strncmp(line, "WE", 2) && !txt->west)
		txt->west = ft_substr(line, skip(line, find_space(line)),
				ft_strlen(line) - skip(line, find_space(line)) - 1);
	else if (line && !ft_strncmp(line, "EA", 2) && !txt->east)
		txt->east = ft_substr(line, skip(line, find_space(line)),
				ft_strlen(line) - skip(line, find_space(line)) - 1);
	return (1);
}

static int	txt_file_check(char *route)
{
	int	fd;

	fd = open(route, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

static int	check_paths(t_txt *txt)
{
	if (!ext_checker(txt->north, ".xpm")
		|| !ext_checker(txt->south, ".xpm")
		|| !ext_checker(txt->east, ".xpm")
		|| !ext_checker(txt->west, ".xpm")
		|| !txt_file_check(txt->north)
		|| !txt_file_check(txt->south)
		|| !txt_file_check(txt->east)
		|| !txt_file_check(txt->west))
		return (0);
	return (1);
}

static int	txt_check(t_state *state, t_txt *txt, char **my_map)
{
	if (!txt->north || !txt->south || !txt->west || !txt->east)
	{
		free_txt(txt);
		free_array(my_map);
		exit_with_error(state, "ERROR: MISSING TEXTURE");
	}
	if (!check_paths(txt))
	{
		free_txt(txt);
		free_array(my_map);
		exit_with_error(state, "ERROR: INVALID TEXTURE FILE");
	}
	return (1);
}

int	txt_errors(t_state *state, char **my_map)
{
	t_txt	txt;
	t_color	color;
	int		i;

	i = 0;
	init_txt_color(&txt, &color);
	while (my_map[i])
	{
		if (my_map[i][0] == '\n')
			i++;
		else
		{
			assign_route(&txt, my_map[i]);
			if (!assign_colors(&color, my_map[i]))
			{
				free_array(my_map);
				free_txt(&txt);
				free_color(&color);
				exit_with_error(state, "ERROR: COLOUR ERROR");
			}
			i++;
		}
	}
	txt_check(state, &txt, my_map);
	free_txt(&txt);
	free_color(&color);
	return (1);
}
