/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 18:50:07 by aabet             #+#    #+#             */
/*   Updated: 2020/10/28 19:10:09 by aabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int pos)
{
	char	*str;
	char	*temp;

	str = (char *)s;
	temp = 0;
	while (*str)
	{
		if (*str == pos)
			temp = str;
		str++;
	}
	if (pos == '\0')
		temp = str;
	return (temp);
}
