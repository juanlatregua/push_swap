NAME = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

SRC_PATH = src/
OBJ_PATH = obj/

SRC = do_move.c \
      initialization.c \
      input_check_utils.c input_check.c \
      position.c \
      push.c swap.c rotate.c reverse_rotate.c \
      sort_tiny.c sort.c \
      stack_functions.c \
      utils.c \
      main.c \
      cost.c
SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ   = $(SRC:.c=.o)
OBJS  = $(addprefix $(OBJ_PATH), $(OBJ))
INCS = -I ./includes/

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJ_PATH)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

