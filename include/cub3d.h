/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:31:05 by mruiz-sa          #+#    #+#             */
/*   Updated: 2023/01/09 13:14:14 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

typedef struct s_txt
{
	int		north_flg;
	int		south_flg;
	int		east_flg;
	int		west_flg;
	char	*north;
	char	*south;
	char	*east;
	char	*west;
}	t_txt;
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
int		texture_errors(t_state *state, char **my_map);
int		free_textures(t_txt *txt);
int		skip(char *str, int start);
int		find_space(char *str);

#endif