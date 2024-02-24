/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:55:54 by lpennisi          #+#    #+#             */
/*   Updated: 2024/02/22 14:49:46 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307

int	on_destroy(t_pointers *ptr)
{
	if (ptr->map.matrix)
		free (ptr->map.matrix);
	if (ptr->map.tex.collectable)
	{
		mlx_destroy_image(ptr->mlx, ptr->map.tex.collectable);
		mlx_destroy_image(ptr->mlx, ptr->map.tex.exit);
		mlx_destroy_image(ptr->mlx, ptr->map.tex.floor);
		mlx_destroy_image(ptr->mlx, ptr->map.tex.player);
		mlx_destroy_image(ptr->mlx, ptr->map.tex.wall);
	}
	if (ptr->win)
		mlx_destroy_window(ptr->mlx, ptr->win);
	if (ptr->mlx)
		mlx_destroy_display(ptr->mlx);
	free(ptr->mlx);
	exit (0);
	return (0);
}
 
int	on_keypress(int keysym, t_pointers *ptr)
{
	(void)ptr;
	if (keysym == ESC)
		on_destroy(ptr);
	printf("Pressed key: %d\n", keysym);
	return (0);
}
