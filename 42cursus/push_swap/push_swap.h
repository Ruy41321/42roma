/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:59:59 by lpennisi          #+#    #+#             */
/*   Updated: 2024/02/07 17:05:26 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MIN -2147483648
# define INT_MAX 2147483647

# include "ft_printf.h"
# include <stdlib.h>

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
int		pop(t_stack s);
void	push(t_stack s, int value);
void	sa(t_stack_ab stacks);
void	sb(t_stack_ab stacks);
void	ss(t_stack_ab stacks);
void	pa(t_stack_ab stacks);
void	pb(t_stack_ab stacks);
void	ra(t_stack_ab stacks);
void	rb(t_stack_ab stacks);
void	rr(t_stack_ab stacks);
void	rra(t_stack_ab stacks);
void	rrb(t_stack_ab stacks);
void	rrr(t_stack_ab stacks);
long	ft_atol(const char *str);
int		ft_strlen(const char *str);
void	error_exit(void);
void	printf_stack(t_stack_ab stacks);

#endif