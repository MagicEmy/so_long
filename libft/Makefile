NAME := libft.a
HEADERS := libft.h
SRC :=	ft_atoi.c 	 \
		ft_bzero.c	 \
		ft_calloc.c  \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c 	 \
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_memcpy.c		\
		ft_memmove.c	\
		ft_memset.c		\
		ft_putchar_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c	\
		ft_putstr_fd.c	\
		ft_split.c		\
		ft_strchr.c		\
		ft_strdup.c		\
		ft_striteri.c	\
		ft_strjoin.c	\
		ft_strlcat.c	\
		ft_strlcpy.c	\
		ft_strlen.c		\
		ft_strmapi.c	\
		ft_strncmp.c	\
		ft_strnstr.c	\
		ft_strrchr.c	\
		ft_strtrim.c	\
		ft_substr.c		\
		ft_tolower.c	\
		ft_toupper.c
BONUS = ft_lstadd_back.c	\
		ft_lstadd_front.c	\
		ft_lstclear.c		\
		ft_lstdelone.c		\
		ft_lstiter.c		\
		ft_lstlast.c		\
		ft_lstmap.c			\
		ft_lstnew.c			\
		ft_lstsize.c
OBJ	:= $(SRC:.c=.o)
OBJBONUS = ${BONUS:.c=.o}
CC := gcc
CFLAGS := -Wall -Wextra -Werror
LIBC := ar -rcs

#//= Colors =//#
BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
RESET	:= \033[0m

all: $(NAME)
	@echo "$(BLUE)Libft Done$(RESET)"


$(NAME): $(OBJ) $(HEADERS)
	@$(LIBC) $(NAME) $(OBJ)

bonus:	${OBJ} ${OBJBONUS}
		$(LIBC) ${NAME} ${OBJ} ${OBJBONUS}

#exec: $(NAME)
#	$(CC) $(CFLAGS) -o $(NAME) main.c -lft -L. -I
#	./$(NAME)

%.o: %.c 
	@$(CC) $(CFLAGS) -o $@ -c $<
	
clean:
	@rm -f $(OBJ) ${OBJBONUS}

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
