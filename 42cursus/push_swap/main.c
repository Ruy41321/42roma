/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:00:42 by lpennisi          #+#    #+#             */
/*   Updated: 2024/02/07 17:06:17 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*param_parse(int argc, char **argv);
int	*argv_to_intarr(int argc, char **argv);
int	are_digits(char **argv);
int	has_duplicates(int *elems, int size);

int	main(int argc, char **argv)
{
	t_stack_ab	stacks;

	stacks.a.elem = param_parse(argc, argv);
	stacks.b.size = 0;
	stacks.a.size = argc - 1;
	printf_stack(stacks);
	return (0);
}

int	*param_parse(int argc, char **argv)
{
	int	*elems;

	if (argc == 1)
		exit (0);
	if (!are_digits(argv))
		error_exit();
	elems = argv_to_intarr(argc, argv);
	if (has_duplicates(elems, argc - 1))
	{
		free(elems);
		error_exit();
	}
	return (elems);
}

int	are_digits(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		if (ft_strlen(argv[i]) > 12)
			return (0);
		if (argv[i][0] != '-' && (argv[i][0] < 48 || argv[i][0] > 57))
			return (0);
		j = 1;
		while (argv[i][j])
		{
			if (argv[i][j] < 48 || argv[i][j] > 57)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	*argv_to_intarr(int argc, char **argv)
{
	int		*elems;
	long	temp;
	int		i;
	int		j;

	elems = (int *)malloc(sizeof(int) * (argc - 1));
	i = 0;
	j = 1;
	while (argv[j])
	{
		temp = ft_atol(argv[j]);
		if (temp > INT_MAX || temp <= INT_MIN)
		{
			free(elems);
			error_exit();
		}
		elems[i] = (int)temp;
		i++;
		j++;
	}
	return (elems);
}

int	has_duplicates(int *elems, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (elems[i] == elems[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
