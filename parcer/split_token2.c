#include "../minishell.h"

char	*push_content(t_list *env, char *temp, char *res)
{
	t_list	*node;
	int		i;

	node = find_env(env, temp);
	free(temp);
	if (!node)
		return (res);
	temp = (char *)node->content;
	i = 0;
	while (temp[i] && temp[i] != '=')
		i++;
	if (temp[i] == '\0')
		return (res);
	temp = ft_substr(temp, i + 1, ft_strlen(temp) - i);
	res = str_plus_str(res, temp);
	free(temp);
	return (res);
}

char	*if_one_q(char *res, int *i_st, char *str)
{
	int		j;
	char	*temp_str;
	int		i;

	i = *i_st;
	j = i + 1;
	while (str[j] && str[j] != '\'')
		j++;
	if (str[j] == '\'')
	{
		temp_str = ft_substr(str, i + 1, j - i - 1);
		res = str_plus_str(res, temp_str);
		free(temp_str);
		i = j;
	}
	else
		res = append_symbol(res, '\'');
	*i_st = i;
	return (res);
}

char	*if_two_q(char *res, int *i_st, char *str)
{
	int	j;
	int	i;

	i = *i_st;
	j = i + 1;
	while (str[j] && str[j] != '\"')
		j++;
	if (str[j] == '\"')
	{
		i++;
		while (i < j)
		{
			res = append_symbol(res, str[i]);
			i++;
		}
	}
	else
		res = append_symbol(res, str[i]);
	*i_st = i;
	return (res);
}

char	*if_single_q(char *str, int i, int *simb_st, char *res)
{
	int	simb;
	int	j;

	simb = *simb_st;
	if (str[i] == '\'' && simb == 0)
	{
		j = i + 1;
		while (str[j] && str[j] != '\'')
			j++;
		if (str[j] == '\'')
			simb = 1;
		res = append_symbol(res, '\'');
	}
	else if (str[i] == '\'' && simb == 1)
	{
		simb = 0;
		res = append_symbol(res, '\'');
	}
	*simb_st = simb;
	return (res);
}
