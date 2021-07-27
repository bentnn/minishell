#include "../minishell.h"

int	is_pipe(const char *str, int i)
{
	return (str[i] == '|');
}

int	is_redirect(const char *str, int i)
{
	return (str[i] == '>' || str[i] == '<');
}

int	is_not_cmd(const char *str)
{
	return (ft_strncmp(str, "<", 2) == 0 || ft_strncmp(str, ">", 2) == 0
		|| ft_strncmp(str, ">>", 3) == 0 || ft_strncmp(str, "<<", 2) == 0
		|| ft_strncmp(str, "|", 2) == 0);
}

char	**add_token_to_array(char **array, char *str)
{
	char	**res;
	int		i;

	i = 0;
	while (array[i])
		i++;
	res = malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (array[i])
	{
		res[i] = array[i];
		i++;
	}
	res[i++] = str;
	res[i] = NULL;
	free(array);
	return (res);
}

int	last_is_redir(char **array)
{
	int	i;

	if (array[0] == NULL)
		return (0);
	i = 0;
	while (array[i + 1] != NULL)
		i++;
	return (is_redirect(array[i], 0));
}
