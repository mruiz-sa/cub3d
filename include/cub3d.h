/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:31:05 by mruiz-sa          #+#    #+#             */
/*   Updated: 2023/01/10 11:59:02 by mruiz-sa         ###   ########.fr       */
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
	int				fd;
	int				size;
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
int		ext_checker(char *str, char *ext);
int		parse_file(char *av, t_state *state);
void	file_error(char *av);
void	free_array(char **array);
int		exit_with_error(t_state *state, char *str);
int		init_state(t_state *state);
int		free_state(t_state *state);
int		file_size(int fd);
char	*get_next_line(int fd, int flag);
int		txt_errors(t_state *state, char **my_map);
int		free_txt(t_txt *txt);
int		free_color(t_color *color);
int		skip(char *str, int start);
int		find_space(char *str);
void	init_txt_color(t_txt *txt, t_color *color);
int		find_char_from(char *str, char c, int start);
int		assign_colors(t_color *color, char *line);

#endif