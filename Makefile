CC = gcc
NAME = ft_ls
SRC = srcs/main.c srcs/utils.c srcs/ft_ls.c srcs/parse_args.c srcs/print_data.c srcs/ft_clean_exit.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re