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

int	main(int ac, char **av, char **env)
{
	t_data	instance;

	if (ac <= 5)
		return (1);
	instance = init_cmds(env);
	if (parsing(ac, av, &instance))
		return (1);
	piping(ac, av, &instance);
	return (0);
}
