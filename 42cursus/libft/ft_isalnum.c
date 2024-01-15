#include "libft.h"

int	ft_isalnum(int arg)
{
	if ((arg >= '0' && arg <= '9') || (arg >= 'a' && arg <= 'z')
		|| (arg >= 'A' && arg <= 'Z'))
		return (1);
	return (0);
}
