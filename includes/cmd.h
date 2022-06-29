/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 16:11:45 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/29 09:09:06 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H
# include <sys/types.h>

typedef struct s_cmd
{
	char	**arg;
	char	*path;
	int		pipe[2];
	pid_t	pid;
}			t_cmd;

typedef struct s_cmds
{
	t_cmd	*cmds;
	int		size;
}			t_cmds;

int		new_cmd(t_cmds *cmds, char *cmd);

void	ft_free_tab(char **tab);

void	free_cmds(t_cmds *cmds);

t_cmds	init_cmds(void);

int		launch_cmd(t_cmd *cmd, char **paths);

#endif
