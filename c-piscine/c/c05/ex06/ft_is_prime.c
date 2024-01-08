/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:38:48 by lpennisi          #+#    #+#             */
/*   Updated: 2023/12/16 16:36:22 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime_recursive(int nb, int try)
{
	if (try == nb || try > 46340)
		return (1);
	if (nb % try != 0)
		return (ft_is_prime_recursive(nb, try + 1));
	return (0);
}

int	ft_is_prime(int nb)
{
	if (nb < 2)
		return (0);
	return (ft_is_prime_recursive(nb, 2));
}
