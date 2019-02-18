# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeagan <jeagan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/18 04:22:20 by jeagan            #+#    #+#              #
#    Updated: 2019/02/18 04:22:23 by jeagan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=sudoku_solver

SRCS= sudoku42.c

SRCDIR = 

OBJ= $(SRCS:.c=.o)
SRCSDIR = $(addprefix $(SRCDIR), $(SRCS))

INCLUDES= -I ./inc
CFLAGS = -c -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
		gcc -o $@ $(OBJ)

$(OBJ): $(SRCSDIR)
	gcc $(CFLAGS) $^ $(INCLUDES)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.phony: $(NAME) fclean clean re all

