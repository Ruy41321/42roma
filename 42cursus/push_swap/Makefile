NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ift_printf
RM = rm -f

LIBPRINTF = ./ft_printf/libftprintf.a

SRCS = main.c utils/utils.c utils/stack_utils.c utils/op.c \
	utils/reverse_rotate_op.c utils/rotate_op.c sort/long.c sort/short.c

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(LIBPRINTF):
	$(MAKE) -C ./ft_printf

$(NAME): $(OBJS) $(LIBPRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBPRINTF) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(MAKE) clean -C ./ft_printf
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./ft_printf
	$(RM) $(NAME)

re: fclean all