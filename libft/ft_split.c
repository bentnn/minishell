/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 19:19:18 by aabet             #+#    #+#             */
/*   Updated: 2020/11/16 18:47:32 by aabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	words;

	words = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || !*(s + 1)))
			words++;
		s++;
	}
	return (words);
}

static int	word_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	*free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (0);
}

static char	**create_arr(char **arr, const char *s,
		int words, char c)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (i < words)
	{
		while (*s && *s == c)
			s++;
		len = word_len(s, c);
		arr[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!arr[i])
			return (free_arr(arr));
		j = 0;
		while (j < len)
		{
			arr[i][j] = *s;
			s++;
			j++;
		}
		arr[i][j] = '\0';
		i++;
	}
	arr[i] = 0;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		words;

	if (!s)
		return (0);
	words = count_words(s, c);
	arr = (char **)malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (0);
	return (create_arr(arr, s, words, c));
}
