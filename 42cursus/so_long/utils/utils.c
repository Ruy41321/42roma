/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:03:39 by lpennisi          #+#    #+#             */
/*   Updated: 2024/02/22 13:51:18 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_handling(t_pointers *ptr, char *msg)
{
	ft_putstr_fd("Error: ", STDERR_FILENO);
	ft_putstr_fd(msg,  STDERR_FILENO);
	ft_putstr_fd("\n",  STDERR_FILENO);
	on_destroy(ptr);
}

void	print_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
		ft_printf("%s\n", map[i++]);
}
