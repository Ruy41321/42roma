/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:21:55 by lpennisi          #+#    #+#             */
/*   Updated: 2024/02/06 15:22:57 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack_ab stacks)
{
	int	i;

	i = 0;
	while (i < stacks.a.size - 1)
	{
		swap(stacks.a.elem[i], stacks.a.elem[i + 1]);
		i++;
	}
}

void	rb(t_stack_ab stacks)
{
	int	i;

	i = 0;
	while (i < stacks.b.size - 1)
	{
		swap(stacks.b.elem[i], stacks.b.elem[i + 1]);
		i++;
	}
}

void	rr(t_stack_ab stacks)
{
	ra(stacks);
	rb(stacks);
}
