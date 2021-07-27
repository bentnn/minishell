/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:48:21 by aabet             #+#    #+#             */
/*   Updated: 2021/07/27 18:25:45 by bmohor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				minus;
	unsigned long	result;

	minus = 1;
	result = 0;
	while (*str && (*str == ' ' || *str == '\t' || *str == '\r' || *str == '\n'
			|| *str == '\v' || *str == '\f'))
		str++;
	if (*str && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			minus = -1;
		str++;
	}
	while (*str && *str >= 48 && *str <= 57)
	{
		if (result > LONG_MAX && minus == 1)
			return (-1);
		if (result > LONG_MAX && minus == -1)
			return (0);
		result = result * 10 + (*str - 48);
		str++;
	}
	return ((int)result * minus);
}
