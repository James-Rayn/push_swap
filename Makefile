NAME    = push_swap

CC      = gcc
IFLAGS  = -I includes

SRCS    = srcs/main.c \
          srcs/stack.c \
          srcs/stack_utils.c \
          srcs/operations_swap.c \
          srcs/operations_push.c \
          srcs/operations_rotate.c \
          srcs/operations_rrotate.c \
          srcs/utils.c \
          srcs/sort_simple.c \
          srcs/sort_medium.c \
          srcs/sort_complex.c \
          srcs/sort_adaptive.c

OBJS    = $(SRCS:.c=.o)

all:    $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:     fclean all