/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prntf_ptr_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:29:54 by lpennisi          #+#    #+#             */
/*   Updated: 2024/04/03 20:00:34 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	if (num == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		write(1, "0x", 2);
		recursive_putptr(num);
	}
	return (ptr_len(num));
}
