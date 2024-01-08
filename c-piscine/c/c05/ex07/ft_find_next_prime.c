/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:36:11 by lpennisi          #+#    #+#             */
/*   Updated: 2023/12/17 14:32:33 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime_recursive(int nb, int try)
{
	if (try >= nb || try > 46340)
		return (1);
	if (nb % try != 0)
		return (ft_is_prime_recursive(nb, try + 1));
	return (0);
}

int	ft_find_next_prime(int nb)
{
	int	is_prime;
	int	i;

	i = 0;
	if (nb < 2)
		return (2);
	is_prime = ft_is_prime_recursive(nb + i, 2);
	while (is_prime == 0)
	{
		i += 1;
		is_prime = ft_is_prime_recursive(nb + i, 2);
	}
	return (nb + i);
}
