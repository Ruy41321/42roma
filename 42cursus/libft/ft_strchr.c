#include "libft.h"

char	*strchr(const char *s, char c)
{
	int	i;

	i = 0;
	while (i < ft_strlen(s) + 1)
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}
