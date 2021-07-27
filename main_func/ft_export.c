#include "../minishell.h"

void	ft_export_create_new_env(char **args, int i, int j, t_data *data)
{
	char	*name;
	t_list	*temp;

	if (args[i][j] == '=')
		name = ft_substr(args[i], 0, j);
	else
		name = ft_strdup(args[i]);
	temp = find_env(data->env, name);
	if (temp)
	{
		free(temp->content);
		temp->content = ft_strdup(args[i]);
	}
	else
	{
		temp = ft_lstnew(ft_strdup(args[i]));
		ft_lstadd_back(&data->env, temp);
	}
	free(name);
}

void	ft_export_creating_env(char **args, t_data *data)
{
	int	i;
	int	j;

	i = 1;
	while (args[i])
	{
		j = 0;
		while (args[i][j] && args[i][j] != '=' && args[i][j] != '$')
		{
			j++;
		}
		if (args[i][j] == '$' || j == 0)
		{
			ft_putstr_fd(OUR_SHELL, STDERR_FILENO);
			ft_putstr_fd(": export: '", STDERR_FILENO);
			ft_putstr_fd(args[i], STDERR_FILENO);
			ft_putendl_fd("': not a valid identifier", STDERR_FILENO);
			i++;
			set_exit_status(1);
			continue ;
		}
		ft_export_create_new_env(args, i, j, data);
		i++;
	}
}

void	ft_export_print_with_content(char **array, int i, int j, int out)
{
	ft_putstr_fd("=\"", out);
	j++;
	while (array[i][j])
	{
		if (array[i][j] == '$' || array[i][j] == '\\'
			|| array[i][j] == '\'' || array[i][j] == '\"')
			ft_putchar_fd('\\', out);
		ft_putchar_fd(array[i][j], out);
		j++;
	}
	ft_putstr_fd("\"", out);
}

void	ft_export_print(t_data *data, int out)
{
	char	**array;
	int		i;
	int		j;

	array = env_to_array(data->env);
	array = sort_array_env(array);
	i = 0;
	while (array[i])
	{
		ft_putstr_fd("declare -x ", out);
		j = 0;
		while (array[i][j] && array[i][j] != '=')
		{
			ft_putchar_fd(array[i][j], out);
			j++;
		}
		if (array[i][j] == '=')
			ft_export_print_with_content(array, i, j, out);
		ft_putchar_fd('\n', out);
		free(array[i]);
		i++;
	}
	free(array);
}

void	ft_export(char **args, t_data *data, int out)
{
	set_exit_status(0);
	if (args[1] == NULL && data->env)
		ft_export_print(data, out);
	else if (args[1] != NULL)
		ft_export_creating_env(args, data);
	clear_str_array(args);
}
