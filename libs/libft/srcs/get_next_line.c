/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 12:45:03 by ambouren          #+#    #+#             */
/*   Updated: 2021/11/29 13:49:30 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1] = "";
	char		*line;
	int			size;

	line = NULL;
	if (*buffer)
	{
		if (ft_recup_line(&line, buffer))
			return (line);
		if (!line)
			return (NULL);
	}
	while (1)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1)
			return (ft_panic(line));
		buffer[size] = 0;
		if (!size || ft_recup_line(&line, buffer) || !line)
			break ;
	}
	return (line);
}
