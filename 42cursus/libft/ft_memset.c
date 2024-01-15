#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*buffer;

	buffer = NULL;
	buffer = (unsigned char *) str;
	while (n--)
		buffer[n] = (unsigned char) c;
	return ((void *) str);
}
