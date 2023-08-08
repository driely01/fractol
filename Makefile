# folders
MLX = mlx/
FRCTL = fractals/
UTLS = utils/

SRC = fractol.c \
		$(FRCTL)mandlbrotset.c \
		$(FRCTL)juliaset.c \
		$(FRCTL)burningship.c \
		$(FRCTL)bonus_of_bonus_part.c \
		$(UTLS)ft_atof.c \
		$(UTLS)fractol_useful_utils.c \
		$(MLX)events.c \
		$(MLX)colors.c \
		$(MLX)event_utils.c

OBJ =  $(SRC:.c=.o)

NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

COLOR = \033[0;36m
END = \033[0m

all: $(NAME)
	@echo ""
	@echo "\033[0;33mCompiling... $(END)"
	@echo ""
	@echo "$(COLOR)███████╗██████╗  █████╗  ██████╗████████╗ ██████╗ ██╗     $(END)"
	@echo "$(COLOR)██╔════╝██╔══██╗██╔══██╗██╔════╝╚══██╔══╝██╔═══██╗██║     $(END)"
	@echo "$(COLOR)█████╗  ██████╔╝███████║██║        ██║   ██║   ██║██║     $(END)"
	@echo "$(COLOR)██╔══╝  ██╔══██╗██╔══██║██║        ██║   ██║   ██║██║     $(END)"
	@echo "$(COLOR)██║     ██║  ██║██║  ██║╚██████╗   ██║   ╚██████╔╝███████╗$(END)"
	@echo "$(COLOR)╚═╝     ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝   ╚═╝    ╚═════╝ ╚══════╝$(END)"
	@echo "\033[0;33m==========================================================$(END)"
	@echo ""

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c fractol.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re fclean clean all