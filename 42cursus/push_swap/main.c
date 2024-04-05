/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:00:42 by lpennisi          #+#    #+#             */
/*   Updated: 2024/04/05 14:28:57 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*param_parse(int *argc, char **argv);
int	*argv_to_intarr(int argc, char ***argv);
int	are_digits(int argc, char **argv);
int	has_duplicates(int *elems, int size);

int	main(int argc, char **argv)
{
	t_stack_ab	stacks;

	stacks.a.elem = param_parse(&argc, argv);
	stacks.b.elem = NULL;
	stacks.b.size = 0;
	stacks.a.size = argc - 1;
	if (!is_sorted(stacks.a))
	{
		if (stacks.a.size == 2)
			sa(stacks);
		else if (stacks.a.size <= 5)
			short_stack_sort(&stacks);
		else
			sort_bitxbit(&stacks);
	}
	free(stacks.a.elem);
	free(stacks.b.elem);
	return (0);
}

int	*param_parse(int *argc, char **argv)
{
	int		*elems;
	char	**split;

	if (*argc == 1)
		exit (0);
	split = get_split(argc, argv);
	if (!are_digits(*argc, split))
	{
		free_split(*argc, &split);
		error_exit();
	}
	elems = argv_to_intarr(*argc, &split);
	free_split(*argc, &split);
	if (has_duplicates(elems, *argc - 1))
	{
		free(elems);
		error_exit();
	}
	return (elems);
}

int	are_digits(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) > 12)
			return (0);
		if ((argv[i][0] != '-' || !argv[i][1]) \
		&& (argv[i][0] < 48 || argv[i][0] > 57))
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

int	*argv_to_intarr(int argc, char ***argv)
{
	int		*elems;
	long	temp;
	int		i;

	elems = (int *)malloc(sizeof(int) * (argc - 1));
	i = 1;
	while (i < argc)
	{
		temp = ft_atol((*argv)[i]);
		if (temp > INT_MAX || temp < INT_MIN)
		{
			free_split(argc, argv);
			free(elems);
			error_exit();
		}
		elems[i - 1] = (int)temp;
		i++;
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
