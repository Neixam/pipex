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
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

int	find_path(t_cmd *cmd, char **paths)
{
	int		i;
	char	*path;

	i = -1;
	while (paths[++i])
	{
		path = ft_strjoin(path[i], ft_strrchr(cmd->arg[0], '/'));
		if (!path)
			return (1);
		if (access(path, F_OK) != -1)
		{
			cmd->path = path;
			return (0);
		}
		free(path);
	}
	return (0);
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
	ret[0] = 0;
	return (ret);
}

void	piping(int ac, char **av, t_data *instance)
{
	char	**paths;
	int		i;

	paths = ft_pathfinder(instance->env);
	if (!paths)
		return (1);
	i = 0;
	while (i < instance->cmds->size)
	{
		if (launch_cmd(&instance->cmds.cmds[i], paths))
			return (1);
		if (instance->cmds.cmds[i].pid == 0)
		{
			close(instance->cmds.cmds[i].pipe[0]);
			if (i == instance->cmds->size - 1)
			{
				if (instance->fd_out != -1 && dup2(1, instance->fd_out) == -1)
				{
					perror("dup2");
					exit(1);
				}
			}
			else
			{
				if (dup2(1, instance->cmds.cmds[i].pipe[1]) == -1)
				{
					perror("dup2");
					exit(1);
				}
			}
		}
		else
		{
			close(instance->cmds.cmds[i].pipe[1]);
			if (i == 0)
			{
				if (dup2(0, instance->fd_in) == -1)
				{
					perror("dup2");
					return (1);
				}
			}
			else
			{
				if (dup2(0, instance->cmds.cmds[i].pipe[0]) == -1)
				{
					perror("dup2");
					return (1);
				}
			}
			execve(instance->cmds.cmds[i].path, instance->cmds.cmds[i].arg, instance->env);
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
	instance->fd_out = open(av[ac - 1], O_RDONLY);
	if (instance->fd_out == -1)
		perror("open");
	instance->cmds.cmds = (t_cmd *)malloc(sizeof(t_cmd) * (ac - 3));
	if (!instance->cmds.cmds)
		return (1);
	i = 1
	while (++i < ac - 1)
		if (new_cmd(&instance->cmds, av[i]))
			return (1);
	return (0);
}
