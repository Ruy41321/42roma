/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:08:35 by lpennisi          #+#    #+#             */
/*   Updated: 2024/02/02 16:17:27 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_empty(char *next_line);
int	is_fd_invalid(int fd);

char	*get_next_line(int fd)
{
	char		buffer;
	char		*next_line;
	int			bytes_read;

	if (fd < 0)
		return (NULL);
	next_line = (char *)malloc(sizeof(char));
	next_line[0] = '\0';
	bytes_read = read(fd, &buffer, 1);
	if (bytes_read == 1)
	{
		next_line = ft_add_char(next_line, buffer);
		while (buffer != '\n')
		{
			bytes_read = read(fd, &buffer, 1);
			if (bytes_read == 0)
				break ;
			next_line = ft_add_char(next_line, buffer);
		}
	}
	else if (is_empty(next_line) || is_fd_invalid(bytes_read))
		return (NULL);
	return (next_line);
}

int	is_empty(char *next_line)
{
	if (ft_strlen(next_line))
		return (0);
	free (next_line);
	return (1);
}

int	is_fd_invalid(int fd)
{
	if (fd < 0)
		return (1);
	return (0);
}
