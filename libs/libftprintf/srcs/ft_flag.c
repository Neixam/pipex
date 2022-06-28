/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 12:45:18 by ambouren          #+#    #+#             */
/*   Updated: 2021/12/07 15:25:25 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_particular_atoi(const char *s, int *i)
{
	int	val;

	val = 0;
	while (s[*i] <= '9' && s[*i] >= '0')
		val = val * 10 + s[(*i)++] - '0';
	return (val);
}

t_flag	ft_flag(const char *fmt, int *i)
{
	t_flag	flag;
	int		ret;

	flag.flag = 0;
	flag.dot_size = 0;
	(*i)++;
	while (fmt[*i])
	{
		ret = ft_strichr("0-.# +", fmt[*i]);
		if (ret == -1)
			break ;
		flag.flag |= (1 << ret);
		(*i)++;
		if (ret == 2)
			flag.dot_size = ft_particular_atoi(fmt, i);
	}
	flag.size = ft_particular_atoi(fmt, i);
	return (flag);
}
