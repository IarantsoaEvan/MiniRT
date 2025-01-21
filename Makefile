CC = cc
FLAGS = -g -Wall -Wextra -Werror 
LIBFT_N = libft.a
LIBFT_D = ./libft
MLX_D = minilibx-linux
NAME = miniRT
SRC = 	parsing/init_data_utils.c\
		parsing/init_data.c\
		parsing/fill_data_utils.c\
		parsing/print_parse.c\
		parsing/add_back_lst.c\
		src/utils.c\
		src/graph_rt.c\
		src/ray_tracing.c\
		parsing/fill_plane.c\
		parsing/fill_sphere.c\
		parsing/fill_cylindre.c\
		parsing/fill_cam.c\
		parsing/fill_data.c\
		intersection/intersection.c\
		intersection/intersection_utils.c\
		intersection/sphere.c\
		src/main.c
%.o: %.c
	@$(CC) $(FLAGS) -I/usr/include -I$(MLX_D) -O3 -c $< -o $@
	@ echo "Make MLx[OK]"
all : $(NAME)
$(NAME): $(SRC)
	@make -C $(MLX_D)
	@make -C $(LIBFT_D)
	@test -e $(LIBFT_D)/$(LIBFT_N) || cp $(LIBFT_D)/$(LIBFT_N) $(LIBFT_D)
	@$(CC) $(FLAGS) $(SRC) -Lminilibx-linux -lmlx_Linux -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz -L$(LIBFT_D) -lft -o $(NAME)
	@ echo "Make[OK]"
clean:
	@make clean -C $(MLX_D) 
	@make clean -C $(LIBFT_D)
	@rm -f $(OBJ)
	@ echo "Make clean [OK]"

fclean: clean
	@make fclean -C $(LIBFT_D)
	@rm -f $(NAME)
	@ echo "Make fclean [OK]"
re: fclean all

run: re
	clear
	./$(NAME) sphere.rt

gdb: re
	clear
	gdb ./$(NAME) 

leak: re
	clear
	valgrind --leak-check=full --show-leak-kinds=all  ./$(NAME) map.rt