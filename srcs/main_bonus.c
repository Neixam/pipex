/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 09:13:19 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/29 10:36:52 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include "data.h"
#include "parsing.h"
#include "libft.h"
#include "pipe.h"
#include <unistd.h>

int	main(int ac, char **av, char **env)
{
	t_data	instance;

	if (ac < 5)
		return (ft_puterror("Few number of param\n"));
	instance = init_data(env);
	if (parsing(ac, av, &instance))
		return (1);
	piping(&instance);
	if (!ft_strcmp("here_doc", av[1]))
		ft_error("unlink", &instance, unlink(av[1]) == -1);
	destroy_data(&instance);
	return (0);
}
