/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 20:41:05 by aabet             #+#    #+#             */
/*   Updated: 2020/11/11 20:41:08 by aabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_len(long temp)
{
	int	i;

	i = 0;
	while (temp)
	{
		temp = temp / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	i;
	long	temp;

	temp = (long)n * -1 * (-1 + (n < 0) * 2);
	i = count_len(temp);
	str = malloc(sizeof(*str) * ((i += (n <= 0)) + 1));
	if (!str)
		return (0);
	str[i--] = '\0';
	temp = (long)n * -1 * (-1 + (n < 0) * 2);
	while (temp)
	{
		str[i--] = temp % 10 + 48;
		temp = temp / 10;
	}
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	return (str);
}
