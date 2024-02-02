/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:27:23 by lpennisi          #+#    #+#             */
/*   Updated: 2024/02/02 16:13:23 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
