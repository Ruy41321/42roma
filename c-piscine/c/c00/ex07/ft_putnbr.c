/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:07:01 by lpennisi          #+#    #+#             */
/*   Updated: 2023/12/09 17:36:23 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_num_as_char(int n, char *number);
int		my_str_len(char *number);
void	reverse(char *number);

void	ft_putnbr(int nb)
{
	char	number[11];

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	write_num_as_char(nb, number);
	write(1, number, my_str_len(number));
}

void	write_num_as_char(int n, char *number)
{
	int	is_negative;
	int	i;

	if (n == 0)
	{
		number[0] = '0';
		number[1] = '\0';
		return ;
	}
	is_negative = 0;
	if (n < 0)
	{
		is_negative = 1;
		n = -n;
	}
	i = 0;
	while (n > 0)
	{
		number[i++] = '0' + (n % 10);
		n /= 10;
	}
	if (is_negative)
		number[i++] = '-';
	number[i] = '\0';
	reverse(number);
}

void	reverse(char *number)
{
	int		start;
	int		end;
	char	temp;

	start = 0;
	end = my_str_len(number) - 1;
	while (start < end)
	{
		temp = number[start];
		number[start++] = number[end];
		number[end--] = temp;
	}
}

int	my_str_len(char *number)
{
	int	len;

	len = 0;
	while (number[len] != '\0')
		len++;
	return (len);
}
