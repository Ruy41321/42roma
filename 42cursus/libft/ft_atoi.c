/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:43:53 by lpennisi          #+#    #+#             */
/*   Updated: 2024/01/18 14:43:55 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	is_in_strings(char c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (true);
		str++;
	}
	return (false);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	while (is_in_strings(*(char *) str, "\t\n\v\f\r "))
		str++;
	sign = 1;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		if (result * 10 < 0)
			return (-1);
		result *= 10;
		result += *str - '0';
		str++;
	}
	return (result * sign);
}
