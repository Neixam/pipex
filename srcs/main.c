/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 16:11:34 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/29 10:36:31 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "parsing.h"
#include "libft.h"
#include "pipe.h"

int	main(int ac, char **av, char **env)
{
	t_data	instance;

	if (ac != 5)
		return (ft_puterror("Bad number of param\n"));
	instance = init_data(env);
	if (parsing(ac, av, &instance))
		return (1);
	piping(&instance);
	destroy_data(&instance);
	return (0);
}
