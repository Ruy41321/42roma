/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:22:18 by lpennisi          #+#    #+#             */
/*   Updated: 2024/02/02 11:22:56 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	ft_putchar(char ch);
int	ft_putstr(char *s);
int	ft_putptr(unsigned long long num);
int	ft_putnbr(int n);
int	ft_put_unsnbr(unsigned int n);
int	ft_puthex(unsigned int n, char flag);

#endif