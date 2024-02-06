/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:35:23 by lpennisi          #+#    #+#             */
/*   Updated: 2024/02/06 13:27:45 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signum)
{
	static char	ch;
	static int	pos;
	int			bit;

	if (signum == SIGUSR1)
		bit = 0;
	else
		bit = 1;
	ch |= (bit << pos++);
	if (pos == 7)
	{
		if (ch == 0)
			ft_putchar_fd('\n', 1);
		else
			ft_putchar_fd(ch, 1);
		ch = 0;
		pos = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_handler = signal_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_printf("Error to handle SIGUSR1");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_printf("Error to handle SIGUSR2");
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
