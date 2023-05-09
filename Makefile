# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alabdull <@student.42abudhabi.ae>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 18:03:46 by alabdull          #+#    #+#              #
#    Updated: 2023/05/08 04:54:02 by alabdull         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC =	julia.c utils.c melbrot.c fractol.c\

OBJ = $(SRC:.c=.o)

CC = gcc -Wall -Werror -Wextra

CFLAGS =  -g3 -fsanitize=address

MLX = libmlx.dylib

LIB = Libft/libft.a

PRINTF = Libft/ft_printf/libftprintf.a

GNL = ./Libft/get_next_line/getnextline.a

%.o: %.c
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(MLX) $(OBJ)
	@make -sC ./Libft
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) $(PRINTF) $(GNL) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(MLX):
	@make -sC ./mlx

clean:
	@rm -f $(OBJ)
	@rm -f $(MLX)
	@make clean -sC ./mlx
	@make clean -sC ./Libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -sC ./Libft

re: fclean all

.PHONY: all clean fclean re
