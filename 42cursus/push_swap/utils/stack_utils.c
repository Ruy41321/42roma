/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:28:40 by lpennisi          #+#    #+#             */
/*   Updated: 2024/02/06 15:58:08 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void new_stacks(t_stack_ab stacks, int argc, char **argv)
{
	stacks.b.size = 0;
	stacks.a.size = 0;
	while (stacks.a.size < argc - 1)
	{
		stacks.a.elem[stacks.a.size] = argv[stacks.a.size + 1];
		stacks.a.size++;
	}
	return (stacks);
}

int	is_empty(t_stack s)
{
	if (s.size == 0)
		return (1);
	return (0);
}

void	swap(int *a, int *b)
{
	int	buf;

	buf = *a;
	*a = *b;
	*b = buf;
}

int	pop(t_stack s)
{
	int	ret;
	int	*new_elem;
	int	i;

	ret = s.elem[0];
	new_elem = (int *)malloc(sizeof(int) * (s.size - 1));
	i = 0;
	while (i < s.size - 1)
	{
		new_elem[i] = s.elem[i + 1];
		i++;
	}
	free(s.elem);
	s.elem = new_elem;
	s.size--;
	return (ret);
}

void	push(t_stack s, int value)
{
	int	*new_elem;
	int	i;

	new_elem = (int *)malloc(sizeof(int) * (s.size + 1));
	new_elem[0] = value;
	i = 1;
	while (i < s.size + 1)
	{
		new_elem[i] = s.elem[i];
		i++;
	}
	free(s.elem);
	s.elem = new_elem;
	s.size++;
}
