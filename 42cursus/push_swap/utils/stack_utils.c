/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:28:40 by lpennisi          #+#    #+#             */
/*   Updated: 2024/04/04 19:22:45 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

int	pop(t_stack *s)
{
	int	ret;
	int	*new_elem;
	int	i;

	s->size--;
	ret = s->elem[0];
	new_elem = (int *)malloc(sizeof(int) * (s->size));
	if (new_elem == NULL)
		exit(0);
	i = 0;
	while (i < s->size)
	{
		new_elem[i] = s->elem[i + 1];
		i++;
	}
	free(s->elem);
	s->elem = new_elem;
	return (ret);
}

void	push(t_stack *s, int value)
{
	int	*new_elem;
	int	i;

	s->size++;
	new_elem = (int *)malloc(sizeof(int) * (s->size));
	if (new_elem == NULL)
		exit(0);
	new_elem[0] = value;
	i = 1;
	while (i < s->size)
	{
		new_elem[i] = s->elem[i - 1];
		i++;
	}
	if (s->elem != NULL)
		free(s->elem);
	s->elem = new_elem;
}

int	is_sorted(t_stack a)
{
	int	i;

	i = 0;
	while (i < a.size - 1)
	{
		if (a.elem[i] > a.elem[i + 1])
			return (0);
		i++;
	}
	return (1);
}
