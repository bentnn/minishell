/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 15:54:48 by aabet             #+#    #+#             */
/*   Updated: 2020/11/11 15:54:49 by aabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *buf1, const void *buf2, size_t n)
{
	size_t			i;
	unsigned char	*my_b1;
	unsigned char	*my_b2;

	i = 0;
	my_b1 = (unsigned char *)buf1;
	my_b2 = (unsigned char *)buf2;
	while (i < n)
	{
		if (my_b1[i] != my_b2[i])
			return (my_b1[i] - my_b2[i]);
		i++;
	}
	return (0);
}
