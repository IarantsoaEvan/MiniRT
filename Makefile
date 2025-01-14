CC = cc
FLAGS = -Wall -Wextra -Werror 
LIBFT_N = libft.a
LIBFT_D = ./libft
MLX_D = minilibx-linux
NAME = miniRT
SRC = 	src/main.c
%.o: %.c
	$(CC) $(FLAGS) -I/usr/include -I$(MLX_D) -O3 -c $< -o $@

all : $(NAME)
$(NAME): $(SRC)
	make -C $(MLX_D)
	make -C $(LIBFT_D)
	test -e $(LIBFT_D)/$(LIBFT_N) || cp $(LIBFT_D)/$(LIBFT_N) $(LIBFT_D)
	$(CC) $(FLAGS) $(SRC) -Lminilibx-linux -lmlx_Linux -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz -L$(LIBFT_D) -lft -o $(NAME)
clean:
	make clean -C $(MLX_D) 
	make clean -C $(LIBFT_D)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_D)
	rm -f $(NAME)

re: fclean all
