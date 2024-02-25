/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:26:59 by lpennisi          #+#    #+#             */
/*   Updated: 2024/02/02 11:27:49 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	num_len(int n, int base)
{
	int	c;

	c = 0;
	if (n <= 0)
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

int	long_long_len(long long n, int base)
{
	int	c;

	c = 0;
	if (n <= 0)
		c++;
	while (n)
	{
		n /= base;
		c++;
	}
	return (c);
}

int	ft_put_unsnbr(unsigned int nb)
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

int	ft_puthex(unsigned int n, char flag)
{
	int	c;

	c = 0;
	if (n >= 16)
	{
		c += ft_puthex(n / 16, flag);
		c += ft_puthex(n % 16, flag);
	}
	else
	{
		if (n <= 9)
			ft_putchar((n + '0'));
		else
		{
			ft_putchar((n - 10 + flag - 23));
		}
		c++;
	}
	return (c);
}
