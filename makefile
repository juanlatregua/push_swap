NAME = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC_PATH = src/
OBJ_PATH = obj/

SRC			= main.c \
			  input_check.c	inpup_check_utils.c\
			  init.c \
			  stack.c \
			  swap.c push.c rotate.c reverser_rotate.c \
			  sort_tiny.c sort.c \
			  position.c cost.c	do_move.c \
			  utils.c
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

