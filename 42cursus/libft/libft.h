#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# undef	INT_MIN
# undef	INT_MAX

# define INT_MIN -2147483648
# define INT_MAX 2147483647

int ft_isalpha(int c);
int	ft_isdigit(int arg);
int	ft_isalnum(int arg);
int	ft_isascii(int c);
int	ft_isprint(int arg);
int	ft_strlen(const char *str);
void	*ft_memset(void *str, int c, size_t n);

#endif