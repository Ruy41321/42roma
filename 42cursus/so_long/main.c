/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:58:00 by lpennisi          #+#    #+#             */
/*   Updated: 2024/04/04 15:28:30 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	init_pointer(t_pointers *ptr);

int	main(int argc, char **argv)
{
	t_pointers	ptr;
	char		*ext;

	init_pointer(&ptr);
	if (argc != 2)
		error_handling(&ptr, "Invalid Number of Arguments");
	ext = ft_get_extention(argv[1]);
	if (ft_strncmp(ext, "ber", 3))
		error_handling(&ptr, "Wrong extention");
	free(ext);
	set_map(&ptr, argv[1]);
	check_map_validation(&ptr);
	init_pointers(&ptr);
	load_map(&ptr);
	set_hook_and_loop(&ptr);
	return (0);
}

void	init_pointer(t_pointers *ptr)
{
	ptr->mlx = NULL;
	ptr->win = NULL;
	ptr->map.matrix = NULL;
	ptr->map.tex.collect = NULL;
}
