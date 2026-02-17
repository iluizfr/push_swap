NAME = push_swap
FLAG = -Wall -Wextra -Werror
CC   = cc

SRCS = main.c src/sort_utils.c src/utils.c src/list_function.c src/ft_split.c src/libft.c \
       operations/swap.c src/parser.c operations/rotate.c operations/reverse_rotate.c \
	   operations/push.c src/sort.c src/set_lis.c src/sort_utils2.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC)  $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAG) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

build: all clean

.PHONY: all clean fclean re