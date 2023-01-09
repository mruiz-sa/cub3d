/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:58:11 by mruiz-sa          #+#    #+#             */
/*   Updated: 2023/01/09 13:33:30 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"
#include <fcntl.h>

static void	init_textures(t_txt *txt)
{
	txt->north = NULL;
	txt->south = NULL;
	txt->east = NULL;
	txt->west = NULL;
	txt->north_flg = 0;
	txt->south_flg = 0;
	txt->east_flg = 0;
	txt->west_flg = 0;
}

static void	assign_route(t_txt *txt, char *line)
{
	if (line && !ft_strncmp(line, "NO", 2) && !txt->north_flg)
	{
		txt->north = ft_substr(line, skip(line, find_space(line)),
				ft_strlen(line) - skip(line, find_space(line)) - 1);
		txt->north_flg = 1;
	}
	else if (line && !ft_strncmp(line, "SO", 2) && !txt->south_flg)
	{
		txt->south = ft_substr(line, skip(line, find_space(line)),
				ft_strlen(line) - skip(line, find_space(line)) - 1);
		txt->south_flg = 1;
	}
	else if (line && !ft_strncmp(line, "WE", 2) && !txt->west_flg)
	{
		txt->west = ft_substr(line, skip(line, find_space(line)),
				ft_strlen(line) - skip(line, find_space(line)) - 1);
		txt->west_flg = 1;
	}
	else if (line && !ft_strncmp(line, "EA", 2) && !txt->east_flg)
	{
		txt->east = ft_substr(line, skip(line, find_space(line)),
				ft_strlen(line) - skip(line, find_space(line)) - 1);
		txt->east_flg = 1;
	}
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

int	texture_errors(t_state *state, char **my_map)
{
	t_txt	txt;
	int		i;

	i = 0;
	(void)state;
	init_textures(&txt);
	while (my_map[i])
	{
		if (my_map[i][0] == '\n')
			i++;
		else
		{
			assign_route(&txt, my_map[i]);
			i++;
		}
	}
	if (!txt.north_flg || !txt.south_flg || !txt.west_flg || !txt.east_flg)
	{
		free_textures(&txt);
		free_array(my_map);
		exit_with_error(state, "MISSING TEXTURE");
	}
	if (!check_paths(&txt))
	{
		free_textures(&txt);
		free_array(my_map);
		exit_with_error(state, "INVALID TEXTURE FILE");
	}
	free_textures(&txt);
	return (1);
}
