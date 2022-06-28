/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:26:24 by ambouren          #+#    #+#             */
/*   Updated: 2021/12/07 14:49:36 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf_bonus.h"

int	ft_putchar(void *c, t_flag flag)
{
	flag.size--;
	if (!(MINUS & flag.flag))
		return (ft_putalign(flag) + write(1, c, 1));
	return (write(1, c, 1) + ft_putalign(flag));
}
