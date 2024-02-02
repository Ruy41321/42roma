NAME = test

SRCS = test_printf.c

LIB_PATH = /home/giggio/42roma/42cursus/ft_printf

CC		= gcc

RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

all:	
	${CC} ${CFLAGS} ${SRCS} -o ${NAME} -L${LIB_PATH} -lftprintf

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY:	all clean fclean re