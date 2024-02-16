/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:06:37 by lpennisi          #+#    #+#             */
/*   Updated: 2024/02/11 12:25:14 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack_ab stacks)
{
	if (stacks.a.size > 1)
		swap(&stacks.a.elem[0], &stacks.a.elem[1]);
	ft_printf("sa\n");
}

void	sb(t_stack_ab stacks)
{
	if (stacks.b.size > 1)
		swap(&stacks.b.elem[0], &stacks.b.elem[1]);
	ft_printf("sb\n");
}

void	ss(t_stack_ab stacks)
{
	sa(stacks);
	sb(stacks);
}

void	pa(t_stack_ab *stacks)
{
	if (!is_empty(stacks->b))
		push(&stacks->a, pop(&stacks->b));
	ft_printf("pa\n");
}

void	pb(t_stack_ab *stacks)
{
	if (!is_empty(stacks->a))
		push(&stacks->b, pop(&stacks->a));
	ft_printf("pb\n");
}
