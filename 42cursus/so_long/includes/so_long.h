/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:49:58 by lpennisi          #+#    #+#             */
/*   Updated: 2024/02/22 14:14:39 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_texture
{
	void	*wall;
	void	*floor;
	void	*exit;
	void	*player;
	void	*collectable;
	int		size;
}	t_texture;

typedef struct s_map
{
	t_texture	tex;
	char	**matrix;
	int	line_size;
	int	line_num;
}	t_map;

typedef struct s_pointers
{
	void		*mlx;
	void		*win;
	t_map		map;
}	t_pointers;

# define WALL_PATH "./assets/myAssets/wall.xpm"
# define FLOOR_PATH "./assets/myAssets/floor.xpm"
# define EXIT_PATH "./assets/myAssets/exit.xpm"
# define PLAYER_PATH "./assets/myAssets/player.xpm"
# define COLLECTABLE_PATH "./assets/myAssets/collectable.xpm"

# define TRUE 1
# define FALSE 0

void	error_handling(t_pointers *ptr, char *msg);
void	set_hook_and_loop(t_pointers *ptr);
void	init_pointers(t_pointers *ptr);
void	init_textures(t_pointers *ptr);
int		on_destroy(t_pointers *ptr);
int		on_keypress(int keysym, t_pointers *ptr);
void	load_map(t_pointers *ptr);
void	print_map(char **map);
void	check_perimeter(t_pointers *ptr, int i, int j);
void	check_path(t_pointers *ptr,int p, int e, int c);
int		has_path_to_collectables(t_map *map, int c, int i, int j, int **visited);
int		has_path_to_exit(t_map map, int i, int j, int **visited);
void	set_matrix(t_pointers *ptr, char *map_path);
void	check_map_validation(t_pointers *ptr);

#endif