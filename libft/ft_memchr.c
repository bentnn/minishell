/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 20:38:02 by aabet             #+#    #+#             */
/*   Updated: 2020/11/08 20:38:04 by aabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char	*my_arr;
	size_t			i;

	my_arr = (unsigned char *)arr;
	i = 0;
	while (i < n)
	{
		if (my_arr[i] == (unsigned char)c)
			return ((void *)arr + i);
		i++;
	}
	return (0);
}
