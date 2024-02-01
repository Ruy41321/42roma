#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_putstr(char *s)
{
	if (!s)
		return (0);
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}

int	ptr_len(unsigned long long n)
{
	int	c;

	c = 2;
	while (n != 0)
	{
		n = n / 16;
		c++;
	}
	return (c);
}

void	recursive_putptr(unsigned long long num)
{
	if (num >= 16)
	{
		recursive_putptr(num / 16);
		recursive_putptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + '0');
		else
			ft_putchar(num - 10 + 'a');
	}
}

int	ft_putptr(unsigned long long num)
{
	write(1, "0x", 2);
	if (num == 0)
		return (write(1, "0", 1) + 2);
	else
		recursive_putptr(num);
	return (ptr_len(num));
}

int num_len(int n, int base)
{
	int c;

	c = 0;
	if (n < 0)
		c++;
	while (n)
	{
		n /= base;
		c++;
	}
	return (c);
}

int	ft_putnbr(int n)
{
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else if (n < 0)
	{
		ft_putstr("-");
		ft_putnbr(-n);
	}
	else
	{
		if (n > 9)
			ft_putnbr(n / 10);
		ft_putchar(48 + n % 10);
	}
	return (num_len(n, 10));
}

int long_long_len(long long n, int base)
{
	int c;

	c = 0;
	if (n < 0)
		c++;
	while (n)
	{
		n /= base;
		c++;
	}
	return (c);
}

int ft_put_unsnbr(unsigned int nb)
{
	if (nb == 4294967295)
		ft_putstr("4294967295");
	else
	{
		if (nb > 9)
			ft_putnbr(nb / 10);
		ft_putchar(48 + nb % 10);
	}
	return (long_long_len(nb, 10));
}

int ft_puthex(unsigned int n, char flag)
{
	if (n == 0)
		return (write(1, "0", 1));
	if (n >= 16)
	{
		ft_puthex(n / 16, flag);
		ft_puthex(n % 16, flag);
	}
	else
	{
		if (n <= 9)
			ft_putchar((n + '0'));
		else
		{
			ft_putchar((n - 10 + flag - 23));
		}
	}
	return (num_len(n, 16));
}