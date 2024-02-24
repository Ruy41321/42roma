/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:58:00 by lpennisi          #+#    #+#             */
/*   Updated: 2024/02/22 14:07:41 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int argc, char **argv)
{
	t_pointers	ptr;
	
	if (argc != 2)
		error_handling(&ptr, "Invalid Number of Arguments");
	set_matrix(&ptr, argv[1]);
	check_map_validation(&ptr);
	init_pointers(&ptr);
	load_map(&ptr);
	set_hook_and_loop(&ptr);
	return (0);
}
