/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 19:48:18 by ambouren          #+#    #+#             */
/*   Updated: 2021/11/27 19:48:20 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*ret;
	int		i;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!ret)
		return (NULL);
	i = -1;
	while (((char *)s1)[++i])
		ret[i] = ((char *)s1)[i];
	ret[i] = 0;
	return (ret);
}
