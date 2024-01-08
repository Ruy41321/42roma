/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:28:38 by lpennisi          #+#    #+#             */
/*   Updated: 2023/12/02 18:38:44 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_putchar.h"
void 	writeLine(int x, char cLeft, char cRight, char mid);
void	rush(int x, int y)
{	
	const char	CORNER1 = 'A', CORNER2 = 'C', MID = 'B';
	int i = 0;
	while (i != y)
	{
		if(i==0) //caso prima riga
	            writeLine(x, CORNER1, CORNER1, MID);
		else if(i==y-1) //caso ultima riga
        	    writeLine(x, CORNER2, CORNER2, MID);
		else //caso rige centrali
	            writeLine(x, MID, MID, ' ');
		i++;
	}
}

void	writeLine(int x, char cLeft, char cRight, char mid)
{
	int i = 1;
	if (x > 0)
		ft_putchar(cLeft);
	while (x-i > 1)
	{
  		ft_putchar(mid);
		i++;
	}
	if (x > 1)
		ft_putchar(cRight);
	ft_putchar('\n');
}

