/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 09:32:43 by mruiz-sa          #+#    #+#             */
/*   Updated: 2023/01/04 10:32:29 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include <unistd.h>

int	file_size(int fd)
{
	char	c;
	int		size;

	size = 0;
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			size++;
	}
	return (size);
}
