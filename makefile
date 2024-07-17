NAME = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC	= src/initialization.c \
      src/input_check.c \
      src/sorting_algorithms.c \
      src/position.c \
      src/cost.c \
      src/calculate_move.c \
      src/operations.c \
      src/stack_functions.c \
      src/utils.c \
      src/error.c \
      src/main.c
SRC	= $(addprefix $(SRC_PATH), $(SRC))
OBJ = $(SRC:.c=.o)
OBJ = $(addprefix $(OBJ_PATH), $(OBJ))
INCS = -I ./includes/

all = $(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH):
	mkdr $(OBJ_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJ_PATH)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

