/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:25:13 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/26 21:56:56 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "cmd.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "ft_error.h"

int	find_path(t_cmd *cmd, char **paths)
{
	int		i;
	char	*path;
	char	*tmp;

	i = -1;
	if (!ft_strchr(cmd->arg[0], '/'))
		while (paths[++i])
		{
			tmp = ft_strjoin(paths[i], "/");
			ft_error("malloc", 0, !tmp);
			path = ft_strjoin(tmp, cmd->arg[0]);
			free(tmp);
			ft_error("malloc", 0, !path);
			if (access(path, F_OK) != -1)
			{
				cmd->path = path;
				return (1);
			}
			free(path);
		}
	cmd->path = ft_strdup(cmd->arg[0]);
	ft_error("malloc", 0, !cmd->path);
	return (1);
}

char	**ft_pathfinder(char **env)
{
	int		i;
	char	**ret;

	i = -1;
	while (env[++i])
		if (!ft_strncmp("PATH=", env[i], 5))
			return (ft_split(env[i] + 5, ':'));
	ret = (char **)malloc(sizeof(char *));
	ft_error("malloc", 0, !ret);
	ret[0] = 0;
	return (ret);
}

void	piping(t_data *instance)
{
	int		i;

	instance->paths = ft_pathfinder(instance->env);
	ft_error("malloc", instance, !instance->paths);
	ft_error("dup2", instance, dup2(instance->fd_in, 0) == -1);
	i = -1;
	while (++i < instance->cmds.size)
	{
		if (launch_cmd(&instance->cmds.cmds[i], instance->paths))
			exit(1);
		if (instance->cmds.cmds[i].pid == 0)
		{
			close(instance->cmds.cmds[i].pipe[0]);
			if (i == instance->cmds.size - 1)
				ft_error("dup2", instance,
						instance->fd_out == -1 || dup2(instance->fd_out, 1) == -1);
			else
				ft_error("dup2", instance,
						dup2(instance->cmds.cmds[i].pipe[1], 1) == -1);
			close(instance->cmds.cmds[i].pipe[1]);
			ft_error("execve", instance, 
					execve(instance->cmds.cmds[i].path, instance->cmds.cmds[i].arg, instance->env) == -1);
		}
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

int	parsing(int ac, char **av, t_data *instance)
{
	int	i;

	instance->fd_in = open(av[1], O_RDONLY);
	if (instance->fd_in == -1)
	{
		perror("open");
		instance->fd_in = 0;
	}
	instance->fd_out = open(av[ac - 1], O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (instance->fd_out == -1)
		perror("open");
	instance->cmds.cmds = (t_cmd *)malloc(sizeof(t_cmd) * (ac - 3));
	if (!instance->cmds.cmds)
		return (1);
	i = 1;
	while (++i < ac - 1)
		if (new_cmd(&instance->cmds, av[i]))
			return (1);
	return (0);
}
