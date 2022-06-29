/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:41:14 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/29 10:41:22 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"
#include "ft_error.h"
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

static t_cmd	get(t_data *instance, int i)
{
	return (instance->cmds.cmds[i]);
}

void	redirect(t_data *instance, int i)
{
	t_cmd	cmd;

	cmd = get(instance, i);
	close(cmd.pipe[0]);
	if (i == instance->cmds.size - 1)
		ft_error("dup2", instance,
			instance->fd_out == -1
			|| dup2(instance->fd_out, 1) == -1);
	else
		ft_error("dup2", instance,
			dup2(cmd.pipe[1], 1) == -1);
	close(cmd.pipe[1]);
	ft_error("execve", instance,
		execve(cmd.path, cmd.arg, instance->env) == -1);
}

void	piping(t_data *instance)
{
	int		i;

	ft_error("dup2", instance, dup2(instance->fd_in, 0) == -1);
	i = -1;
	while (++i < instance->cmds.size)
	{
		if (launch_cmd(&instance->cmds.cmds[i], instance->paths))
			exit(1);
		if (instance->cmds.cmds[i].pid == 0)
			redirect(instance, i);
		else
		{
			close(instance->cmds.cmds[i].pipe[1]);
			ft_error("dup2", instance,
				dup2(instance->cmds.cmds[i].pipe[0], 0) == -1);
			close(instance->cmds.cmds[i].pipe[0]);
			waitpid(0, 0, 0);
		}
	}
}
