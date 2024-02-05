SERVER = server
CLIENT = client

LIBFT = ./libft/libft.a

FLAGS = -Wall -Wextra -Werror -IIncludes

SRCS_SERVER = server.c
SRCS_CLIENT = client.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

RM = rm -f

all: ${SERVER} ${CLIENT}

$(LIBFT):
	$(MAKE) -C ./libft

${SERVER}: ${OBJS_SERVER} $(LIBFT)
	gcc ${FLAGS} ${OBJS_SERVER} ${LIBFT} -o ${SERVER}

${CLIENT}: ${OBJS_CLIENT} $(LIBFT)
	gcc ${FLAGS} ${OBJS_CLIENT} ${LIBFT} -o ${CLIENT}

%.o: %.c
	gcc ${FLAGS} -c $< -o $@

clean:
	$(MAKE) clean -C ./libft
	${RM} ${OBJS_SERVER} ${OBJS_CLIENT}

fclean: clean
	$(MAKE) fclean -C ./libft
	${RM} ${SERVER} ${CLIENT}
	
re: fclean all
