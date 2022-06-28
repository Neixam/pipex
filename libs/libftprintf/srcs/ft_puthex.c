/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:51:42 by ambouren          #+#    #+#             */
/*   Updated: 2021/11/29 19:02:41 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_aux(unsigned int n)
{
	int	ret;

	if (n < 16)
	{
		if (n >= 10)
			n = 'a' + n % 10;
		else
			n += '0';
		return (ft_putchar(&n));
	}
	ret = ft_puthex_aux(n / 16);
	return (ret + ft_puthex_aux(n % 16));
}

int	ft_puthex(void *x)
{
	int	n;

	n = *((int *)x);
	return (ft_puthex_aux(n));
}
