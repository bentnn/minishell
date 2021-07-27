/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 16:15:18 by aabet             #+#    #+#             */
/*   Updated: 2020/11/08 16:15:19 by aabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;

	i = 0;
	if (!dst || !src)
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	srclen = ft_strlen(src);
	while (i < (size - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (srclen < size - 1)
		dst[srclen] = '\0';
	else
		dst[size - 1] = '\0';
	return (srclen);
}
