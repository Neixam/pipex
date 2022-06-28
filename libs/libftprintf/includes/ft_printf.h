/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:19:14 by ambouren          #+#    #+#             */
/*   Updated: 2021/11/30 15:42:25 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef int	(*t_print)(void *);

int	ft_putchar(void *c);
int	ft_putstr(void *s);
int	ft_putnbr(void *n);
int	ft_puthex(void *x);
int	ft_putuns(void *u);
int	ft_putmajhex(void *x);
int	ft_putadd(void *p);
int	ft_printf(const char *fmt, ...);
int	ft_strichr(char *s, char c);

#endif
