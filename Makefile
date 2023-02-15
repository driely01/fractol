# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 11:38:55 by del-yaag          #+#    #+#              #
#    Updated: 2023/02/15 18:56:24 by del-yaag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = fractol.c ft_atof.c juliaset.c mandlbrotset.c \
		events.c colors.c burningship.c fractol_useful_utils.c \
		bonus_of_bonus_part.c event_utils.c

OBJ =  $(SRC:.c=.o)

NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c fractol.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re fclean clean all