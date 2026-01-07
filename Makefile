NAME = push_swap
FLAG = -Wall -Wextra -Werror
CC   = cc
AR   = ar rcs

SRCS = 
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