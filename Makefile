NAME = so_long

SRC = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c pars.c check_walls.c ft_error.c gaming.c shapes.c handle_player/draw_player.c handle_player/handle_player.c handle_player/sides.c handle_player/animate_player.c
CC = cc
MNFLAGS = -lmlx -lX11 -lXext -lm
CFLAG = -g -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAG) $(OBJ) $(MNFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAG) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
