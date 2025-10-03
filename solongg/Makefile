NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = get_next_line/get_next_line_utils.c get_next_line/get_next_line.c \
	   main.c \
       control_map1.c \
	   free_and_exit.c \
	   free_and_exit1.c \
	   game_loop.c \
	   init_struct.c \
	   player_move.c \
	   read_map.c \
	   read_map1.c \
	   render.c \
	   validate_maps.c \
	   validate_maps1.c \
	   validate_maps2.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX_A = $(MLX_DIR)/libmlx_Linux.a   # hazır libmlx_Linux.a kullan
MLX_LINK = -lXext -lX11 -lm
INCS = -I$(MLX_DIR) -I$(LIBFT_DIR) -Iincludes

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX_A)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_A) $(MLX_LINK) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# MinilibX'i sadece var olan arşiv ile kullan
$(MLX_A):
	@echo "Using precompiled MinilibX: $(MLX_A)"

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
