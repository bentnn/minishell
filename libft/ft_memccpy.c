/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 20:28:30 by aabet             #+#    #+#             */
/*   Updated: 2020/11/08 20:28:35 by aabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int ch, size_t n)
{
	unsigned char	*my_dst;
	unsigned char	*my_src;
	size_t			i;

	my_dst = (unsigned char *)dst;
	my_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		my_dst[i] = my_src[i];
		if (my_dst[i] == (unsigned char)ch)
			return ((void *)(dst + i + 1));
		i++;
	}
	return (0);
}
