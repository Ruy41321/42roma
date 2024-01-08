/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:11:25 by lpennisi          #+#    #+#             */
/*   Updated: 2023/12/18 18:36:36 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_len_array(int size, char **array)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (i < size)
	{
		len += ft_strlen(array[i]);
		i++;
	}
	return (len);
}

void	ft_concat(char *str, char **strs, int size, char *sep)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		while (*strs[i] != '\0')
		{
			*str = *strs[i];
			strs[i]++;
			str++;
		}
		j = 0;
		while (sep[j] != '\0' && i + 1 < size)
		{
			*str = sep[j];
			j++;
			str++;
		}
		i++;
	}
	*str = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;

	if (size == 0)
	{
		str = malloc(1);
		if (!str)
			return (0);
		*str = '\0';
		return (str);
	}
	str = (char *)malloc(ft_len_array(size, strs)
			+ ((size) * ft_strlen(sep)));
	ft_concat(str, strs, size, sep);
	return (str);
}
