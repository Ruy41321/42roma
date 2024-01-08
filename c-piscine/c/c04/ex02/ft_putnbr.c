/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:32:08 by lpennisi          #+#    #+#             */
/*   Updated: 2023/12/16 22:53:41 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int	nbr_u;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		nbr_u = (-1 * nb);
		ft_putchar('-');
	}
	else
		nbr_u = nb;
	if (nbr_u >= 10)
	{
		ft_putnbr(nbr_u / 10);
		ft_putnbr(nbr_u % 10);
	}
	else
		ft_putchar(nbr_u + '0');
}
