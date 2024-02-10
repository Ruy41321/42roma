/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:20:27 by lpennisi          #+#    #+#             */
/*   Updated: 2024/02/10 15:40:26 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	ft_atol(const char *str)
{
	int		sign;
	long	result;

	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	sign = 1;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (result * sign);
}

void	error_exit(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(1);
}

void	printf_stack(t_stack_ab stacks)
{
	int	i;

	i = 0;
	ft_printf("Stack a - size: %d\n", stacks.a.size);
	while (i < stacks.a.size)
	{
		ft_printf("%d\n", stacks.a.elem[i]);
		i++;
	}
	i = 0;
	ft_printf("Stack b - size: %d\n", stacks.b.size);
	while (i < stacks.b.size)
	{
		ft_printf("%d\n", stacks.b.elem[i]);
		i++;
	}
}
