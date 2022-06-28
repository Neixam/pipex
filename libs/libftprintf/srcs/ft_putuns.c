/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 12:59:00 by ambouren          #+#    #+#             */
/*   Updated: 2021/12/04 13:03:11 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuns_aux(unsigned int n)
{
	int	ret;

	if (n < 10)
	{
		n += '0';
		return (ft_putchar(&n));
	}
	ret = ft_putuns_aux(n / 10);
	return (ret + ft_putuns_aux(n % 10));
}

int	ft_putuns(void *u)
{
	unsigned int	n;

	n = *((unsigned int *)u);
	return (ft_putuns_aux(n));
}
