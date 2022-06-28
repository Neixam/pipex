/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 16:11:34 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/26 20:54:37 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "data.h"
#include "parsing.h"
#include "libft.h"

int	main(int ac, char **av, char **env)
{
	t_data	instance;

	if (ac < 5)
	{
		ft_putstr_fd("Bad number of param\n", 2);
		return (1);
	}
	instance = init_data(env);
	if (parsing(ac, av, &instance))
		return (1);
	piping(&instance);
	destroy_data(&instance);
	return (0);
}
