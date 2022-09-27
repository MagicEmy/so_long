NAME		:=	so_long
INC			:=	-I include
HEADERS		:=	include/so_long.h
SRC			:=	main.c
OBJ			:= $(SRC:%.c=obj/%.o)
MLX 		:= MLX42/libmlx42.a
MLX_FLAGS 	:= -I include -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
MLX_DIR 	:= MlX42/
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror #-g -fsanitize=address

all:	$(NAME)

$(NAME): $(OBJ) $(HEADERS) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(INC) $(MLX) -o $(NAME) -I include -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit

obj/%.o: src/%.c
	@mkdir -p obj
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(MLX):
	@make -C MLX42/

clean:
	#@rm -f $(OBJ)
	@rm -rf obj
	$(MAKE) fclean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
