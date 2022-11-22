# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 10:34:08 by mruiz-sa          #+#    #+#              #
#    Updated: 2022/11/22 10:40:53 by mruiz-sa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
SRC = 

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3
LINKS = -Lminilibx -lmlx -framework OpenGL -framework AppKit
OBJECTS = $(SRC:.c=.o)

$(NAME): $(OBJECTS)
	@clear
	@make -C minilibx
	@make bonus -C libft
	@$(CC) $(CFLAGS) $(LINKS) $(OBJECTS) libft/libft.a -I include/ -o $(NAME)
	@echo "\n\033[92m"-------------\\n👌 COMPILED 👌\\n-------------\\n"\033[0m\n"

all: $(NAME)

clean: 
	@clear
	@echo "\n\033[31m"-------------------\\n💣 DELETED FILES 💣\\n-------------------\\n"\033[0m\n"
	@rm -f $(OBJECTS)

fclean: clean
	@make clean -C ./minilibx
	@make clean -C ./libft
	@rm -rf $(NAME)
	@rm -rf so_long
	@rm -rf libmlx.a
	@rm -rf libft.a
	@rm -rf cub3d.a

re: fclean all

.PHONY: all clean re