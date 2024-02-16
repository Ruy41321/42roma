NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ift
RM = rm -f

LIBFT = ./libft/libft.a

SRCS = main.c utils/utils.c utils/stack_utils.c utils/op.c \
	utils/reverse_rotate_op.c utils/rotate_op.c sort/long.c sort/short.c

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re: fclean all