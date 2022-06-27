/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:35:35 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/26 21:51:49 by ambouren         ###   ########.fr       */
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
	t_cmds	cmds;
}	        t_data;

t_data	init_data(char **env);

#endif
