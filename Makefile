# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsemke <fsemke@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/29 12:20:57 by fsemke            #+#    #+#              #
#    Updated: 2022/05/23 15:26:16 by fsemke           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC =	src/so_long.c	\
		src/read.c		\
		src/map.c		\
		src/map_rules.c	\
		src/graphic.c	\
		src/xpm_init.c	\
		src/animation.c	\
		src/move.c

OBJ =	$(SRC:.c=.o)

CC = gcc
CFLAGS = -I. -ggdb3 -Wall -Wextra -Werror

MLX = mlx/libmlx_Linux.a
LIBFT = libft/libft.a

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	make -C ./mlx
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJ) $(MLX) $(LIBFT) -lXext -lX11 -lm -lz -o $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C ./libft

fclean: clean
	rm -f so_long
	make fclean -C ./libft
	make clean -C ./mlx

re: fclean all