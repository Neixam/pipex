/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 08:24:34 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/29 10:35:58 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H
# include "data.h"

void	ft_error(char *err, t_data *instance, int test);

int		ft_puterror(char *err);

#endif
