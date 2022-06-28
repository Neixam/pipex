/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmajhex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 12:58:30 by ambouren          #+#    #+#             */
/*   Updated: 2021/12/07 15:24:01 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putmajhex_aux(unsigned int n, int dot_size)
{
	int		ret;
	t_flag	null;

	null.flag = 0;
	null.size = 0;
	if (n < 16 && dot_size <= 1)
	{
		if (n >= 10)
			n = 'A' + n % 10;
		else
			n += '0';
		return (ft_putchar(&n, null));
	}
	ret = ft_putmajhex_aux(n / 16, dot_size - 1);
	return (ret + ft_putmajhex_aux(n % 16, 0));
}

int	ft_putmajhex(void *X, t_flag flag)
{
	int		n;
	t_flag	null;

	null.flag = 0;
	null.size = 0;
	n = *((int *)X);
	flag.size -= ft_len((unsigned int)n, 16);
	if (HTAG & flag.flag && n)
	{
		flag.size -= 2;
		if (!(MINUS & flag.flag))
			return (ft_putalign(flag) + ft_putstr("0X", null)
				+ ft_putmajhex_aux(n, flag.dot_size));
		return (ft_putstr("0X", null) + ft_putmajhex_aux(n, flag.dot_size)
			+ ft_putalign(flag));
	}
	if (!(MINUS & flag.flag))
		return (ft_putalign(flag) + ft_putmajhex_aux(n, flag.dot_size));
	return (ft_putmajhex_aux(n, flag.dot_size) + ft_putalign(flag));
}
