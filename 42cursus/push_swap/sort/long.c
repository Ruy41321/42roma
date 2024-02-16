/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:39:27 by lpennisi          #+#    #+#             */
/*   Updated: 2024/02/12 15:27:47 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		*array_dup(int *src, int size);
void	bubble_sort(int *array, int size);
void	convert_to_simple_numbers(t_stack_ab *stacks);

void	sort_bitxbit(t_stack_ab *stacks)
{
	int	bits_n;
	int	i;
	int	j;

	convert_to_simple_numbers(stacks);
	bits_n = 0;
	while (((stacks->a.size - 1) >> bits_n) != 0)
		bits_n++;
	i = -1;
	while (!is_sorted(stacks->a) && ++i < bits_n)
	{
		j = stacks->a.size;
		while (!is_sorted(stacks->a) && (j--))
		{
			if (((stacks->a.elem[0] >> i) & 1) == 1)
				ra(*stacks);
			else
				pb(stacks);
		}
		while (!is_empty(stacks->b))
			pa(stacks);
	}
}

int	*array_dup(int *src, int size)
{
	int		*dest;
	int		i;

	dest = (int *)malloc(sizeof(int) * size);
	if (!dest)
		exit(0);
	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

void	bubble_sort(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
				swap(array + i, array + j);
			j++;
		}
		i++;
	}
}

void	convert_to_simple_numbers(t_stack_ab *stacks)
{
	int	*copy;
	int	*copy_to_sort;
	int	i;
	int	j;

	copy = array_dup(stacks->a.elem, stacks->a.size);
	copy_to_sort = array_dup(stacks->a.elem, stacks->a.size);
	bubble_sort(copy_to_sort, stacks->a.size);
	i = 0;
	while (i < stacks->a.size)
	{
		j = 0;
		while (j < stacks->a.size)
		{
			if (copy[j] == copy_to_sort[i])
				stacks->a.elem[j] = i;
			j++;
		}
		i++;
	}
	i = 0;
	free(copy);
	free(copy_to_sort);
}
