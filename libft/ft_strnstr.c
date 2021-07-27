/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 21:26:11 by aabet             #+#    #+#             */
/*   Updated: 2020/11/02 21:26:14 by aabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*checking(char *str1, char *str2, size_t len, int current)
{
	size_t	i;
	size_t	j;
	int		ok;

	if (str1[current] == str2[0])
	{
		i = 0;
		j = current;
		ok = 1;
		while (str2[i] && ok)
		{
			if ((len > 0 && j >= len) || str2[i] != str1[j])
				ok = 0;
			i++;
			j++;
		}
		if (ok)
		{
			while (current--)
				str1++;
			return (str1);
		}
	}
	return (0);
}

char	*ft_strnstr(char *str1, char *str2, size_t len)
{
	size_t		current;
	char		*res;

	if (str2[0] == '\0')
		return (str1);
	current = 0;
	while (((current < len && len > 0) || len < 0) && str1[current])
	{
		res = checking(str1, str2, len, current);
		if (res)
			return (res);
		current++;
	}
	return (0);
}
