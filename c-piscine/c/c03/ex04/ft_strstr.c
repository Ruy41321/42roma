/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 00:16:08 by lpennisi          #+#    #+#             */
/*   Updated: 2023/12/16 00:26:51 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	y;

	y = 0;
	if (*to_find == '\0')
		return (str);
	while (str[y] != '\0')
	{
		i = 0;
		while (str[y + i] == to_find[i])
		{
			i++;
			if (to_find[i] == '\0')
				return (&str[y]);
		}
		y++;
	}
	return (0);
}
