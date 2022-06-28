/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 21:52:16 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/26 21:52:51 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "data.h"

int		find_path(t_cmd *cmd, char **paths);

char	**ft_pathfinder(char **env);

void	piping(t_data *instance);

int		parsing(int ac, char **av, t_data *instance);

#endif
