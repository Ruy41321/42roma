#include "libft.h"

char	*strchr(const char *s, char c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == c)
			return (&s[i]);
		i--;
	}
	return (NULL);
}
