#include "../minishell.h"

t_list	*push_env_to_list(char **env)
{
	t_list	*first;
	t_list	*temp;
	int		i;

	if (!env)
		return (0);
	i = 0;
	first = NULL;
	while (env[i])
	{
		temp = ft_lstnew(ft_strdup(env[i]));
		if (!temp)
		{
			ft_lstclear(&first, free);
			return (0);
		}
		ft_lstadd_back(&first, temp);
		i++;
	}
	return (first);
}

void	delete_one_env(t_list **env, const char *name)
{
	t_list	*iter;
	t_list	*temp;

	if (!env || !name || !*env)
		return ;
	iter = *env;
	if (cmp_env_and_name(iter, name))
	{
		*env = iter->next;
		ft_lstdelone(iter, free);
		return ;
	}
	while (iter->next)
	{
		if (cmp_env_and_name(iter->next, name))
		{
			temp = iter->next;
			iter->next = iter->next->next;
			ft_lstdelone(temp, free);
			return ;
		}
		iter = iter->next;
	}
}

static void	delete_env_ar(char **res, int i)
{
	while (i >= 0)
	{
		free(res[i]);
		i--;
	}
	free(res);
}

char	**env_to_array(t_list *env)
{
	char	**res;
	t_list	*iter;
	int		i;

	res = malloc(sizeof(char *) * (ft_lstsize(env) + 1));
	if (!res)
		return (NULL);
	iter = env;
	i = 0;
	while (iter)
	{
		res[i] = ft_strdup((char *)iter->content);
		if (!res[i])
		{
			delete_env_ar(res, i);
			return (NULL);
		}
		iter = iter->next;
		i++;
	}
	res[i] = NULL;
	return (res);
}

void	replace_or_add_new_env(t_list **env, const char *name, char *new)
{
	t_list	*temp;
	char	*str;

	temp = find_env(*env, name);
	if (temp)
	{
		free(temp->content);
		temp->content = ft_strdup(name);
		if (new[0] != '\0')
		{
			temp->content = append_symbol(temp->content, '=');
			temp->content = str_plus_str(temp->content, new);
		}
	}
	else
	{
		str = ft_strdup(name);
		str = append_symbol(str, '=');
		str = str_plus_str(str, new);
		temp = ft_lstnew(str);
		ft_lstadd_back(env, temp);
	}
}
