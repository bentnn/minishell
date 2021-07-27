/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 15:53:44 by aabet             #+#    #+#             */
/*   Updated: 2020/11/11 15:53:46 by aabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	else_block(unsigned char *my_dst, const unsigned char *my_src,
					   size_t n)
{
	while (n > 0)
	{
		*(my_dst) = *(my_src);
		my_dst++;
		my_src++;
		n--;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*my_dst;
	const unsigned char	*my_src;

	if (!n || dst == src)
		return (dst);
	my_dst = (unsigned char *)dst;
	my_src = (unsigned char *)src;
	i = 1;
	if (my_src < my_dst)
	{
		while (i <= n)
		{
			my_dst[n - i] = my_src[n - i];
			i++;
		}
	}
	else
	{
		else_block(my_dst, my_src, n);
	}
	return (dst);
}
