/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 12:47:58 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/29 09:28:18 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1024

int		ft_strclen(char *s, char c);
int		ft_decal_buff(char *buffer, int decal);
int		ft_recup_line(char **line, char *buffer);
char	*ft_panic(char *line);

#endif
