/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_op.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:23:02 by lpennisi          #+#    #+#             */
/*   Updated: 2024/02/11 12:25:37 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack_ab stacks)
{
	int	i;

	i = stacks.a.size - 1;
	while (i > 0)
	{
		swap(&stacks.a.elem[i], &stacks.a.elem[i - 1]);
		i--;
	}
	ft_printf("rra\n");
}

void	rrb(t_stack_ab stacks)
{
	int	i;

	i = stacks.b.size - 1;
	while (i > 0)
	{
		swap(&stacks.b.elem[i], &stacks.b.elem[i - 1]);
		i--;
	}
	ft_printf("rrb\n");
}

void	rrr(t_stack_ab stacks)
{
	rra(stacks);
	rrb(stacks);
}
