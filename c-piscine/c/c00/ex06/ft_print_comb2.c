/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:43:44 by lpennisi          #+#    #+#             */
/*   Updated: 2023/12/09 16:55:48 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	set_char(int n, char *c1, char *c2);
void	stamp(int i, int y);

void	ft_print_comb2(void)
{
	int	i;
	int	y;

	i = 0;
	while (i < 99)
	{
		y = 0 + i;
		while (y < 100)
		{
			if (i == y)
			{
				y++;
				continue ;
			}
			stamp(i, y);
			y++;
		}
		i++;
	}
}

void	stamp(int i, int y)
{
	char	c1;
	char	c2;

	c1 = '0';
	c2 = '0';
	set_char(i, &c1, &c2);
	write(1, &c1, 1);
	write(1, &c2, 1);
	write(1, " ", 1);
	set_char(y, &c1, &c2);
	write(1, &c1, 1);
	write(1, &c2, 1);
	if (i != 98 || y != 99)
		write(1, ", ", 2);
}

void	set_char(int n, char *c1, char *c2)
{
	int	first;

	if (n < 10)
	{
		*c1 = '0';
		*c2 = n + 48;
	}
	else
	{
		first = (int) n / 10;
		*c1 = first + 48;
		*c2 = n - (first * 10) + 48;
	}
}
