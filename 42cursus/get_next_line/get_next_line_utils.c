/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:27:23 by lpennisi          #+#    #+#             */
/*   Updated: 2024/04/03 14:15:40 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*buffer;

	buffer = NULL;
	buffer = (unsigned char *) str;
	while (n--)
		buffer[n] = (unsigned char) c;
	return ((void *) str);
}

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

size_t	ft_strcpy(char *dest, const char *src)
{
	size_t	c;
	size_t	i;

	i = 0;
	c = ft_strlen(src);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (c);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	dest = (char *)malloc(ft_strlen(src) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}

char	get_last(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len)
		len--;
	return (str[len]);
}
