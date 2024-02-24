/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_extention.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:57:07 by lpennisi          #+#    #+#             */
/*   Updated: 2024/02/22 13:06:08 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_extention(char *pathfile)
{
	char	**words;
	char	*ext;

	words = ft_split(pathfile, '.');
	while (*words)
		ext = *words++;
	return (ext);
}