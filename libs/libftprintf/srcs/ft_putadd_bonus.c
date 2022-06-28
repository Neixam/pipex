/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadd_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:11:15 by ambouren          #+#    #+#             */
/*   Updated: 2021/12/07 15:17:46 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putadd_aux(unsigned long ad)
{
	int		ret;
	t_flag	null;

	null.flag = 0;
	null.size = 0;
	if (ad < 16)
	{
		if (ad >= 10)
			ad = 'a' + ad % 10;
		else
			ad += '0';
		return (ft_putchar(&ad, null));
	}
	ret = 0;
	ret += ft_putadd_aux(ad / 16);
	return (ret + ft_putadd_aux(ad % 16));
}

#ifdef LINUX

int	ft_putadd(void *a, t_flag flag)
{
	unsigned long	ad;
	int				ret;
	t_flag			null;

	null.flag = 0;
	null.size = 0;
	if (!a)
		return (ft_putstr("(nil)", null));
	ad = (unsigned long)a;
	flag.size -= 2;
	flag.size -= ft_len(ad, 16);
	ret = 0;
	if (!(MINUS & flag.flag))
		ret += ft_putalign(flag);
	ret += ft_putstr("0x", null);
	ret += ft_putadd_aux(ad);
	if (MINUS & flag.flag)
		return (ret + ft_putalign(flag));
	return (ret);
}

#else

int	ft_putadd(void *a, t_flag flag)
{
	unsigned long	ad;
	int				ret;
	t_flag			null;

	null.flag = 0;
	null.size = 0;
	if (!a)
		return (ft_putstr("0x0", null));
	ad = (unsigned long)a;
	flag.size -= 2;
	flag.size -= ft_len(ad, 16);
	ret = 0;
	if (!(MINUS & flag.flag))
		ret += ft_putalign(flag);
	ret += ft_putstr("0x", null);
	ret += ft_putadd_aux(ad);
	if (MINUS & flag.flag)
		return (ret + ft_putalign(flag));
	return (ret);
}

#endif
