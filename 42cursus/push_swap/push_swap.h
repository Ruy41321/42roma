/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:59:59 by lpennisi          #+#    #+#             */
/*   Updated: 2024/04/05 14:26:44 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int	size;
	int	*elem;
}	t_stack;

typedef struct s_stack_ab
{
	t_stack	a;
	t_stack	b;
}	t_stack_ab;

int		is_empty(t_stack s);
void	swap(int *a, int *b);
int		pop(t_stack *s);
void	push(t_stack *s, int value);
void	sa(t_stack_ab stacks);
void	sb(t_stack_ab stacks);
void	s(t_stack_ab stacks);
void	pa(t_stack_ab *stacks);
void	pb(t_stack_ab *stacks);
void	ra(t_stack_ab stacks);
void	rb(t_stack_ab stacks);
void	rr(t_stack_ab stacks);
void	rra(t_stack_ab stacks);
void	rrb(t_stack_ab stacks);
void	rrr(t_stack_ab stacks);
void	error_exit(void);
void	printf_stack(t_stack_ab stacks);
int		is_sorted(t_stack a);
void	tree_nums_sort(t_stack_ab stacks);
void	short_stack_sort(t_stack_ab *stacks);
void	sort_bitxbit(t_stack_ab *stacks);
char	**get_split(int *argc, char **argv);
void	free_split(int size, char ***split);

#endif