#include "../minishell.h"

void	replace_content(t_list *node, const char *new)
{
	char	*str;
	char	*temp;
	int		i;

	if (!node)
		return ;
	i = 0;
	temp = (char *)node->content;
	while (temp[i] && temp[i] != '=')
		i++;
	if (temp[i] == '\0')
		return ;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return ;
	ft_strlcpy(str, temp, i + 2);
	temp = ft_strjoin(str, new);
	if (temp)
	{
		free(node->content);
		node->content = temp;
	}
	free(str);
}

int	cmp_env_and_name(t_list *node, const char *name)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)node->content;
	while (str[i] && name[i])
	{
		if (str[i] != name[i])
			break ;
		i++;
	}
	return (name[i] == 0 && (str[i] == '=' || str[i] == 0));
}

t_list	*find_env(t_list *env, const char *name)
{
	t_list	*temp;

	if (!env)
		return (NULL);
	temp = env;
	while (temp)
	{
		if (cmp_env_and_name(temp, name))
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

char	*get_env_value(t_list *env, const char *name)
{
	t_list	*temp;
	int		i;
	char	*str;
	char	*res;

	temp = find_env(env, name);
	if (!temp)
		return (NULL);
	i = 0;
	str = (char *)temp->content;
	while (str[i] && str[i] != '=')
		i++;
	res = ft_substr(str, i + 1, ft_strlen(str));
	return (res);
}

char	*get_env_name(const char *str)
{
	int		i;
	char	*res;
	int		size;

	size = 0;
	while (str[size] && str[size] != '=')
		size++;
	res = malloc(sizeof(char) * (size + 1));
	i = 0;
	while (i < size)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
