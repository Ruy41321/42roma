/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:00:42 by lpennisi          #+#    #+#             */
/*   Updated: 2024/02/06 16:00:44 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void param_check(int argc, char **argv)
{

}

int	main(int argc, char **argv)
{
	t_stack_ab stacks;

	param_check(argc, argv);
	init_stacks(stacks, argc, argv);
	return (0);
}
