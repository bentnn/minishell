#include "../minishell.h"

char	**if_multi_redir(char **array, int i)
{
	set_exit_status(258);
	if (array[i + 1])
		printf("%s: syntax error near unexpected token '%s'\n",
			   OUR_SHELL, array[i + 1]);
	else
		printf("%s: syntax error near unexpected token 'newline'\n",
			   OUR_SHELL);
	clear_str_array(array);
	return (NULL);
}

char	**check_multi_redir_and_pipes(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (is_redirect(array[i], 0) && (!array[i + 1]
				|| is_not_cmd(array[i + 1])))
			return (if_multi_redir(array, i));
		else if (is_pipe(array[i], 0) && (i == 0 || !array[i + 1]
				|| is_pipe(array[i + 1], 0)))
		{
			printf("%s: syntax error near unexpected token '|'\n", OUR_SHELL);
			clear_str_array(array);
			set_exit_status(258);
			return (NULL);
		}
		i++;
	}
	array = change_args(array);
	if (array[0] == NULL)
	{
		free(array);
		return (NULL);
	}
	return (array);
}

char	**if_pipe_stt(char **res)
{
	char	*new_str;

	new_str = malloc(sizeof(char) * 2);
	if (!new_str)
	{
		clear_str_array(res);
		return (0);
	}
	new_str[0] = '|';
	new_str[1] = '\0';
	res = add_token_to_array(res, new_str);
	return (res);
}

char	**if_redir_stt(char **res, int *i_stt, char *str)
{
	int		temp;
	char	*new_str;
	int		j;
	int		i;

	i = *i_stt;
	temp = 1;
	temp += ((str[i] == '>' && str[i + 1] == '>')
			|| (str[i] == '<' && str[i + 1] == '<'));
	new_str = malloc(sizeof(char) * (temp + 1));
	j = 0;
	while (temp)
	{
		new_str[j++] = str[i++];
		temp--;
	}
	new_str[j] = '\0';
	res = add_token_to_array(res, new_str);
	*i_stt = i - 1;
	return (res);
}
