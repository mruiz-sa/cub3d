/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:23:08 by mruiz-sa          #+#    #+#             */
/*   Updated: 2023/01/04 11:18:08 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include <stdlib.h>
#include <fcntl.h>

int	parse_map(char *av, t_state *state)
{
	t_file	file;
	char	**my_map;
	int		i;

	i = 0;
	file.fd = open(av, O_RDONLY);
	if (file.fd == -1)
		file_error(av);
	file.size = file_size(file.fd);
	my_map = (char **)ft_calloc(file.size + 1, sizeof(char *));
	if (!my_map)
		return (1);
	printf("%s\n", ft_get_next_line(file.fd));
	my_map[i] = 0;
	exit_with_error(state, "PRUEBA");
	return (0);
}
