NAME = push_swap
FLAG = -Wall -Wextra -Werror
CC   = cc
AR   = ar rcs

SRCS = push_swap.c push_swap_utils.c list_function.c ft_split.c 
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(FLAG) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re