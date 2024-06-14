CC = gcc
# CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDE = -I src/header

SRC_FILES = $(shell find src -name "*.c")
OBJ_FILES = $(SRC_FILES:.c=.o)

TARGET = minishell

all: $(TARGET)

$(TARGET): $(OBJ_FILES) $(LIBFT)
	$(CC) $(LIBFT) $(CFLAGS) $(OBJ_FILES) -o $@ -L $(LIBFT_DIR) $(INCLUDE) -lreadline

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -I $(LIBFT_DIR) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ_FILES)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(TARGET)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
