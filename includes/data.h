/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:35:35 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/29 09:08:21 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H
# include "cmd.h"

typedef struct s_data
{
	int		fd_in;
	int		fd_out;
	char	**env;
	char	**paths;
	t_cmds	cmds;
}			t_data;

t_data	init_data(char **env);

void	destroy_data(t_data *instance);

#endif
