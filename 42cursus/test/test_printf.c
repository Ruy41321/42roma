#include <stdio.h>
#include "ft_printf.h"

int main()
{
	int n = 124162;

	printf("stringa: %d\n", n);
	printf("%d\n", ft_printf("stringa: %d\n", n));
}