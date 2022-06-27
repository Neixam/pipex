/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 16:50:48 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/26 21:04:41 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i]);
	free(tab);
}

int	launch_cmd(t_cmd *cmd, char **paths)
{
	if (pipe(cmd->pipe) == -1)
	{
		perror("pipe");
		return (1);
	}
	if (!find_cmd(cmd, paths))
		return (1);
	cmd->pid = fork();
	if (cmd->pid == -1)
	{
		perror("fork");
		return (1);
	}
	return (0);
}

int	new_cmd(t_cmds *cmds, char *cmd)
{
	int	pos;

	pos = cmds->size++;
	cmds->cmds[pos].arg = ft_split(cmd, ' ');
	if (!cmds->cmds[pos].arg)
		return (1);
	return (0);
}

t_cmds	init_cmds(void)
{
	t_cmds	ret;

	ret.size = 0;
	ret.cmds = 0;
	return (ret);
}

void	free_cmds(t_cmds *cmds)
{
	while (cmds->size)
	{
		ft_free_tab(cmds->cmds[--cmds->size].arg);

	}
	free(cmds->cmds);
}
