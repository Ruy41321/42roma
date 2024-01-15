#include "libft.h"

int	ft_isprint(int arg)
{
	if (arg >= 32 && arg <= 126)
		return (1);
	return (0);
}
