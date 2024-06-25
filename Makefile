CC = gcc
CFLAGS = -Wall -Wextra -Werror -I/opt/homebrew/opt/readline/include
CFLAGS = -I/opt/homebrew/opt/readline/include
LDFLAGS = -L/opt/homebrew/opt/readline/lib -lreadline

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDE = -I src/header -I $(LIBFT_DIR)

SRC_FILES = $(shell find src -name "*.c")
OBJ_FILES = $(SRC_FILES:.c=.o)

TARGET = minishell

all: $(TARGET)

$(TARGET): $(OBJ_FILES) $(LIBFT)
	$(CC) $(OBJ_FILES) $(LIBFT) $(CFLAGS) $(LDFLAGS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

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