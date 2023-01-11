/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:23:08 by mruiz-sa          #+#    #+#             */
/*   Updated: 2023/01/11 11:13:18 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "free_error.h"
#include "file.h"
#include <fcntl.h>

static void	get_size(char *av, t_file *file)
{
	file->fd = open(av, O_RDONLY);
	if (file->fd == -1)
		file_error(av);
	file->size = file_size(file->fd);
	close(file->fd);
}

static char	**copy_map(t_file *file, char *av)
{
	char	**my_map;
	int		i;

	i = -1;
	get_size(av, file);
	file->fd = open(av, O_RDONLY);
	my_map = (char **)ft_calloc(file->size + 1, sizeof(char *));
	if (!my_map)
		return (NULL);
	while (++i < file->size)
		my_map[i] = get_next_line(file->fd, 0);
	my_map[i] = 0;
	get_next_line(file->fd, 1);
	close(file->fd);
	return (my_map);
}

int	parse_file(char *av, t_state *state)
{
	t_file	file;
	char	**my_map;

	my_map = copy_map(&file, av);
	txt_errors(state, my_map);
	free_array(my_map);
	exit_with_error(state, "PRUEBA");
	return (0);
}
