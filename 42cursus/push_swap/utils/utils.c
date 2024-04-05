/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:20:27 by lpennisi          #+#    #+#             */
/*   Updated: 2024/04/05 14:40:28 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	error_exit(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(0);
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

char	**get_split(int *argc, char **argv)
{
	char	**split;
	char	**buffer;
	int		i;

	if (*argc == 2)
	{
		buffer = ft_split(argv[1], ' ');
		i = 0;
		while (buffer[++i])
			*argc += 1;
		split = (char **)malloc(sizeof(char *) * (*argc));
		split[0] = ft_strdup(buffer[0]);
		i = 0;
		while (buffer[i++])
			split[i] = buffer[i - 1];
		free(buffer);
	}
	else
	{
		split = (char **)malloc(sizeof(char *) * (*argc));
		i = -1;
		while (argv[++i])
			split[i] = ft_strdup(argv[i]);
	}
	return (split);
}

void	free_split(int size, char ***split)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free((*split)[i++]);
	}
	free(*split);
}
