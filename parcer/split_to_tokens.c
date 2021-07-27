#include "../minishell.h"

int	count_len_when_cmd(char *str, int temp, int j, int simb)
{
	while (str[temp] && (j || simb || !is_pipe(str, temp))
		&& (j || simb || !is_redirect(str, temp)))
	{
		if (str[temp] == '\'')
		{
			if (j == 0 && ft_strchr(&str[temp + 1], '\''))
				j = 1;
			else if (j == 1)
				j = 0;
		}
		else if (str[temp] == '\"')
		{
			if (simb == 0 && ft_strchr(&str[temp + 1], '\"'))
				simb = 1;
			else if (simb == 1)
				simb = 0;
		}
		temp++;
	}
	while (str[temp - 1] == ' ')
		temp--;
	return (temp);
}

char	**add_new_cmd(char **res, char *str, int *i_stt, int temp)
{
	char	*new_str;
	int		i;
	int		j;

	i = *i_stt;
	new_str = malloc(sizeof(char) * (temp - i + 1));
	if (!new_str)
	{
		clear_str_array(res);
		return (0);
	}
	j = 0;
	while (i < temp)
		new_str[j++] = str[i++];
	new_str[j] = '\0';
	res = add_token_to_array(res, new_str);
	*i_stt = i - 1;
	return (res);
}

char	**if_cmd(char **res, char *str, int *i_stt)
{
	int	i;
	int	temp;

	i = *i_stt;
	temp = i;
	if (last_is_redir(res))
	{
		while (str[temp] && str[temp] != ' '
			&& !is_pipe(str, temp) && !is_redirect(str, temp))
			temp++;
	}
	else
		temp = count_len_when_cmd(str, temp, 0, 0);
	*i_stt = i;
	return (add_new_cmd(res, str, i_stt, temp));
}

char	**split_to_tokens(char *str)
{
	int		i;
	char	**res;

	res = malloc(sizeof(char *));
	if (!res)
		return (0);
	res[0] = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
		{
			if (is_pipe(str, i))
				res = if_pipe_stt(res);
			else if (is_redirect(str, i))
				res = if_redir_stt(res, &i, str);
			else
				res = if_cmd(res, str, &i);
		}
		i++;
	}
	return (check_multi_redir_and_pipes(res));
}
