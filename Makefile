NAME		:=	so_long
INC			:=	-I include -I libft
HEADERS		:=	include/so_long.h
SRC			:=	main.c \
				map_validation.c \
				get_next_line.c \
				get_next_line_utils.c
OBJ			:= $(SRC:%.c=obj/%.o)
LIBFT		:= libft/libft.a
LIBFT_DIR	:= libft/
MLX 		:= MLX42/libmlx42.a
MLX_FLAGS 	:= -I include -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
MLX_DIR 	:= MlX42/
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror #-g -fsanitize=address

all:	$(NAME)

$(NAME): $(OBJ) $(HEADERS) $(MLX) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(INC) $(MLX) $(LIBFT) -o $(NAME) -I include -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit

obj/%.o: src/%.c
	@mkdir -p obj
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(MLX):
	@make -C $(MLX_DIR)

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@rm -rf obj
	$(MAKE) fclean -C $(MLX_DIR)
	$(MAKE) fclean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
