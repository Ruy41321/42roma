#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	dest = (char *)malloc(ft_strlen(src) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}
