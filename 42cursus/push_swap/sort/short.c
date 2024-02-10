/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:37:41 by lpennisi          #+#    #+#             */
/*   Updated: 2024/02/10 22:43:42 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_between_2nd_3rd(t_stack_ab *stacks);

void	tree_nums_sort(t_stack_ab stacks)
{
	while (!is_sorted(stacks.a))
	{
		if (stacks.a.elem[0] > stacks.a.elem[1] \
		&& stacks.a.elem[1] < stacks.a.elem[2] \
		&& stacks.a.elem[0] > stacks.a.elem[2])
			ft_printf("%s", ra(stacks));
		else if (stacks.a.elem[0] < stacks.a.elem[1] \
		&& stacks.a.elem[1] > stacks.a.elem[2] \
		&& stacks.a.elem[0] > stacks.a.elem[2])
			ft_printf("%s", rra(stacks));
		else
			ft_printf("%s", sa(stacks));
	}
}

void	short_stack_sort(t_stack_ab *stacks)
{
	while (stacks->a.size > 3)
		ft_printf("%s", pb(stacks));
	tree_nums_sort(*stacks);
	while (!is_empty(stacks->b))
	{
		if (stacks->b.elem[0] < stacks->a.elem[0])
			ft_printf("%s", pa(stacks));
		else if (stacks->b.elem[0] < stacks->a.elem[1])
		{
			ft_printf("%s", pa(stacks));
			ft_printf("%s", sa(*stacks));
		}
		else if (stacks->b.elem[0] > stacks->a.elem[stacks->a.size - 1])
		{
			ft_printf("%s", pa(stacks));
			ft_printf("%s", ra(*stacks));
		}
		else
			push_between_2nd_3rd(stacks);
	}
	if (!is_sorted(stacks->a))
		error_exit();
}

void	push_between_2nd_3rd(t_stack_ab *stacks)
{
	if (stacks->b.elem[0] < stacks->a.elem[2] && stacks->a.size == 4)
	{
		ft_printf("%s", ra(*stacks));
		ft_printf("%s", pa(stacks));
		ft_printf("%s", sa(*stacks));
		ft_printf("%s", rra(*stacks));
	}
	else
	{
		ft_printf("%s", rra(*stacks));
		ft_printf("%s", pa(stacks));
		ft_printf("%s", ra(*stacks));
		ft_printf("%s", ra(*stacks));
	}
}
