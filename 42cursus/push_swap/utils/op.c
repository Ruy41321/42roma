/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:06:37 by lpennisi          #+#    #+#             */
/*   Updated: 2024/02/10 19:15:24 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*sa(t_stack_ab stacks)
{
	if (stacks.a.size > 1)
		swap(&stacks.a.elem[0], &stacks.a.elem[1]);
	return ("sa\n");
}

char	*sb(t_stack_ab stacks)
{
	if (stacks.b.size > 1)
		swap(&stacks.b.elem[0], &stacks.b.elem[1]);
	return ("sb\n");
}

char	*ss(t_stack_ab stacks)
{
	sa(stacks);
	sb(stacks);
	return ("ss\n");
}

char	*pa(t_stack_ab *stacks)
{
	if (!is_empty(stacks->b))
		push(&stacks->a, pop(&stacks->b));
	return ("pa\n");
}

char	*pb(t_stack_ab *stacks)
{
	if (!is_empty(stacks->a))
		push(&stacks->b, pop(&stacks->a));
	return ("pb\n");
}
