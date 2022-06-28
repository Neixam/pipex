/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:29:38 by ambouren          #+#    #+#             */
/*   Updated: 2021/11/30 15:12:10 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_aux(long n)
{
	int		ret;
	char	c;

	ret = 0;
	if (n < 0)
	{
		c = '-';
		ret += ft_putchar(&c);
		return (ret + ft_putnbr_aux(-n));
	}
	if (n < 10)
	{
		c = n + '0';
		return (ret + ft_putchar(&c));
	}
	ret += ft_putnbr_aux(n / 10);
	return (ret + ft_putnbr_aux(n % 10));
}

int	ft_putnbr(void *n)
{
	int	nb;

	nb = *((int *)n);
	return (ft_putnbr_aux(nb));
}
