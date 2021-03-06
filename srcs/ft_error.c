/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 08:24:02 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/29 10:34:52 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

void	ft_error(char *err, t_data *instance, int test)
{
	if (!test)
		return ;
	perror(err);
	destroy_data(instance);
	exit(1);
}

int	ft_puterror(char *err)
{
	ft_putstr_fd(err, 2);
	return (1);
}
