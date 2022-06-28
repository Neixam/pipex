/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:07:53 by ambouren          #+#    #+#             */
/*   Updated: 2021/12/04 18:57:36 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <unistd.h>
#include <stdarg.h>

void	ft_init(t_print ft_print[9])
{
	ft_print[0] = ft_putchar;
	ft_print[1] = ft_putstr;
	ft_print[2] = ft_putadd;
	ft_print[3] = ft_putnbr;
	ft_print[4] = ft_putnbr;
	ft_print[5] = ft_putuns;
	ft_print[6] = ft_puthex;
	ft_print[7] = ft_putmajhex;
}

int	ft_choose(int choice, va_list args, t_flag flag)
{
	t_print			ft_print[8];
	int				n;
	unsigned int	un;
	char			*s;
	void			*ad;

	ft_init(ft_print);
	if (choice == 0 || choice == 3 || choice == 4 || choice >= 6)
	{
		n = va_arg(args, int);
		ad = &n;
	}
	else if (choice == 5)
	{
		un = va_arg(args, unsigned int);
		ad = &un;
	}
	else if (choice == 1)
	{
		s = va_arg(args, char *);
		ad = s;
	}
	else
		ad = va_arg(args, void *);
	return (ft_print[choice](ad, flag));
}

int	ft_format(const char *fmt, int *i, va_list args)
{
	int		ret;
	t_flag	flag;
	t_flag	null;

	null.flag = 0;
	null.size = 0;
	flag = ft_flag(fmt, i);
	ret = ft_strichr("cspdiuxX%", fmt[*i]);
	if (ret == 8)
		return (ft_putchar("%", null));
	if (ret == -1 && !fmt[*i + 1])
		return (-1);
	return (ft_choose(ret, args, flag));
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		i;
	int		size;

	if (!fmt)
		return (-1);
	va_start(args, fmt);
	size = 0;
	i = -1;
	while (fmt[++i])
	{
		if (fmt[i] == '%')
			size += ft_format(fmt, &i, args);
		else
			size += write(1, &((char *)fmt)[i], 1);
	}
	va_end(args);
	return (size);
}
