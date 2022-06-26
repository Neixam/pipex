/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 12:30:30 by ambouren          #+#    #+#             */
/*   Updated: 2021/11/27 18:39:47 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_count_word(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s)
	{
		if (*s != c)
		{
			len++;
			while (*s && *s != c)
				s++;
		}
		if (*s)
			s++;
	}
	return (len);
}

static char	**ft_panic(char **tab, int len)
{
	int	i;

	i = 0;
	while (i < len)
		free(tab[i++]);
	free(tab);
	return (NULL);
}

static char	*ft_recup_word(char **s, char c)
{
	int		len_word;
	char	*ret;

	len_word = 0;
	while (*(*s + len_word) && *(*s + len_word) != c)
		len_word++;
	ret = ft_substr(*s, 0, len_word);
	if (!ret)
		return (NULL);
	*s += len_word;
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	int		i_word;
	char	**ret;

	if (!s)
		return (NULL);
	ret = (char **)malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	if (!ret)
		return (NULL);
	i_word = 0;
	while (*s)
	{
		if (*s != c)
		{
			ret[i_word] = ft_recup_word((char **)&s, c);
			if (!ret[i_word++])
				return (ft_panic(ret, i_word - 1));
		}
		if (*s)
			s++;
	}
	ret[i_word] = 0;
	return (ret);
}
