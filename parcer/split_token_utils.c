#include "../minishell.h"

char	*append_symbol(char *str, char ch)
{
	char	*new;
	int		i;

	new = malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!new)
		return (0);
	i = 0;
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = ch;
	new[i + 1] = '\0';
	free(str);
	return (new);
}

char	*append_dollar(const char *str, char *res, int st, t_list *env)
{
	int		i;
	char	*temp;

	i = st + 1;
	while (str[i] && str[i] != ' ' && str[i] != '\''
		&& str[i] != '$' && str[i] != '\"')
		i++;
	if (i == st + 1)
	{
		res = append_symbol(res, '$');
		return (res);
	}
	temp = ft_substr(str, st + 1, i - st - 1);
	if (temp[0] == '?' && temp[1] == '\0')
	{
		free(temp);
		temp = ft_itoa(get_exit_status());
		res = str_plus_str(res, temp);
		free(temp);
		return (res);
	}
	return (push_content(env, temp, res));
}

char	*check_simb(char *str)
{
	int		i;
	char	*res;

	i = 0;
	res = malloc(sizeof(char));
	res[0] = '\0';
	while (str[i])
	{
		if (str[i] == '\'')
			res = if_one_q(res, &i, str);
		else if (str[i] == '\"')
			res = if_two_q(res, &i, str);
		else
			res = append_symbol(res, str[i]);
		i++;
	}
	return (res);
}

char	**add_str_to_array(char **array, char *str)
{
	int		i;
	char	**res;

	if (!array || !str)
		return (0);
	i = 0;
	while (array[i] != NULL)
		i++;
	res = malloc(sizeof(char *) * (i + 2));
	if (!res)
		return (0);
	i = 0;
	while (array[i] != NULL)
	{
		res[i] = array[i];
		i++;
	}
	res[i] = check_simb(str);
	res[i + 1] = NULL;
	free(array);
	return (res);
}

char	*str_plus_str(char *dst, const char *src)
{
	int		i;
	int		j;
	char	*res;

	res = malloc(sizeof(char) * (ft_strlen(dst) + ft_strlen(src) + 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (dst[i])
	{
		res[j] = dst[i];
		i++;
		j++;
	}
	i = 0;
	while (src[i])
	{
		res[j] = src[i];
		i++;
		j++;
	}
	res[j] = '\0';
	free(dst);
	return (res);
}
