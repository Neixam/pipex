/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 09:55:27 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/29 10:39:31 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft.h"
#include "ft_error.h"
#include <stdlib.h>
#include <unistd.h>

int	find_path(t_cmd *cmd, char **paths)
{
	int		i;
	char	*path;
	char	*tmp;

	i = -1;
	if (!ft_strchr(cmd->arg[0], '/'))
	{
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

void	here_doc(t_data *instance, char **av)
{
	char	*line;

	instance->fd_in = open("here_doc", O_WRONLY | O_TRUNC | O_CREAT,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	ft_error("open", instance, instance->fd_in == -1);
	while (1)
	{
		ft_putstr_fd("heredoc> ", 1);
		line = get_next_line(0);
		ft_error("malloc", instance, !line);
		if (ft_strcmp(line, av[2]) == '\n')
			break ;
		write(instance->fd_in, line, ft_strlen(line));
	}
	close(instance->fd_in);
}

int	parsing_bonus(int ac, char **av, t_data *instance)
{
	int	i;

	if (ac < 6)
		return (ft_puterror("Few number of param\n"));
	here_doc(instance, av);
	instance->fd_in = open(av[1], O_RDONLY);
	if (instance->fd_in == -1)
		perror("open");
	instance->fd_out = open(av[ac - 1], O_WRONLY | O_APPEND | O_CREAT,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (instance->fd_out == -1)
		perror("open");
	instance->cmds.cmds = (t_cmd *)malloc(sizeof(t_cmd) * (ac - 4));
	ft_error("malloc", instance, !instance->cmds.cmds);
	instance->paths = ft_pathfinder(instance->env);
	ft_error("malloc", instance, !instance->paths);
	i = 2;
	while (++i < ac - 1)
		if (new_cmd(&instance->cmds, av[i]))
			return (1);
	return (0);
}

int	parsing(int ac, char **av, t_data *instance)
{
	int		i;

	if (!ft_strcmp("here_doc", av[1]))
		return (parsing_bonus(ac, av, instance));
	instance->fd_in = open(av[1], O_RDONLY);
	if (instance->fd_in == -1)
		perror("open");
	instance->fd_out = open(av[ac - 1], O_WRONLY | O_TRUN | O_CREAT,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (instance->fd_out == -1)
		perror("open");
	instance->cmds.cmds = (t_cmd *)malloc(sizeof(t_cmd) * (ac - 3));
	ft_error("malloc", instance, !instance->cmds.cmds);
	instance->paths = ft_pathfinder(instance->env);
	ft_error("malloc", instance, !instance->paths);
	i = 1;
	while (++i < ac - 1)
		if (new_cmd(&instance->cmds, av[i]))
			return (1);
	return (0);
}
