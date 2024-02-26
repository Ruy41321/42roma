/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:08:35 by lpennisi          #+#    #+#             */
/*   Updated: 2024/02/26 14:40:26 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		is_empty(char *next_line);
char	*add_buffer(char *next_line, char *buf, char **backup, int buf_size);
char	*add_char(char *s, char ch);
void	restore(char *next_line, char **backup);

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buffer;
	char		*next_line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	next_line = (char *)malloc(sizeof(char));
	*next_line = 0;
	restore(next_line, &backup);
	while (next_line[ft_strlen(next_line) - 1] != '\n')
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read > 0)
			next_line = add_buffer(next_line, buffer, &backup, bytes_read);
		if (bytes_read != BUFFER_SIZE)
			break ;
	}
	free(buffer);
	if(is_empty(next_line))
		return (NULL);
	return (next_line);
}

void	restore(char *next_line, char **backup)
{
	char	*buffer;

	if (*backup)
	{
		buffer = ft_strdup(*backup);
		free(*backup);
		*backup = (char *)malloc(sizeof(char));
		**backup = 0;
		next_line = add_buffer(next_line, buffer, backup, ft_strlen(buffer));
	}
	else
	{
		*backup = (char *)malloc(sizeof(char));
		**backup = 0;
	}
}

char	*add_buffer(char *next_line, char *buf, char **backup, int buf_size)
{
	int		n;
	int		f;

	f = 1;
	n = 0;
	while (n < buf_size)
	{
		if (f)
		{
			next_line = add_char(next_line, buf[n]);
			if (buf[n] == '\n')
				f = 0;
		}
		else
			*backup = add_char(*backup, buf[n]);
		n++;
	}
	return (next_line);
}

char	*add_char(char *s, char ch)
{
	char	*ret;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(s) + 2));
	ft_strcpy(ret, s);
	ret[ft_strlen(s)] = ch;
	ret[ft_strlen(s) + 1] = '\0';
	free(s);
	return (ret);
}

int	is_empty(char *next_line)
{
	if (ft_strlen(next_line))
		return (0);
	free (next_line);
	return (1);
}
