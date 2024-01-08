/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:06:25 by lpennisi          #+#    #+#             */
/*   Updated: 2023/12/09 16:42:05 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_comb(int c1, int c2, int c3);

void	ft_print_comb(void)
{
	int	i;
	int	y;
	int	j;

	i = 0;
	while (i < 8)
	{
		y = i + 1;
		while (y < 9)
		{
			j = y + 1;
			while (j < 10)
			{
				write_comb(i, y, j);
				j++;
			}
			y++;
		}
		i++;
	}
}

void	write_comb(int c1, int c2, int c3)
{
	char	c;

	c = c1 + 48;
	write(1, &c, 1);
	c = c2 + 48;
	write(1, &c, 1);
	c = c3 + 48;
	write(1, &c, 1);
	if (c1 != 7 || c2 != 8 || c3 != 9)
		write(1, ", ", 2);
}
