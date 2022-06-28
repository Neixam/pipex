/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:27:19 by ambouren          #+#    #+#             */
/*   Updated: 2021/12/07 14:53:23 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_putstr(void *s, t_flag flag)
{
	int		ret;
	int		i;
	t_flag	null;

	null.flag = 0;
	null.size = 0;
	ret = 0;
	if (!s)
		return (ft_putstr("(null)", null));
	flag.size -= ft_strlen((char *)s);
	if (!(MINUS & flag.flag))
		ret += ft_putalign(flag);
	i = 0;
	while (((char *)s)[i] && (!(DOT & flag.flag) || i < flag.dot_size))
		ret += ft_putchar(&((char *)s)[i++], null);
	if (MINUS & flag.flag)
		return (ret + ft_putalign(flag));
	return (ret);
}
