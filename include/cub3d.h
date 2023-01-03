/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:31:05 by mruiz-sa          #+#    #+#             */
/*   Updated: 2023/01/03 11:39:39 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define BUFFER_SIZE 100

typedef struct s_map{
	char	**cub;
	int		height;
	int		width;
	int		fd;
}	t_map;
typedef struct s_state
{
	t_map	*map;
}	t_state;

int		arg_checker(int ac, char **av);
int		parse_map(char *av, t_state *state);
void	file_error(char *av);
int		exit_with_error(t_state *state, char *str);
int		init_state(t_state *state);
int		free_state(t_state *state);

#endif