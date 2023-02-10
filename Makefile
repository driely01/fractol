# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 11:38:55 by del-yaag          #+#    #+#              #
#    Updated: 2023/02/10 16:49:34 by del-yaag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = fractol.c ft_atof.c juliaset.c mandlbrotset.c \
		events.c

OBJ = $(SRC:.c=.o)

NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ) fractol.h
	$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re fclean clean all