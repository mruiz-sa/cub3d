/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:31:05 by mruiz-sa          #+#    #+#             */
/*   Updated: 2023/01/04 11:17:49 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

typedef struct s_file
{
	int	fd;
	int	size;
}	t_file;
typedef struct s_map{
	char	**cub;
	int		height;
	int		width;
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
int		file_size(int fd);
char	*ft_get_next_line(int fd);

#endif