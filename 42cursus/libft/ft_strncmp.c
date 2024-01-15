#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i])
	{
		if (i + 1 >= n)
			break ;
		i++;
		if (s1[i] == '\0' || s2[i] == '\0')
			return (s1[i] - s2[i]);
	}
	return (s1[i] - s2[i]);
}
