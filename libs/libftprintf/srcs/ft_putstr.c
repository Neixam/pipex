/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:27:19 by ambouren          #+#    #+#             */
/*   Updated: 2021/11/30 15:11:36 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(void *s)
{
	int	ret;

	ret = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (((char *)s)[ret])
		ret += ft_putchar(&((char *)s)[ret]);
	return (ret);
}
