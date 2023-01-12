/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:31:05 by mruiz-sa          #+#    #+#             */
/*   Updated: 2023/01/12 11:49:46 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

typedef struct s_txt
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
}	t_txt;

typedef struct s_color
{
	int		floor[3];
	int		ceiling[3];
	char	*ceiling_line;
	char	*floor_line;
}	t_color;
typedef struct s_file
{
	int	fd;
	int	size;
	int	map_start;
	int	map_end;	
}	t_file;
typedef struct s_map
{
	char	**only_map;
}	t_map;
typedef struct s_state
{
}	t_state;

int		arg_checker(int ac, char **av);
char	*get_next_line(int fd);
void	init_txt_color(t_txt *txt, t_color *color);
int		assign_colors(t_color *color, char *line);
int		parse_map(t_state *state, t_file *file, char **my_map);
#endif