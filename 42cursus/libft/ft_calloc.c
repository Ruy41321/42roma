#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*str;

	str = malloc(size * nmemb);
	if (!str)
		return (NULL);
	i = 0;
	ft_bzero(str, size * nmemb);
	return (str);
}
