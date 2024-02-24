/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:37:15 by lpennisi          #+#    #+#             */
/*   Updated: 2024/02/22 14:28:57 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_map(t_pointers *ptr)
{
	int x;
	int y;

	y = -1;
	while (++y < ptr->map.line_num)
	{
		x = -1;
		while (++x < ptr->map.line_size)
		{
			if (ptr->map.matrix[y][x] == '1')
				mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->map.tex.wall, x * 128, y * 128);
			else if (ptr->map.matrix[y][x] == '0')
				mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->map.tex.floor, x * 128, y * 128);
			else if (ptr->map.matrix[y][x] == 'P')
				mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->map.tex.player, x * 128, y * 128);
			else if (ptr->map.matrix[y][x] == 'E')
				mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->map.tex.exit, x * 128, y * 128);
			else if (ptr->map.matrix[y][x] == 'C')
				mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->map.tex.collectable, x * 128, y * 128);
		}
	}
}

int get_line_num(char *path)
{
	int	fd;
	int	line_count;

	line_count = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (*(get_next_line(fd)))
		line_count++;
	close(fd);
	return (line_count);
}

void	set_matrix(t_pointers *ptr, char *map_path)
{
	int	i;
	int fd;

	if (ft_strncmp(ft_get_extention(map_path), "ber", 3))
		error_handling(ptr, "Wrong extention");
	ptr->map.line_num = get_line_num(map_path);
	if (ptr->map.line_num == -1)
		error_handling(ptr, "Errore nell'apertura del file");
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		error_handling(ptr, "Errore nell'apertura del file");
	ptr->map.matrix = malloc(sizeof(char *) * (ptr->map.line_num + 1));
	ptr->map.matrix[0] = ft_strdup(get_next_line(fd));
	ptr->map.line_size = ft_strlen(ptr->map.matrix[0]);
	i = 0;
	while (++i < ptr->map.line_num)
	{
		ptr->map.matrix[i] = ft_strdup(get_next_line(fd));
		if (ft_strlen((ptr->map.matrix[i])) != ptr->map.line_size)
			error_handling(ptr, "The map must be rectangular");
	}
	ptr->map.matrix[i] = NULL;
	close(fd);
}

int	has_correct_value(char cell, int *p, int *e, int *c)
{
	if (cell == 'P')
		(*p)++;
	else if (cell == 'E')
		(*e)++;
	else if (cell == 'C')
		(*c)++;
	else if (cell != '0' && cell != '1')
		return (FALSE);
	return (TRUE);
}

void	check_map_validation(t_pointers *ptr)
{
	int i;
	int j;
	int player;
	int my_exit;
	int collectable;

	player = 0;
	my_exit = 0;
	collectable = 0;
	i = -1;
	while (++i < ptr->map.line_num)
	{
		j = -1;
		while (++j < ptr->map.line_size)
		{
			check_perimeter(ptr, i, j);
			if (!has_correct_value(ptr->map.matrix[i][j], &player, &my_exit, &collectable))
				error_handling(ptr, "The only characters allow are 1, 0, P, C, E");
		}
	}
	check_path(ptr, player, my_exit, collectable);
}
