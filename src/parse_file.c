/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:23:08 by mruiz-sa          #+#    #+#             */
/*   Updated: 2023/01/05 10:45:20 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include <stdlib.h>
#include <fcntl.h>

static void	get_size(char *av, t_file *file)
{
	file->fd = open(av, O_RDONLY);
	if (file->fd == -1)
		file_error(av);
	file->size = file_size(file->fd);
	close(file->fd);
}

int	parse_file(char *av, t_state *state)
{
	t_file	file;
	char	**my_map;
	int		i;

	i = -1;
	get_size(av, &file);
	file.fd = open(av, O_RDONLY);
	my_map = (char **)ft_calloc(file.size + 1, sizeof(char *));
	if (!my_map)
		return (1);
	while (++i < file.size)
		my_map[i] = get_next_line(file.fd, 0);
	my_map[i] = 0;
	get_next_line(file.fd, 1);
	close(file.fd);
	free_array(my_map);
	exit_with_error(state, "PRUEBA");
	return (0);
}
