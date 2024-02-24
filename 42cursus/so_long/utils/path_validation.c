/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:11:06 by lpennisi          #+#    #+#             */
/*   Updated: 2024/02/22 14:10:24 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	has_path_to_exit(t_map map, int i, int j, int **visited)
{
    if (i < 0 || i >= map.line_num || j < 0 \
	|| j >= map.line_size || visited[i][j] || map.matrix[i][j] == '1')
        return (FALSE);
    visited[i][j] = 1;
    if (map.matrix[i][j] == 'E')
        return (TRUE);
    if (has_path_to_exit(map, i - 1, j, visited) || \
        has_path_to_exit(map, i + 1, j, visited) || \
        has_path_to_exit(map, i, j - 1, visited) || \
        has_path_to_exit(map, i, j + 1, visited))
        return (TRUE);
    return (FALSE);
}

int	get_collectable_recur(t_map *map, int c, int i, int j, int **visited)
{
	if (i < 0 || i >= map->line_num || j < 0 \
	|| j >= map->line_size || visited[i][j] || map->matrix[i][j] == '1')
		return (c);
    visited[i][j] = 1;
	if (map->matrix[i][j] == 'C')
		c--;
	if (c != 0)
	{
		c = get_collectable_recur(map, c, i - 1, j, visited);
		if (c != 0)
		{
			c = get_collectable_recur(map, c, i + 1, j, visited);
			if (c != 0)
			{
				c = get_collectable_recur(map, c, i, j - 1, visited);
				if (c != 0)
					c = get_collectable_recur(map, c, i, j + 1, visited);
			}
		}
	}
	return (c);
}

int	has_path_to_collectables(t_map *map, int c, int i, int j, int **visited)
{
	c = get_collectable_recur(map, c, i, j, visited);
	if (c == 0)
		return (TRUE);
	return (FALSE);
}
