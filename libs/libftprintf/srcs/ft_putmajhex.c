/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmajhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:34:32 by ambouren          #+#    #+#             */
/*   Updated: 2021/11/30 15:34:37 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putmajhex_aux(unsigned int n)
{
	int	ret;

	if (n < 16)
	{
		if (n >= 10)
			n = 'A' + n % 10;
		else
			n += '0';
		return (ft_putchar(&n));
	}
	ret = ft_putmajhex_aux(n / 16);
	return (ret + ft_putmajhex_aux(n % 16));
}

int	ft_putmajhex(void *X)
{
	int	n;

	n = *((int *)X);
	return (ft_putmajhex_aux(n));
}
