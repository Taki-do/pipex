NAME = pipex
PATH_LIBFT = libft/
LIBFT_LIB = $(PATH_LIBFT)libft.a
SRC = src/main.c src/path.c
SRC_BONUS = src/main_bonus.c src/path.c src/fd_bonus.c
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror

all: $(LIBFT_LIB) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT_LIB) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT_LIB):
	make -C $(PATH_LIBFT)

bonus: $(LIBFT_LIB) $(OBJ_BONUS)
	$(CC) $(FLAGS) $(OBJ_BONUS) $(LIBFT_LIB) -o $(NAME)

clean:
	/bin/rm -f $(OBJ) $(OBJ_BONUS)
	make -C $(PATH_LIBFT) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(PATH_LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
