NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_PATH = minilibx-linux/
MLX_NAME = libmlx_Linux.a
MLX = $(MLX_PATH)$(MLX_NAME)
MLX_FLAGS = -L$(MLX_PATH) -lmlx_Linux -lX11 -lXext -lm

MLX_URL = https://cdn.intra.42.fr/document/document/31570/minilibx-linux.tgz
MLX_DIR = minilibx-linux


SRCS = main.c \
	   init.c \
	   events.c \
	   render.c \
	   math_utils.c \
	   string_utils.c

OBJS = $(SRCS:.c=.o)

all: $(MLX_DIR) $(NAME)

$(NAME): $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)
	@echo "\033[32mFractol compiled successfully!\033[0m"

$(MLX): $(MLX_DIR)
	@echo "\033[33mCompiling minilibx...\033[0m"
	@make -C $(MLX_PATH)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(MLX_DIR):
	wget -q $(MLX_URL) -O minilibx-linux.tgz 
	tar -xzf minilibx-linux.tgz
	rm -f minilibx-linux.tgz

clean:
	@echo "\033[33mCleaning object files...\033[0m"
	@make -C $(MLX_PATH) clean
	@rm -f $(OBJS)

fclean: clean
	@echo "\033[33mRemoving executable...\033[0m"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re