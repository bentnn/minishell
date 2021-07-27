#include "../minishell.h"

char	*put_dollar_firstly(char *str, t_list *env)
{
	int		i;
	char	*res;
	int		simb;

	res = malloc(sizeof(char));
	res[0] = '\0';
	i = 0;
	simb = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			res = if_single_q(str, i, &simb, res);
		else if (str[i] == '$' && simb == 0)
		{
			res = append_dollar(str, res, i, env);
			while (str[i + 1] && str[i + 1] != ' '
				&& str[i + 1] != '$' && str[i + 1] != '\"')
				i++;
		}
		else
			res = append_symbol(res, str[i]);
		i++;
	}
	return (res);
}

int	find_i(char *str, int i)
{
	int	simb;

	while (str[i])
	{
		if (str[i] == '\'')
		{
			simb = i + 1;
			while (str[simb] && str[simb] != '\'')
				simb++;
			if (str[simb] == '\'')
				i = simb;
		}
		else if (str[i] == '\"')
		{
			simb = i + 1;
			while (str[simb] && str[simb] != '\"')
				simb++;
			if (str[simb] == '\"')
				i = simb;
		}
		else if (str[i] == ' ')
			break ;
		i++;
	}
	return (i);
}

char	**create_new_str(char **res, char *str, int i, int j)
{
	char	*temp;

	temp = ft_substr(str, j, i - j);
	res = add_str_to_array(res, temp);
	free(temp);
	return (res);
}

char	**split_token(char *string, t_list *env)
{
	char	**res;
	int		i;
	int		j;
	char	*str;

	res = malloc(sizeof(char *));
	if (!res)
		return (0);
	str = put_dollar_firstly(string, env);
	res[0] = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
		{
			j = i;
			i = find_i(str, i);
			res = create_new_str(res, str, i, j);
		}
		i += (str[i] != '\0');
	}
	free(str);
	return (res);
}
