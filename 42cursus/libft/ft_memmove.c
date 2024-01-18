/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:48:00 by lpennisi          #+#    #+#             */
/*   Updated: 2024/01/18 14:48:01 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*str1_buff;
	unsigned char	*str2_buff;

	str1_buff = (unsigned char *)dest;
	str2_buff = (unsigned char *)src;
	if (!dest && !src)
		return (dest);
	if (src < dest)
		while (n--)
			str1_buff[n] = str2_buff[n];
	else
		while (n--)
			*str1_buff++ = *str2_buff++;
	return (dest);
}
