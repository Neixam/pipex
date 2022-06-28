/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 13:03:20 by ambouren          #+#    #+#             */
/*   Updated: 2021/12/07 14:53:52 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putuns_aux(unsigned int n, int dot_size)
{
	int		ret;
	t_flag	null;

	null.flag = 0;
	null.size = 0;
	if (n < 10 && dot_size <= 1)
	{
		n += '0';
		return (ft_putchar(&n, null));
	}
	ret = ft_putuns_aux(n / 10, dot_size - 1);
	return (ret + ft_putuns_aux(n % 10, 0));
}

int	ft_putuns(void *u, t_flag flag)
{
	unsigned int	n;

	n = *((unsigned int *)u);
	flag.size -= ft_len(n, 10);
	if (!(MINUS & flag.flag))
		return (ft_putalign(flag) + ft_putuns_aux(n, flag.dot_size));
	return (ft_putuns_aux(n, flag.dot_size) + ft_putalign(flag));
}
