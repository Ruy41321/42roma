/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:08:35 by lpennisi          #+#    #+#             */
/*   Updated: 2024/02/21 14:11:59 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_add_char(char *s, char ch)
{
	char	*ret;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(s) + 2));
	ft_strcpy(ret, s);
	ret[ft_strlen(s)] = ch;
	ret[ft_strlen(s) + 1] = '\0';
	free(s);
	return (ret);
}

char	*get_next_line(int fd)
{
	char		buffer;
	char		*next_line;
	int			bytes_read;

	if (fd < 0)
		return (0);
	next_line = (char *)malloc(sizeof(char));
	next_line[0] = '\0';
	bytes_read = read(fd, &buffer, 1);
	if (bytes_read != 0)
	{
		next_line = ft_add_char(next_line, buffer);
		while (buffer != '\n')
		{
			bytes_read = read(fd, &buffer, 1);
			if (bytes_read == 0)
				break ;
			if (buffer != '\n')
				next_line = ft_add_char(next_line, buffer);
		}
	}
	return (next_line);
}
