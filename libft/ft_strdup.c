/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 15:55:34 by aabet             #+#    #+#             */
/*   Updated: 2020/11/11 15:55:37 by aabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*copy;

	len = ft_strlen(str);
	copy = (char *)malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (0);
	ft_strlcpy(copy, str, len + 1);
	return (copy);
}
