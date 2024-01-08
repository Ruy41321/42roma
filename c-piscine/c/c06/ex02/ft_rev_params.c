/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:45:12 by lpennisi          #+#    #+#             */
/*   Updated: 2023/12/16 17:46:16 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	argc--;
	while (argc > 0)
	{
		write(1, argv[argc], ft_strlen(argv[argc]));
		write(1, "\n", 1);
		argc--;
	}
	return (0);
}
