NAME = push_swap
FLAG = -Wall -Wextra -Werror
CC   = cc

SRCS = push_swap.c push_swap_utils.c list_function.c ft_split.c libft.c \
       operations/swap.c parser.c operations/rotate.c operations/reverse_rotate.c \
	   operations/push.c sort_utils.c algorithm.c set_lis.c
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