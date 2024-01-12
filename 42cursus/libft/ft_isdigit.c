#include "libft.h"

int	ft_isdigit(int arg)
{
	if (arg > 47 && arg < 58)
		return (arg);
	return (0);
}