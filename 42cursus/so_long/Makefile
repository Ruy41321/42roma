NAME = so_long
CC = cc	
CFLAGS = -Wall -Wextra -Werror -Ift -Iincludes
RM = rm -f

LIBFT = ./libft/libft.a

SRCS = main.c

OBJS = ${SRCS:.c=.o}

ifeq ($(shell uname), Linux)
	INCLUDES = -I/usr/include -Imlx
else
	INCLUDES = -I/opt/X11/include -Imlx
endif
 
MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a
ifeq ($(shell uname), Linux)
	MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
else
	MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif

 
all: $(MLX_LIB) $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft
 
.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)
 
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX_FLAGS)
 
$(MLX_LIB):
	@make -C $(MLX_DIR)

clean:
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./mlx
	$(RM) $(OBJS)

fclean:	clean
	$(MAKE) fclean -C ./libft
	$(MAKE) fclean -C ./mlx
	$(RM) $(NAME)