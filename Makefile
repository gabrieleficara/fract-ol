# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gficara <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 17:25:41 by gficara           #+#    #+#              #
#    Updated: 2018/12/05 17:21:55 by gficara          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

LIB = fractol.a

LIB2 = libftprintf/libftprintf.a

TRH = -pthread

FRAME = -lmlx -framework OpenGL -framework AppKit

FLAGS = -Wall -Wextra -Werror

CC = gcc

INC = -I includes -I libftprintf/includes/ -I minilibx

SRC = sources/fractol.c \
	  sources/parsing.c \
	  sources/img.c \
	  sources/f_putimg.c \
	  sources/mouse_keyboard.c \
	  sources/fractal.c

OBJ = $(SRC:.c=.o)

.PHONY: clean all fclean re

all : $(NAME)

$(NAME) : $(OBJ) Makefile
	@make -C libftprintf
	@make -C minilibx
	@ar rc $(LIB) $(OBJ)
	@ranlib $(LIB)
	@$(CC) $(FLAGS) $(THR) -o $(NAME) $(LIB) $(LIB2) $(FRAME)
	@echo "Creating $(NAME)"

%.o: %.c
	@$(CC) $(FLAGS) $(TRH) $(INC) -o $@ -c $<

clean :
	@make clean -C libftprintf
	@make clean -C minilibx
	@rm -rf $(OBJ)
	@echo "Removing $(NAME) objects"

fclean : clean
	@make fclean -C libftprintf
	@rm -rf $(NAME) $(LIB)
	@echo "Removing $(LIB) and $(NAME)"

re: fclean all
