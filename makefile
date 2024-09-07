NAME = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC_PATH = src/
OBJ_PATH = obj/

SRC = cost.c \
      do_move.c \
      error.c \
      initialization.c \
      input_check_utils.c input_check.c \
      position.c \
      push.c swap.c rotate.c reverse_rotate.c \
      sort_tiny.c sort.c \
      stack_functions.c \
      utils.c \
      main.c
SRC	= $(addprefix $(SRC_PATH), $(SRC))
OBJ = $(SRC:$(SRC_PATH)%.c=$(OBJ_PATH)%.o)
INCS = -I ./includes/

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJ_PATH)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

