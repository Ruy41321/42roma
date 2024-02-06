/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:35:52 by lpennisi          #+#    #+#             */
/*   Updated: 2024/02/06 13:26:37 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_msg(int pid, char *msg)
{
	int	pos;
	int	f;

	f = 1;
	while (f)
	{
		if (*msg == '\0')
			f = 0;
		pos = 0;
		while (pos < 7)
		{
			if ((*msg >> pos) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(300);
			pos++;
		}
		msg++;
	}
	ft_printf("send\n");
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		ft_printf("Wrong number of parameter\n");
	send_msg(ft_atoi(argv[1]), argv[2]);
	return (0);
}
