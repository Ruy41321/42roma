/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:37:41 by lpennisi          #+#    #+#             */
/*   Updated: 2024/02/12 15:28:04 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_to_3nd_and_4rd(t_stack_ab *stacks);

void	tree_nums_sort(t_stack_ab stacks)
{
	while (!is_sorted(stacks.a))
	{
		if (stacks.a.elem[0] > stacks.a.elem[1] \
		&& stacks.a.elem[1] < stacks.a.elem[2] \
		&& stacks.a.elem[0] > stacks.a.elem[2])
			ra(stacks);
		else if (stacks.a.elem[0] < stacks.a.elem[1] \
		&& stacks.a.elem[1] > stacks.a.elem[2] \
		&& stacks.a.elem[0] > stacks.a.elem[2])
			rra(stacks);
		else
			sa(stacks);
	}
}

void	short_stack_sort(t_stack_ab *stacks)
{
	while (stacks->a.size > 3)
		pb(stacks);
	tree_nums_sort(*stacks);
	while (!is_empty(stacks->b) && stacks->a.size < 5)
	{
		if (stacks->b.elem[0] < stacks->a.elem[0])
			pa(stacks);
		else if (stacks->b.elem[0] < stacks->a.elem[1])
		{
			pa(stacks);
			sa(*stacks);
		}
		else if (stacks->b.elem[0] > stacks->a.elem[stacks->a.size - 1])
		{
			pa(stacks);
			ra(*stacks);
		}
		else
			push_to_3nd_and_4rd(stacks);
	}
}

void	push_to_3nd_and_4rd(t_stack_ab *stacks)
{
	if (stacks->b.elem[0] < stacks->a.elem[2] && stacks->a.size == 4)
	{
		ra(*stacks);
		pa(stacks);
		sa(*stacks);
		rra(*stacks);
	}
	else
	{
		rra(*stacks);
		pa(stacks);
		ra(*stacks);
		ra(*stacks);
	}
}
