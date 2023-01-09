/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:43:14 by mruiz-sa          #+#    #+#             */
/*   Updated: 2023/01/09 13:10:15 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include<stdio.h>
#include<stdlib.h>

void	file_error(char *av)
{
	printf("File not found: %s\n", av);
	exit(0);
}

int	exit_with_error(t_state *state, char *str)
{
	printf("%s\n", str);
	free_state(state);
	exit(0);
	return (0);
}

int	free_textures(t_txt *txt)
{
	if (txt->north)
		free(txt->north);
	if (txt->south)
		free(txt->south);
	if (txt->east)
		free(txt->east);
	if (txt->west)
		free(txt->west);
	return (1);
}
