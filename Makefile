CC      = cc
CFLAGS  = -Wall -Wextra -Werror
INCLUDES= -I./includes -I./includes_copy

OBJ_DIR = obj
NAME    = philosophers

SRCS= ./src/exit.c ./src/init_table.c ./src/input_parser.c ./src/main.c ./src/safe_malloc.c ./src/safe_mutex.c ./src/safe_thred.c ./src/simulate.c

OBJS    = $(SRCS:./src/%.c=$(OBJ_DIR)/src/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^

$(OBJ_DIR)/src/%.o: ./src/%.c | $(OBJ_DIR)/src
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/src:
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
