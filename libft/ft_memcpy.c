/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 16:12:42 by aabet             #+#    #+#             */
/*   Updated: 2020/11/08 16:12:43 by aabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*my_dst;
	unsigned char	*my_src;
	size_t			i;

	if (!n || (!dst && !src))
		return (dst);
	my_dst = (unsigned char *)dst;
	my_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		my_dst[i] = my_src[i];
		i++;
	}
	return (my_dst);
}
