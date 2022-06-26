/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 13:15:24 by ambouren          #+#    #+#             */
/*   Updated: 2021/11/27 19:47:56 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_integer_len(int n)
{
	size_t	nb;
	int		len;

	nb = n;
	len = 1;
	if (n < 0)
	{
		nb = -((long)n);
		len++;
	}
	while (nb / 10)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		len;
	size_t	nb;

	if (!n)
		return (ft_strdup("0"));
	len = ft_integer_len(n);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	ret[len--] = 0;
	nb = n;
	if (n < 0)
		nb = -((long)n);
	while (nb)
	{
		ret[len--] = nb % 10 + '0';
		nb /= 10;
	}
	if (n < 0)
		ret[len] = '-';
	return (ret);
}
