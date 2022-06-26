/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 19:48:27 by ambouren          #+#    #+#             */
/*   Updated: 2021/11/27 19:48:28 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;
	size_t	i;

	ret = malloc(count * size);
	if (!ret)
		return (NULL);
	i = 0;
	while (i < count * size)
		((char *)ret)[i++] = 0;
	return (ret);
}
